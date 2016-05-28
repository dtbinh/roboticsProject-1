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
	Map(string& map_path);
	vector<unsigned char> image; // Raw pixels
	unsigned width, height;
};

#endif /* MAP_H_ */
