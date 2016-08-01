/*
 * turn_left.h
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef TURN_LEFT_H_
#define TURN_LEFT_H_

#include "behavior.h"

class TurnLeft : public Behavior{
public:
	TurnLeft(Robot* robot);
	bool startCond();
	bool stopCond();
	void action();
	virtual ~TurnLeft();
};

#endif /* TURN_LEFT_H_ */
