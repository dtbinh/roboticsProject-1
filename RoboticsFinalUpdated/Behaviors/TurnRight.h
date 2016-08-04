/*
 * TurnRight.h
 *
*  Created on: Aug 1, 2016
 *      Author: user
 */
#include "BehaviorBase.h"

class TurnRight: public Behavior {
public:
	WaypointsManager* _waypointMgr;
	TurnRight(Robot* robot, WaypointsManager* wpManager) : Behavior(robot), _waypointMgr(wpManager) {}
	virtual ~TurnRight();
	void action();
	bool startCond();
	bool stopCond();
	double getPriority();
};
