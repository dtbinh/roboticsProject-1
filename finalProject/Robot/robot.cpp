/*
 * robot.cpp
 *
 *  Created on: May 27, 2016
 *      Author: user
 */

#include "robot.h"

#define WAYPOINT_IN_RANGE_DISTANCE 0.1
Robot* Robot::pRobot = NULL;

Robot::Robot()
{
	char* ip = "localhost";
	int port = 6665;
	bool bMotor = true;
	_PlayerClient = new PlayerClient(ip, port);
	_PositionProxy = new Position2dProxy(_PlayerClient);
	_laserProxy = new LaserProxy(_PlayerClient);
	_PositionProxy->SetMotorEnable(bMotor);
	_PlayerClient->Read();
	_PositionProxy->SetOdometry(startPoseX,startPoseY,startPoseYaw);
}

void Robot::setOdometry(){
	_PositionProxy->SetOdometry(0,0,startYaw);
}

//void Robot::setOdometry(int x, int y, double yaw){
//	int newX = PixelToMeter(x - startPoseX);
//	int newY = PixelToMeter(y - startPoseY);
//	double radianYaw = DegreeToRadian(yaw);
//	_PositionProxy->SetOdometry(newX, newY,radianYaw);
//}

void Robot::update(){
	this->Read();
	this->setOdometry();
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
	delete _laserProxy;
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

float Robot::getLaserScan(int index) {
	return _laserProxy->GetRange(index);
}



bool Robot::isInWaypointRange(Node* nWaypoint, double girdResolution)
{
	return ((abs((this->getX() / girdResolution) - nWaypoint->x) < WAYPOINT_IN_RANGE_DISTANCE) &&
			(abs((this->getY() / girdResolution) - nWaypoint->y) < WAYPOINT_IN_RANGE_DISTANCE));
}

void Robot::Read()
{
	_PlayerClient->Read();
}
