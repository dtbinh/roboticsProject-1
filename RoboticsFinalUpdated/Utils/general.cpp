/*
 * general.cpp
 *
 *  Created on: Aug 4, 2016
 *      Author: user
 */

#include "general.h"

void runRobot(Robot* r, AvoidObstaclesPlan* avoidObstaclesPlan){
	Behavior* _curr = avoidObstaclesPlan->startBehavior();
	LocalizationManager _localizationManager;
	for (int i = 0; i < 15; i++) {
		r->setOdometry();
		r->Read();
		}

	r->Read();
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
				r->Read();
				r->Read();

				// Get the robot's new location
				newX = r->getXPos();
				newY = r->getYPos();
				newYaw = r->getYaw();

				double deltaX = newX - prevX;
				double deltaY = newY - prevY;
				double deltaYaw = newYaw - prevYaw;
				if (deltaX == 0 &&  deltaY == 0 && deltaYaw == 0)
					continue;

				// Update particles
				_localizationManager.updateParticles(r, deltaX, deltaY, deltaYaw);
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

			r->setSpeed(0.0,0.0);
			_curr = _curr->selectNextBehavior();
			r->Read();
		}
}
