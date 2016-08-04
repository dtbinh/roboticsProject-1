/*
 * TurnLeft.h
 *
*  Created on: Aug 1, 2016
 *      Author: user
 */
#include "BehaviorBase.h"

class TurnLeft: public Behavior {
public:
	WaypointsManager* _waypointMgr;
	TurnLeft(Robot* robot, WaypointsManager* wpManager) : Behavior(robot), _waypointMgr(wpManager) {}
	virtual ~TurnLeft();
	void action();
	bool startCond();
	bool stopCond();
	double getPriority();
};
