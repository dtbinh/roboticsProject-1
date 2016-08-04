/*
 * Location.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#include "Location.h"

Location::Location(int x, int y, int yaw){
	this->x = x;
	this->y = y;
	this->yaw = yaw;
}

Location::Location(Location& location){
	this->x = location.x;
	this->y = location.y;
	this->yaw = location.yaw;
}

Location::~Location() {
	// TODO Auto-generated destructor stub
}

