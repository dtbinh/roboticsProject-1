/*
 * LocalizationManager.h
 *
*  Created on: Aug 1, 2016
 *      Author: user
 */

#ifndef LOCALIZATIONMANAGER_H_
#define LOCALIZATIONMANAGER_H_

#include <vector>
#include "../Particle/Particle.h"
#include "../Utils/Location.h"
#include "../Utils/Utils.h"
#include "../Managers/ConfigurationManager.h"

class LocalizationManager {
public:
	LocalizationManager();
	virtual ~LocalizationManager();

	std::vector<Particle*> particles;
	void updateParticles(Robot* robot, double deltaX, double deltaY, double deltaYaw);
	Particle* getBestParticle();
	void createParticles();
};

#endif /* LOCALIZATIONMANAGER_H_ */
