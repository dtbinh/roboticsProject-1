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
#include <cmath>
#include "../Utils/position.h"

class WaypointsManager{
private:
	point pEnd,pStart;
	Map *map;
public:
	WaypointsManager(point &pStart, point &pEnd, Map *map);
	float getGradientBtwNodes(Node* node1, Node* node2);
	std::list<Node*> CreateAPath();
	void printPathToPng(string picName, std::list<Node*> lstPath);
	std::list<Node*> lstAPath;
	std::list<Node*> lstWayPointPath;
	void RemoveUnnecessaryWayPoints(unsigned dwResolution, float fLinearAccuracy);
};

#endif /* WAYPOINTS_MANAGER_H_ */
