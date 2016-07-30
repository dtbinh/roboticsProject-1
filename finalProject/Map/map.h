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
#include "../Utils/structs.h"
#include <iostream>
using namespace std;

class Map{
private:
public:
	Map(const char* map_path,
			double mapResolution,
			double gridResolution);
	vector<unsigned char> image; // Raw pixels
	vector<unsigned char> imageAfterBlow;
	enum CELL {FREE, OCCUPIED};
	std::vector< std::vector<CELL> > 	vMapMatrix;
	unsigned int width, height;
	double mapResolution;
	double gridResolution;
	void MapBlowing(double robotHeight, double robotWidth);
	void WeightCell(int nRow, int nCol, double resolution);
	void CreateMatrix();
	double GetGridMapResolution();
	int ArrPosToMatrixPos(int nRow, int nCol);
	int CheckCellInPng(int nRow, int nCol);
	point calcPointInMap(point p);
	bool IsCellFree(point p);
};

#endif /* MAP_H_ */
