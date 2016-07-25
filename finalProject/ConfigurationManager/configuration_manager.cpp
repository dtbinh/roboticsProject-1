/*
 * configuration_manager.cpp
 *
 *  Created on: May 27, 2016
 *      Author: user
 */
#include "configuration_manager.h"

ConfigurationManager::ConfigurationManager(char *file_path)
{
	this->startLocation = new Location();
	this->goal = new point();
	this->robotSize = new point();
	setParameters(file_path);
}

void ConfigurationManager::setParameters(char *file_path){
	string line, temp_substring;
	ifstream parameters_file;
	parameters_file.open(file_path);

	if (parameters_file.is_open()) {
		getline(parameters_file, line);

		// Get mapPath parameters.
		string temp_map = line.substr(line.find(": ")+2);
		this->mapPath= temp_map.substr(0,temp_map.length()-1).c_str();


		// Get startLocation parameters
		getline(parameters_file, line);
		line = line.substr(line.find(" ")+1);
		this->startLocation->X = atoi((line.substr(0,line.find(" ")+1)).c_str());
		line = line.substr(line.find(" ")+1);
		this->startLocation->Y = atoi(line.substr(0,line.find(" ")+1).c_str());
		line = line.substr(line.find(" ")+1);
		this->startLocation->Yaw = atoi(line.c_str());

		// Get goal parameter.
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		this->goal->X = atoi(line.substr(0,line.find(" ")+1).c_str());
		line = line.substr(line.find(" ")+1);
		this->goal->Y = atoi(line.c_str());

		// Get robotSize parameter.
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		this->robotSize->X = atoi(line.substr(0,line.find(" ")+1).c_str());
		line = line.substr(line.find(" ")+1);
		this->robotSize->Y = atoi(line.c_str());

		// Get mapResolutionCM
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		this->mapResolutionCM = atof(line.c_str());

		// Get gridResolutionCM
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		this->gridResolutionCM = atof(line.c_str());

		parameters_file.close();
	}
}

