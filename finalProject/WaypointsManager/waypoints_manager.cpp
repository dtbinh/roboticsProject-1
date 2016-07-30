/*
 * waypoints_manager.cpp
 *
 *  Created on: May 27, 2016
 *      Author: user
 */

#ifndef WAYPOINTS_MANAGER_CPP_
#define WAYPOINTS_MANAGER_CPP_

#include "waypoints_manager.h"

WaypointsManager::WaypointsManager(point &pStart, point &pEnd,
									Map *map){
	std::list<Node*> lstPath = this->CreateAPath(pStart,pEnd,map);
	this->lstAPath = lstPath;
	//this->lstAPath = this->CreateAPath(pStart,pEnd,map);


}
std::list<Node*> WaypointsManager::CreateAPath(point pStart,
											  point pEnd,
											  Map *map){
	std::list<Node*> openList, closedList;
	std::map<Node*, Node*> nSourceNodes;

	bool bStuck = map->IsCellFree(pStart);
	bool bStuck2 = map->IsCellFree(pEnd);

	Node *nStart = new Node(pStart.X,pStart.Y,NULL);
	Node *nEnd = new Node(pEnd.X,pEnd.Y,NULL);
	Node *nCurrent = new Node(-1, -1,NULL);

	// Calculate
	nStart->calculateNode(nEnd);

	openList.push_back(nStart);
	//int nOpenListSize = openList.size();

	while (!nCurrent->isEqual(nEnd)) {
		// Search for the smallest F in the open list.
		for (std::list<Node*>::iterator iterNode= openList.begin();
			 iterNode != openList.end() ;
			 iterNode++){
			if ((iterNode == openList.begin()) ||
				(*iterNode)->getFValue() < nCurrent->getFValue()) {
				nCurrent = *iterNode;
			}
		}
		// If we reached end so stop the while.
		if (nCurrent->isEqual(nEnd)){
			break;
		}
		// Remove the current point and add it to the closed list.
		openList.remove(nCurrent);
		closedList.push_back(nCurrent);
		// Scan all the nodes around the current node
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				// If its the current point - then pass
				if (i == 0 && j == 0)
					continue;

				// calculate x & adjacentY of adjacent point
				point adjacent = {
						nCurrent->x + j,
						nCurrent->y + i
				};

				// Check if this point is in the closed list
				bool isPointInClosedList = false;
				for (std::list<Node*>::iterator iterNode = closedList.begin(); iterNode != closedList.end(); iterNode++)
				{
					if ((*iterNode)->x == adjacent.X && (*iterNode)->y == adjacent.Y)
					{
						isPointInClosedList = true;
						break;
					}
				}

				// If this point is in the closed list - continue
				if (!isPointInClosedList)
				{
					// Check if this point is in the open list
					bool isPointInOpenedList = false;
					for (std::list<Node*>::iterator iterNode = openList.begin(); iterNode != openList.end(); iterNode++)
					{
						if ((*iterNode)->x == adjacent.X && (*iterNode)->y == adjacent.Y)
						{
							isPointInOpenedList = true;
							break;
						}
					}

					// Check if cell is free and not in open list
					if ((!isPointInOpenedList) && (map->IsCellFree(adjacent))) {
						Node *thisPoint = new Node(adjacent.X, adjacent.Y, nCurrent);
						thisPoint->calculateNode(nEnd);
						openList.push_back(thisPoint);
						nSourceNodes[thisPoint] = nCurrent;
					}
				}
			}
		}
	}

	// After we found the path we have to go back
	// from the end node to the start node and get the path.
	std::list<Node*> lstPath;
	Node *pathCurrent = nCurrent;
	lstPath.push_back(nCurrent);
	while (!pathCurrent->isEqual(nStart)){
		pathCurrent = nSourceNodes[pathCurrent];
		lstPath.push_back(pathCurrent);
	}

	return lstPath;
}

#endif /* WAYPOINTS_MANAGER_CPP_ */
