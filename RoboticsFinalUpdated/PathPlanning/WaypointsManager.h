/*
 * WaypointsManager.h
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef WAYPOINTSMANAGER_H_
#define WAYPOINTSMANAGER_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include "Point.h"
#include "../Utils/Position.h"
#include "../Utils/Utils.h"
#include "../Map/Map.h"

class WaypointsManager {
private:
	std::vector <Position*> _waypointVector;
	int _wpIndex;
	void fillWayPointsVectorByPath(std::vector <Position*> path);
	void optimizePath();
public:
	Position* currWP;

	WaypointsManager();
	WaypointsManager(std::vector <Position*> path);
	std::vector <Position*>  getWayPoints() const {return _waypointVector; };
	Position* getCurrWayPoint();
	Position* getNextWayPoint();
	bool isLastWayPoint();
	bool isInWayPoint(double x,double y);
	bool isClearPath(int x1, int y1, int x2, int y2);
	virtual ~WaypointsManager();
};

#endif /* WAYPOINTSMANAGER_H_ */

