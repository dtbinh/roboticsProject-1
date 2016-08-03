/*
 * general.cpp
 *
 *  Created on: Aug 1, 2016
 *      Author: user
 */
#include "general.h"

Behavior** createBehaviors(Robot* robot) {
	// initialize behaviors
	Behavior *turnToWayPoint;

	Behavior** behaviors = new Behavior*[4];

    behaviors[0] = new MoveToWaypoint(robot);
    behaviors[1] = new MoveForward(robot);
    behaviors[2] = new TurnRight(robot);
    behaviors[3] = new TurnLeft(robot);
    // Connecting behaviors
    behaviors[0]->addNext(behaviors[2]);
    behaviors[0]->addNext(behaviors[3]);
    behaviors[1]->addNext(behaviors[2]);
    behaviors[1]->addNext(behaviors[3]);
    behaviors[2]->addNext(behaviors[0]);
    behaviors[3]->addNext(behaviors[0]);

    return behaviors;
}

void run_robot(Robot* robot, list<Node*> path, Behavior** behaviors,
				Map* mMap, point pStart, point pEnd) {
	Behavior *currBehavior = behaviors[0];
	for (std::list<Node*>::iterator iCurrWaypoint = path.begin();
		 iCurrWaypoint != path.end();
		 iCurrWaypoint++)
	    {
	    	PrintToConsole((int)pStart.X,(int)pStart.Y,
						   (int)pEnd.X,(int)pEnd.Y, mMap,path,robot);
	    	((MoveToWaypoint*)behaviors[0])->setNextWaypoint(*iCurrWaypoint);

	    	robot->update();

	    	// while waypoint is not in range
	    	while (!robot->isInWaypointRange(*iCurrWaypoint,
											 mMap->GetGridMapResolution()))
	    	{
	    		// If curr behavior can be activated
	    		if (currBehavior->startCond()) {
 	    			currBehavior->action();
	    		}
	    		else {
	    			currBehavior = currBehavior->selectNext();
	    			cout << "   ...change behavior to " << currBehavior->strBehaviorName;
	    		}
	    		robot->update();
	    	}
	    }
}

void PrintToConsole(int nStartX,int nStartY,
		int nWantedLocationX,int nWantedLocationY,
		Map* mMap, list<Node*> path, Robot *robot) {
	double robotGridX = robot->getX() / mMap->GetGridMapResolution();
	double robotGridY = robot->getY() / mMap->GetGridMapResolution();
	system("cls");

	for (int i = 0; i < mMap->vMapMatrix.size(); i++)
	{
		for (int j = 0; j < mMap->vMapMatrix[0].size(); j++)
		{
			bool bAStarPoint = false;
			for (std::list<Node*>::iterator listIterator = path.begin();
			listIterator != path.end();
			listIterator++)
			{
				if ((j == (*listIterator)->x) && (i == (*listIterator)->y))
				{
					bAStarPoint = true;
					break;
				}
			}

			if (bAStarPoint)
			{
				cout << ".";
			}
			else if ((j == nWantedLocationX) && (i == nWantedLocationY))
			{
				cout << 'F';
			}
			else if ((j == nStartX) && (i== nStartY))
			{
				cout << 'S';
			}
			else if ((j == robotGridX) && (i == robotGridY))
			{
				cout << '#';
			}
			else
			{
				point p = {j,i};
				if (mMap->IsCellFree(p))
					cout << ' ';
				else
					cout << '0';
			}
		}
		cout << endl;
	}
}
