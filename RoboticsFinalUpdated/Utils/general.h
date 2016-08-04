/*
 * general.h
 *
 *  Created on: Aug 4, 2016
 *      Author: user
 */

#ifndef GENERAL_H_
#define GENERAL_H_

#include "../PathPlanning/AvoidObstaclesPlan.h"
#include "../Managers/LocalizationManager.h"
#include <iostream>
#include "../Robot/Robot.h"
#include "../PathPlanning/PathPlanner.h"
#include "../Behaviors/BehaviorBase.h"
#include "../Managers/LocalizationManager.h"
#include "../PathPlanning/AvoidObstaclesPlan.h"
#include "../Utils/general.h"

void runRobot(Robot* r, AvoidObstaclesPlan* avoidObstaclesPlan);

#endif /* GENERAL_H_ */
