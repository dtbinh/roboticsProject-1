/*
 * GoForward.h
 *
*  Created on: Aug 1, 2016
 *      Author: user
 */
#include "BehaviorBase.h"

class GoForward : public Behavior {
public:
	WaypointsManager* _waypointMgr;
	GoForward(Robot* robot, WaypointsManager* wpManager) : Behavior(robot), _waypointMgr(wpManager) {}
	virtual ~GoForward();
	void action();
	bool startCond();
	bool stopCond();
	double getPriority();
};
