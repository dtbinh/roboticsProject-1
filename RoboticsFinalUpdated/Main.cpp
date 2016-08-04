/*
 * Main.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#include <iostream>
#include "Robot/Robot.h"
#include "PathPlanning/PathPlanner.h"
#include "Behaviors/BehaviorBase.h"
#include "Managers/LocalizationManager.h"
#include "PathPlanning/AvoidObstaclesPlan.h"
#include "Utils/general.h"

using namespace std;

int main(){

	//Robot robot("10.10.245.63", 6665);
	Robot robot("127.0.0.1", 6665);
	PathPlanner* pathPlanner = new PathPlanner();
	AvoidObstaclesPlan* avoidObstaclesPlan = new AvoidObstaclesPlan(&robot, pathPlanner->getWaypointsMgr());
	vector<Position*> points = pathPlanner->getWaypointsMgr()->getWayPoints();

	runRobot(&robot, avoidObstaclesPlan);


	//Bonus
	pathPlanner->printAstarToPng();

	cout << "finished running";

	return 0;
}

