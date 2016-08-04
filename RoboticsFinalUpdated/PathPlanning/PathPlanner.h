/*
 * PathPlanner.h
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef PATHPLANNER_H_
#define PATHPLANNER_H_

#include "../Map/Map.h"
#include "../Utils/Utils.h"
#include "PathFinder.h"
#include "WaypointsManager.h"

class PathPlanner {
private:
	Map* _map;
	vector<Position*> _astarPath;
	WaypointsManager* _waypointsMgr;
public:
	PathPlanner();
	virtual ~PathPlanner();

	WaypointsManager* getWaypointsMgr() const{ return _waypointsMgr; };
	Map* getMap() const{ return _map; };
	void printAstarToPng();
};

#endif /* PATHPLANNER_H_ */
