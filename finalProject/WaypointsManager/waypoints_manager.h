/*
 * waypoints_manager.h
 *
 *  Created on: May 27, 2016
 *      Author: user
 */

#ifndef WAYPOINTS_MANAGER_H_
#define WAYPOINTS_MANAGER_H_
#include "../Map/map.h"
#include "node.h"
#include <list>
#include <map>


class WaypointsManager{
private:
public:
	WaypointsManager(point &pStart, point &pEnd, Map *map);
	std::list<Node*> CreateAPath(point pStart,
							    point pEnd,
							    Map *map);
	std::list<Node*> lstAPath;
};

#endif /* WAYPOINTS_MANAGER_H_ */
