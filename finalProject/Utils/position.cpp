/*
 * position.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#include "position.h"


float CalcGradient(Location& from, Location& to){
	float dY = (signed)(to.Y - from.Y);
	float dX = (signed)(to.X - from.X);

	if (to.X == from.X)
		return FLT_MAX;
	else
		return fabs(dY/dX);
}
