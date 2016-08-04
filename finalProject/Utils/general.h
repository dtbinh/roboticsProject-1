/*
 * general.h
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef GENERAL_H_
#define GENERAL_H_
#include "../Behaviors/move_to_way_point.h"
#include "../Behaviors/turn_left.h"
#include "../Behaviors/turn_right.h"
#include "../Behaviors/move_forward.h"
#include "../Behaviors/behavior.h"
#include "../Robot/robot.h"
#include "../Utils/structs.h"
#include "../Map/map.h"

Behavior** createBehaviors(Robot* robot);
void run_robot(Robot* robot, list<Node*> path, Behavior** behaviors,
				Map* mMap, point pStart, point pEnd);
void PrintToConsole(int nStartX,int nStartY,
		int nWantedLocationX,int nWantedLocationY,
		Map* mMap, list<Node*> path, Robot *robot);
#endif /* GENERAL_H_ */
