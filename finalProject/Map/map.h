/*
 * map.h
 *
 *  Created on: May 27, 2016
 *      Author: user
 */

#ifndef MAP_H_
#define MAP_H_
#include <string>
#include "../Utils/lodepng.h"
#include <iostream>
using namespace std;

class Map{
private:
public:
	Map(const char* map_path,
			double mapResolution);
	vector<unsigned char> image; // Raw pixels
	unsigned width, height;
	double resolution;
	void MapResizing(double robotHeight, double robotWidth);
};

#endif /* MAP_H_ */
