/*
 * turn_left.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#include "turn_left.h"
#define LEFT_SPEED -0.1

TurnLeft::TurnLeft(Robot* robot) : Behavior(robot)
{
	strBehaviorName = "TurnLeft";
}

TurnLeft::~TurnLeft() {}

void TurnLeft::action()
{
	while (this->startCond())
	{
		_robot->setSpeed(0.0, LEFT_SPEED);
		_robot->Read();
	}
}

bool TurnLeft::startCond()
{
	return (checkObstacleInFront(-1));
}
bool TurnLeft::stopCond()
{
	return (!checkObstacleInFront(-1));
}
