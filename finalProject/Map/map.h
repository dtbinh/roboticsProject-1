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
	vector<unsigned char> imageAfterBlow;
	enum CELL 							{FREE, OCCUPIED};
	std::vector< std::vector<CELL> > 	vMapMatrix;
	unsigned int width, height;
	double resolution;
	void MapBlowing(double robotHeight, double robotWidth);
	void WeightCell(int nRow, int nCol, double resolution);
};

#endif /* MAP_H_ */
