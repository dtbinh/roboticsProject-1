/*
 * PathFinder.h
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include <list>
#include <vector>
#include <cstddef>
#include "Point.h"
#include "../Utils/Position.h"
#include "../Utils/Location.h"
#include "../Map/Matrix.h"

using namespace std;

class PathFinder {
public:
	PathFinder();
	PathFinder(Matrix<Utils::CELL_STATUS>* map);
	virtual ~PathFinder();
	vector<Position*> aStar(float x1, float y1, float x2, float y2);
	Matrix<Point*>* _robotsGrid;
	Matrix<Utils::CELL_STATUS>* _map;
	Point* getPoint(int x, int y);
};

#endif /* PATHFINDER_H_ */
