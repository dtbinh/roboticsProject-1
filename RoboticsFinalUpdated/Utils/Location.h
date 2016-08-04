/*
 * Location.h
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef LOCATION_H_
#define LOCATION_H_

class Location {
public:
	int x;
	int y;
	int yaw;

	Location(int x, int y, int yaw);
	Location(Location& location);
	virtual ~Location();
};

#endif /* LOCATION_H_ */
