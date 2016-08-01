/*
 * move_to_way_point.h
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef MOVE_TO_WAY_POINT_H_
#define MOVE_TO_WAY_POINT_H_
#include "behavior.h"

#include "../WaypointsManager/node.h"

class MoveToWaypoint : public Behavior {
public:
	Node* pNextWaypoint;
	void setNextWaypoint(Node* pPoint);
	MoveToWaypoint(Robot *robot);
	virtual bool startCond();
	virtual bool stopCond();
	virtual void action();
	virtual ~MoveToWaypoint();
};

#endif /* MOVE_TO_WAY_POINT_H_ */
