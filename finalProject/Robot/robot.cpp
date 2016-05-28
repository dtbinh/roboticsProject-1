/*
 * robot.cpp
 *
 *  Created on: May 27, 2016
 *      Author: user
 */

#include "robot.h"

void Robot::Init(char* ip, int port, bool bMotor)
{
	_PlayerClient = new PlayerClient(ip, port);
	_PositionProxy = new Position2dProxy(_PlayerClient);
	_LaserProxy = new LaserProxy(_PlayerClient);
	_PositionProxy->SetMotorEnable(bMotor);
	_PlayerClient->Read();
	_PositionProxy->SetOdometry(startPoseX,startPoseY,startPoseYaw);
}

double Robot::getX()
{
	return X;
}

double Robot::getY()
{
	return Y;
}

double Robot::getYaw()
{
	return Yaw;
}

void Robot::setSpeed(double speed, double angularSpeed)
{
	_PositionProxy->SetSpeed(speed,angularSpeed);
}

/*void Robot::setDirection(double Yaw)
{
	_PositionProxy->get
}*/

void Robot::Read()
{
	_PlayerClient->Read();
}
