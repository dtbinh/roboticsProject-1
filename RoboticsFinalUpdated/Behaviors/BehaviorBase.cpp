/*
 * BehaviorBase.cpp
 *
*  Created on: Aug 1, 2016
 *      Author: user
 */
#include "BehaviorBase.h"

bool Behavior::addNextBehavior(Behavior* behaviorToAdd)
{
	Behavior** newBehaviorsArr;
	newBehaviorsArr = new Behavior*[_nextBehaviorsCount + 1];
	if (newBehaviorsArr == NULL)
		return false;

	int i;
	// Clone the nextBehaviors array
	for (i = 0; i < _nextBehaviorsCount; i++)
		newBehaviorsArr[i] = _nextBehaviors[i];

	// Add the new behavior to the end of the array
	newBehaviorsArr[i] = behaviorToAdd;

	delete[] _nextBehaviors;
	_nextBehaviors = newBehaviorsArr;
	_nextBehaviorsCount++;

	return true;
}

Behavior* Behavior::selectNextBehavior()
{
	double maxAvailableSpace = 0;
	Behavior* bestBehavior= NULL;

	// Find the best behavior that can start
	for(int i=0; i<_nextBehaviorsCount; i++)
	{
		double currSpace = _nextBehaviors[i]->getPriority();
		if(_nextBehaviors[i]->startCond() && currSpace > maxAvailableSpace)
		{
			bestBehavior = _nextBehaviors[i];
			maxAvailableSpace = currSpace;
		}
	}

	return bestBehavior;
}

Behavior::~Behavior()
{
	if (_nextBehaviors != NULL)
		delete[] _nextBehaviors;
}
