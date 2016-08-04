/*
 * move_forward.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#include "move_forward.h"
#define FORWARD_SPEED 0.5

MoveForward::MoveForward(Robot *robot) : Behavior(robot)
{
	strBehaviorName = "MoveForward";
}

bool MoveForward::startCond()
{
	return !checkObstacleInFront(0);
}

bool MoveForward::stopCond()
{
	return checkObstacleInFront(0);
}

void MoveForward::action()
{
	_robot->setSpeed(FORWARD_SPEED, 0);
}
