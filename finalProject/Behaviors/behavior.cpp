/*
 * behavior.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */
#include "behavior.h"

#define MIN_ANGLE -45
#define MAX_ANGLE 45
#define MAX_DIST_TO_OBSTACLE 0.5
#define OBSTACLE_FINDER_DIRECTION_INDICATOR -1

Behavior::Behavior(Robot* robot)
{
	_robot = robot;
	nSideIndexShouldTernNow = 0;
}

Behavior* Behavior::addNext(Behavior *behave)
{
    _nextBehaviors.push_back(behave);
    return this;
}

Behavior* Behavior::selectNext() {
    return _nextBehaviors[nSideIndexShouldTernNow];
}

bool Behavior::stopCond(){
	return true;
}

bool Behavior::startCond() {
	return true;
}

bool Behavior::checkObstacleInFront(int nCheckDirectionIndicator){
	int minIndex = DegreesToIndex(MIN_ANGLE);
	int maxIndex = DegreesToIndex(MAX_ANGLE);
	int nIndexesInterval = (maxIndex - minIndex) / 2;
	int nCenterIndex = minIndex + nIndexesInterval;
	float laserReadRight, laserReadLeft;

	for (int i = 0; i < nIndexesInterval; i++) {
		laserReadRight = _robot->getLaserScan(nCenterIndex + (i * (0 - OBSTACLE_FINDER_DIRECTION_INDICATOR)));
		laserReadLeft = _robot->getLaserScan(nCenterIndex + (i * (0 + OBSTACLE_FINDER_DIRECTION_INDICATOR)));

		if ((nCheckDirectionIndicator != -1) &&
			(laserReadRight < MAX_DIST_TO_OBSTACLE)) {
			nSideIndexShouldTernNow = 0;
			return (true);
		}

		if ((nCheckDirectionIndicator != 1) &&
			(laserReadLeft < MAX_DIST_TO_OBSTACLE)) {
			nSideIndexShouldTernNow = 1;
			return (true);
		}

		if ((nCheckDirectionIndicator != -1) &&
			(laserReadRight >= MAX_DIST_TO_OBSTACLE)) {
			return (false);
		}

		if ((nCheckDirectionIndicator != 1) &&
			(laserReadLeft >= MAX_DIST_TO_OBSTACLE)){
			return (false);
		}
	}

	return (false);
}
