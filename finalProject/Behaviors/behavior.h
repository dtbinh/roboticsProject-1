/*
 * behavior.h
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_
#include "../Robot/robot.h"
#include "../Utils/Converter.h"

using namespace std;

class Behavior {
private:
    vector<Behavior *> _nextBehaviors;

protected:
    Robot* _robot;

public:
    Behavior(Robot* robot);
    virtual bool startCond() = 0;
    virtual bool stopCond() = 0;
    virtual void action() = 0;

    Behavior *addNext(Behavior *beh);
    Behavior *selectNext();

	bool checkObstacleInFront(int nCheckDirectionIndicator);
	int nSideIndexShouldTernNow;
	string strBehaviorName;
};


#endif /* BEHAVIOR_H_ */
