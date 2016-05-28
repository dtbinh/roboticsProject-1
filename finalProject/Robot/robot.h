/*
 * robot.h
 *
 *  Created on: May 27, 2016
 *      Author: user
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <libplayerc++/playerc++.h>
//#include "../Utils/Utils.h"
#include <vector>


using namespace std;
using namespace PlayerCc;

class Robot {

	PlayerClient* _PlayerClient;
	Position2dProxy* _PositionProxy;
	LaserProxy* _LaserProxy;
	double X;
	double Y;
	double Yaw;
	double startYaw;

public:
	double startPoseX;
	double startPoseY;
	double startPoseYaw;
	double goalPoseX;
	double goalPoseY;
	double robotWidth;
	double robotHeight;
	void Init(char* ip, int port, bool bMotor);
	double getX();
	double getY();
	double getYaw();
	void setSpeed(double speed, double angularSpeed);
	void Read();
	//void setDirection(double Yaw);


};

#endif /* ROBOT_H_ */
