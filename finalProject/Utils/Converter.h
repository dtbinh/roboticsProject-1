/*
 * Converter.h
 *
 *  Created on: Jul 25, 2016
 *      Author: user
 */

#ifndef CONVERTER_H_
#define CONVERTER_H_

#define DEGREES_INDEX_RATIO (666 / 270)
#define MIDDLE_INDEX (666 / 2)
#define UNSAFE_DIST (0.6)
#define PI 3.1415926536

double RadianToDegree(double radian);
double DegreeToRadian(double degree);
int DegreesToIndex(int degrees);

#endif /* CONVERTER_H_ */
