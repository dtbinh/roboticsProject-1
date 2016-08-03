/*
 * Main.cpp
 * Created by: Or Lavi
 * Date: 09.05.16
 * Course: Robotics
 */
#include <libplayerc++/playerc++.h>
#include "ConfigurationManager/configuration_manager.h"
#include "WaypointsManager/waypoints_manager.h"
#include "Robot/robot.h"
#include "Map/map.h"
#include "Utils/structs.h"
#include "Behaviors/behavior.h"
#include "Utils/general.h"
#include "Behaviors/move_to_way_point.h"
#include "Behaviors/turn_left.h"
#include "Behaviors/turn_right.h"
#include "Behaviors/move_forward.h"
#include "Behaviors/behavior.h"
#include "Robot/robot.h"
#include "Map/map.h"


using namespace PlayerCc;
using namespace std;


#define LASER_SAMPLES 666
#define MIN_ANGLE_FOR_AVOIDANCE -45
#define MAX_ANGLE_FOR_AVOIDANCE 45
#define MAX_DIST_TO_OBSTACLE 0.6
#define MAX_DIST_OF_LASER_SENSOR 4
#define DEFAULT_WAYPOINT_RESOLUTION 13
#define DEFAULT_WAYPOINT_ACCURACY (0.1)

char *PARAMETER_FILE_PATH = "/home/user/Desktop/parameters.txt";

int main(int argc, char** argv)
{
	ConfigurationManager* cmManager = new ConfigurationManager(PARAMETER_FILE_PATH);

	Map* mMap = new Map(cmManager->mapPath,
						cmManager->mapResolutionCM,
						cmManager->gridResolutionCM);

	mMap->MapBlowing(cmManager->robotSize->X,
			cmManager->robotSize->Y);
	mMap->CreateMatrix();

	point pTarget = mMap->calcPointInMap(*cmManager->goal);
	point tempPoint = {cmManager->startLocation->X,
						cmManager->startLocation->Y};
	point pStart = mMap->calcPointInMap(tempPoint);

	WaypointsManager* wayManager = new WaypointsManager(pStart,pTarget,mMap);
	// TODO: Make the way straight line.
	wayManager->printPathToPng("APath.png",wayManager->lstAPath);
	wayManager->RemoveUnnecessaryWayPoints(DEFAULT_WAYPOINT_RESOLUTION,
										   DEFAULT_WAYPOINT_ACCURACY);
	wayManager->printPathToPng("WayPoints.png",wayManager->lstWayPointPath);
	Robot* robot = Robot::getRobot();

    // Creating behaviors
	Behavior** behaviors = createBehaviors(robot);

	robot->update();

	run_robot(robot, wayManager->lstAPath,
			  behaviors, mMap,
			  pStart, pTarget);



}





