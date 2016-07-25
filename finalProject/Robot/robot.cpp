/*
 * robot.cpp
 *
 *  Created on: May 27, 2016
 *      Author: user
 */

#include "robot.h"
Robot* Robot::pRobot = NULL;

Robot::Robot()
{
	char* ip = "localhost";
	int port = 6665;
	bool bMotor = true;
	_PlayerClient = new PlayerClient(ip, port);
	_PositionProxy = new Position2dProxy(_PlayerClient);
	_LaserProxy = new LaserProxy(_PlayerClient);
	_PositionProxy->SetMotorEnable(bMotor);
	_PlayerClient->Read();
	_PositionProxy->SetOdometry(startPoseX,startPoseY,startPoseYaw);
}

Robot* Robot::getRobot()
{
	if(!pRobot)
		pRobot = new Robot;
	return pRobot;
}

Robot::~Robot()
{
	delete _PlayerClient;
	delete _PositionProxy;
	delete _LaserProxy;
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
	double degree = RadianToDegree(_PositionProxy->GetYaw());
	if (degree < 0) {
		degree = 360 + degree;
	}
	return degree;
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
