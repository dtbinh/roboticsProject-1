/*
 * Converter.cpp
 *
 *  Created on: Jul 25, 2016
 *      Author: user
 */

#include "Converter.h"

double DegreeToRadian(double degree) {
	return ((degree)*(PI/180.0));
}

double RadianToDegree(double radian){
	return ((radian) * (180.0/PI));
}
