/*
 * turn_right.h
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef TURN_RIGHT_H_
#define TURN_RIGHT_H_
#include "behavior.h"

class TurnRight : public Behavior {
public:
	TurnRight(Robot* robot);
	bool startCond();
	bool stopCond();
	void action();
	virtual ~TurnRight();
};

#endif /* TURN_RIGHT_H_ */
