/*
 * robot.h
 *
 *  Created on: May 27, 2016
 *      Author: user
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <libplayerc++/playerc++.h>
#include "../Utils/Converter.h"
#include <vector>
#include "../WaypointsManager/node.h"

using namespace std;
//using namespace PlayerCc;

class Robot {

private:
	PlayerCc::PlayerClient* _PlayerClient;
	PlayerCc::Position2dProxy* _PositionProxy;
	PlayerCc::LaserProxy* _laserProxy;
	double X;
	double Y;
	double Yaw;
	double startYaw;
	Robot(const Robot &);
	Robot();
	static Robot* pRobot;

public:
	double startPoseX;
	double startPoseY;
	double startPoseYaw;
	double goalPoseX;
	double goalPoseY;
	double robotWidth;
	double robotHeight;
	~Robot();
	void setOdometry();
	void setOdometry(int x, int y, double yaw);
	void update();
	static Robot* getRobot();
	double getX();
	double getY();
	double getYaw();
	void setSpeed(double speed, double angularSpeed);
	void Read();
	float getLaserScan(int index);
	bool isInWaypointRange(Node* nWaypoint, double girdResolution);
};

#endif /* ROBOT_H_ */
