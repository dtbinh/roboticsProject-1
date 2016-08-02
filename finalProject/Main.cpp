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

//    // Creating behaviors
//	Behavior** behaviors = createBehaviors(robot);
//
//	robot->update();
//
//	run_robot(robot, wayManager->lstAPath,
//			  behaviors, mMap,
//			  pStart, pTarget);

    	// Creating behaviors
	    Behavior** behaviors = new Behavior*[4];
	    behaviors[0] = new MoveToWaypoint(robot);
	    behaviors[1] = new MoveForward(robot);
	    behaviors[2] = new TurnRight(robot);
	    behaviors[3] = new TurnLeft(robot);

	    // Connecting behaviors
	    behaviors[0]->addNext(behaviors[2]);
	    behaviors[0]->addNext(behaviors[3]);
	    behaviors[1]->addNext(behaviors[2]);
	    behaviors[1]->addNext(behaviors[3]);
	    behaviors[2]->addNext(behaviors[0]);
	    behaviors[3]->addNext(behaviors[0]);

	    Behavior *currBehavior = behaviors[0];

		robot->update();

	    for (std::list<Node*>::iterator iCurrWaypoint = wayManager->lstWayPointPath.begin();
			 iCurrWaypoint != wayManager->lstWayPointPath.end();
			 iCurrWaypoint++)
	    {
	    	// PrintToConsole(nStartX,nStartY,nWantedLocationX,nWantedLocationY);
	    	((MoveToWaypoint*)behaviors[0])->setNextWaypoint(*iCurrWaypoint);

	    	robot->update();

	    	// while waypoint is not in range
//	    	while (!robot->isInWaypointRange(*iCurrWaypoint,mMap->GetGridMapResolution()))
//	    	{
	    		// If curr behavior can be activated
	    		if (currBehavior->startCond())
	    		{
	    			currBehavior->action();
	    		}
	    		else
	    		{
	    			currBehavior = currBehavior->selectNext();
	    			cout << "   ...change behavior to " << currBehavior->strBehaviorName;
	    		}

	        	robot->update();
	    	}
//	    }

}





