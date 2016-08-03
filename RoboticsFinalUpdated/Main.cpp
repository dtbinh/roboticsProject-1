/*
 * Main.cpp
 *
 *  Created on: Jun 23, 2015
 *      Author: colman
 */

#include <iostream>
#include "Robot.h"
#include "PathPlanning/PathPlanner.h"
#include "Behaviors/BehaviorBase.h"
#include "LocalizationManager.h"
#include "AvoidObstaclesPlan.h"


using namespace std;
void runRobot(Robot* robot, AvoidObstaclesPlan* avoidObstaclesPlan){
	Behavior* _curr = avoidObstaclesPlan->startBehavior();
	LocalizationManager _localizationManager;
	for (int i = 0; i < 15; i++) {
		robot->setOdometry();
		robot->Read();
		}

	robot->Read();
		if (!_curr->startCond()){
			_curr->selectNextBehavior();
		}

		double prevX = Utils::configurationManager->xStartLocation,
			   prevY = Utils::configurationManager->yStartLocation,
			   prevYaw = Utils::configurationManager->yawStartLocation;
		double newX, newY, newYaw;

		while (_curr != NULL) {
			while (!_curr->stopCond()) {
				_curr->action();
				robot->Read();
				robot->Read();

				// Get the robot's new location
				newX = robot->getXPos();
				newY = robot->getYPos();
				newYaw = robot->getYaw();

				double deltaX = newX - prevX;
				double deltaY = newY - prevY;
				double deltaYaw = newYaw - prevYaw;
				if (deltaX == 0 &&  deltaY == 0 && deltaYaw == 0)
					continue;

				// Update particles
				_localizationManager.updateParticles(robot, deltaX, deltaY, deltaYaw);
				Particle* best = _localizationManager.getBestParticle();
				_localizationManager.createParticles();

				prevX = best->location->x;
				prevX = best->location->y;
				prevX = best->location->yaw;

				cout << "Robot's position: " << newX << ", " << newY << endl;

				prevX = newX;
				prevY = newY;
				prevYaw = newYaw;
			}

			robot->setSpeed(0.0,0.0);
			_curr = _curr->selectNextBehavior();
			robot->Read();
		}
}
int main(){

	Robot robot("10.10.245.63", 6665);
	PathPlanner* pathPlanner = new PathPlanner();
	AvoidObstaclesPlan* avoidObstaclesPlan = new AvoidObstaclesPlan(&robot, pathPlanner->getWaypointsMgr());
	vector<Position*> points = pathPlanner->getWaypointsMgr()->getWayPoints();
	runRobot(&robot, avoidObstaclesPlan);

	//Bonus
	pathPlanner->printAstarToPng();

	cout << "finished running";

	return 0;
}

