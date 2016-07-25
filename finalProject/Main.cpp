/*
 * Main.cpp
 * Created by: Or Lavi
 * Date: 09.05.16
 * Course: Robotics
 */
#include <libplayerc++/playerc++.h>
#include "ConfigurationManager/configuration_manager.h"
#include "Robot/robot.h"
#include "Map/map.h"
using namespace PlayerCc;
using namespace std;


#define LASER_SAMPLES 666
#define MIN_ANGLE_FOR_AVOIDANCE -45
#define MAX_ANGLE_FOR_AVOIDANCE 45
#define MAX_DIST_TO_OBSTACLE 0.6
#define MAX_DIST_OF_LASER_SENSOR 4

char *PARAMETER_FILE_PATH = "/home/user/Desktop/parameters.txt";

int main(int argc, char** argv)
{
	ConfigurationManager* cmManager = new ConfigurationManager(PARAMETER_FILE_PATH);

	Map* mMap = new Map(cmManager->mapPath,
						cmManager->mapResolutionCM);

	mMap->MapResizing(cmManager->robotSize->X,
			cmManager->robotSize->Y);

	Robot* robot = Robot::getRobot();

	robot->setSpeed(1,0);
	while(true)
	{
		robot->Read();
		//robot->setSpeed(1,0);
	}

}





