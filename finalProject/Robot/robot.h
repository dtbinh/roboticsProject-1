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


using namespace std;
using namespace PlayerCc;

class Robot {

private:
	PlayerClient* _PlayerClient;
	Position2dProxy* _PositionProxy;
	LaserProxy* _laserProxy;
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
//	static Robot* getRobot(char* ip, int port, bool bMotor);
	static Robot* getRobot();
	double getX();
	double getY();
	double getYaw();
	void setSpeed(double speed, double angularSpeed);
	void Read();
	float getLaserScan(int index);
	//void setDirection(double Yaw);


};

#endif /* ROBOT_H_ */
