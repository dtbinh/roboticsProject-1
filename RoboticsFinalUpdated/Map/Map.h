/*
 * Map.h
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef MAP_H_
#define MAP_H_

#include "lodepng.h"
#include "Matrix.h"
#include "../Utils/Utils.h"
#include "../PathPlanning/Point.h"
#include "../Managers/ConfigurationManager.h"
#include <cmath>

class Map {
private:
	Matrix<Utils::CELL_STATUS>* _originalMap;
	Matrix<Utils::CELL_STATUS>* _blownMap;

	int _height, _width;
	static Map* _instance;
	Map();
public:
	static Map* getInstance();
	virtual ~Map();

	void loadPng(char* mapPath);
	void saveMapToPng(Matrix<Utils::CELL_STATUS>* map, char* path);
	void saveImageToPng(char* path, std::vector<unsigned char> image);
	void blowMap();
	void printOriginalMap() const{
		_originalMap->print();
	}
	Matrix<Utils::CELL_STATUS>* getOriginalMap() const{
		return _originalMap;
	}
	Matrix<Utils::CELL_STATUS>* getBlownMap() const{
		return _blownMap;
	}
};

#endif /* MAP_H_ */
