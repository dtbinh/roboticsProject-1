/*
 * turn_right.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#include "turn_right.h"
#define RIGHT_SPEED 0.1

TurnRight::TurnRight(Robot* robot) : Behavior(robot)
{
	strBehaviorName = "TurnRight";
}

TurnRight::~TurnRight() {
}

void TurnRight::action()
{
	while (this->startCond())
	{
		_robot->setSpeed(0.0, RIGHT_SPEED);
		_robot->Read();
	}
}

bool TurnRight::startCond()
{
	return (checkObstacleInFront(1));
}
bool TurnRight::stopCond()
{
	return (!checkObstacleInFront(1));
}
