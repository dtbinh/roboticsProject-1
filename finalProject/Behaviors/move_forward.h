/*
 * move_forward.h
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef MOVE_FORWARD_H_
#define MOVE_FORWARD_H_

#include "behavior.h"

class MoveForward : public Behavior {
public:
	MoveForward(Robot *robot);
	virtual bool startCond();
	virtual bool stopCond();
	virtual void action();
};


#endif /* MOVE_FORWARD_H_ */
