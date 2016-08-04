/*
 * ConfigurationManager.cpp
 *
*  Created on: Aug 1, 2016
 *      Author: user
 */

#include "ConfigurationManager.h"
#include <iostream>

ConfigurationManager::ConfigurationManager(const char* file_path) {
	string line, temp_substring;
	ifstream parameters_file;
	parameters_file.open(file_path);
	char file_data[10][100];
	char attribute_name[200];
	ifstream inputFile;
	inputFile.open(file_path, ios::in);
	int counter = 0;
	while (!inputFile.eof()){
		inputFile.getline(attribute_name, 100, ' ');
		inputFile.getline(file_data[counter],100, '\n');
		counter++;
	}

	inputFile.close();
	if (parameters_file.is_open()) {
		getline(parameters_file, line);

		// Get mapPath parameters.
		string mapString = file_data[0];
		if (!mapString.empty() && mapString[mapString.size() - 1] == '\r'){
			mapString.erase(mapString.size() - 1);
		}
		this->mapPath = new char[1024];
		strcpy(this->mapPath, mapString.c_str());

		// Get startLocation parameters
		getline(parameters_file, line);
		line = line.substr(line.find(" ")+1);
		this->xStartLocation = atoi((line.substr(0,line.find(" ")+1)).c_str());
		line = line.substr(line.find(" ")+1);
		this->yStartLocation = atoi(line.substr(0,line.find(" ")+1).c_str());
		line = line.substr(line.find(" ")+1);
		this->yawStartLocation = atoi(line.c_str());

		// Get goal parameter.
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		this->xTarget = atoi(line.substr(0,line.find(" ")+1).c_str());
		line = line.substr(line.find(" ")+1);
		this->yTarget = atoi(line.c_str());

		// Get robotSize parameter.
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		this->robotLength = atoi(line.substr(0,line.find(" ")+1).c_str());
		line = line.substr(line.find(" ")+1);
		this->robotWidth = atoi(line.c_str());

		// Get mapResolutionCM
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		this->mapResolution = atof(line.c_str());

		// Get gridResolutionCM
		getline(parameters_file, line);
		line = line.substr(line.find(": ")+2);
		this->gridResolution = atof(line.c_str());

		parameters_file.close();
	}
}

ConfigurationManager::~ConfigurationManager() {
	delete [] this->mapPath;
}

