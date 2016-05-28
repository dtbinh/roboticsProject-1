/*
 * configuration_manager.h
 *
 *  Created on: May 27, 2016
 *      Author: user
 */

#ifndef CONFIGURATION_MANAGER_H_
#define CONFIGURATION_MANAGER_H_

#include <fstream>
#include "../Utils/structs.h"
#include <string>
using namespace std;

#endif /* CONFIGURATION_MANAGER_H_ */

class ConfigurationManager
{
public:
	Location startLocation;
	string mapPath;
	double mapResolutionCM, gridResolutionCM;
	point goal, robotSize;
	ConfigurationManager(char *file_path);
private:
	void setParameters(char *file_path,string& mapPath, Location *startLocation,double &mapResolutionCM,
			double &gridResolutionCM, point *goal, point *robotSize);
};
