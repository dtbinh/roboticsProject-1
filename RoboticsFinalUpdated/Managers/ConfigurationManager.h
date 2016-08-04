/*
 * ConfigurationManager.h
 *
*  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_

#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class ConfigurationManager {
public:
	ConfigurationManager(const char* configurationFilePath);
	virtual ~ConfigurationManager();


	char* mapPath;
	int xStartLocation;
	int yStartLocation;
	int yawStartLocation;
	int xTarget;
	int yTarget;
	int robotLength;
	int robotWidth;
	double mapResolution;
	double gridResolution;
};



#endif /* CONFIGURATIONMANAGER_H_ */
