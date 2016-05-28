/*
 * configuration_manager.cpp
 *
 *  Created on: May 27, 2016
 *      Author: user
 */
#include "configuration_manager.h"

ConfigurationManager::ConfigurationManager(char *file_path)
{
	setParameters(file_path, mapPath, &startLocation, mapResolutionCM,
				gridResolutionCM, &goal,&robotSize);
}

void ConfigurationManager::setParameters(char *file_path,string& mapPath,
		Location *startLocation,double &mapResolutionCM,
		double &gridResolutionCM, point *goal, point *robotSize){
	string line, temp_substring;
	ifstream parameters_file;
	parameters_file.open(file_path);

	if (parameters_file.is_open()) {
		getline(parameters_file, line);

		// Get mapPath parameters.
		mapPath = line.substr(line.find(": ")+2);

		// Get startLocation parameters
		getline(parameters_file, line);
		line = line.substr(line.find(" ")+1);
		startLocation->X = atoi((line.substr(0,line.find(" ")+1)).c_str());
		line = line.substr(line.find(" ")+1);
		startLocation->Y = atoi(line.substr(0,line.find(" ")+1).c_str());
		line = line.substr(line.find(" ")+1);
		startLocation->Yaw = atoi(line.c_str());

		// Get goal parameter.
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		goal->X = atoi(line.substr(0,line.find(" ")+1).c_str());
		line = line.substr(line.find(" ")+1);
		goal->Y = atoi(line.c_str());

		// Get robotSize parameter.
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		robotSize->X = atoi(line.substr(0,line.find(" ")+1).c_str());
		line = line.substr(line.find(" ")+1);
		robotSize->Y = atoi(line.c_str());

		// Get mapResolutionCM
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		mapResolutionCM = atof(line.c_str());

		// Get gridResolutionCM
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		gridResolutionCM = atof(line.c_str());

		parameters_file.close();
	}
}

