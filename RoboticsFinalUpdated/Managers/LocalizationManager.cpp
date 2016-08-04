/*
 * LocalizationManager.cpp
 *
*  Created on: Aug 1, 2016
 *      Author: user
 */

#include "LocalizationManager.h"

LocalizationManager::LocalizationManager()
{
	int xStartLocation = Utils::configurationManager->xStartLocation;
	int yStartLocation = Utils::configurationManager->yStartLocation;
	int yawStartLocation = Utils::configurationManager->yawStartLocation;

	// Create the first particle
	Location* firstParticleLoc = new Location(xStartLocation,yStartLocation, yawStartLocation);

	Particle* firstParticle = new Particle(firstParticleLoc, 1);
	particles.push_back(firstParticle);

	// Create all particles
	for(int i = 1; i < Utils::PARTICLES_NUMBER; i++)
	{
		Particle* currentParticle = firstParticle->createParticle();
		particles.push_back(currentParticle);
	}
}

LocalizationManager::~LocalizationManager()
{
	// TODO Auto-generated destructor stub
}

void LocalizationManager::updateParticles(Robot* robot, double deltaX, double deltaY, double deltaYaw)
{
	double currBelief;
	std::vector<Particle*> newParticles;
	int maxIndex = 0;
	double maxBelief = 0;

	for(unsigned int i = 0; i < this->particles.size(); i++)
	{
		currBelief =
			this->particles[i]->update(deltaX, deltaY, deltaYaw, robot);

		if (currBelief > maxBelief){
			maxBelief = currBelief;
			maxIndex = i;
		}

		if(currBelief >= Utils::MIN_BELIEF_THRESHOLD)
		{
			newParticles.push_back(this->particles[i]);
		}
	}

	// don't get 0 particles
	if (newParticles.size() == 0){
		if (this->particles[maxIndex]->belief < 0.2){
			this->particles[maxIndex]->belief = 0.8;
		}
		newParticles.push_back(this->particles[maxIndex]);
		for(int i = 2; i < 30; i++)
		{
			Particle* currentParticle = this->particles[maxIndex]->createParticle();
			newParticles.push_back(currentParticle);
		}
	}

	particles = newParticles;
}

void LocalizationManager::createParticles()
{
	for (unsigned int i = 0; i < this->particles.size(); i++){
		// create new one
		if ((particles[i]->belief > Utils::GOOD_BELIEF_THRESHOLD) &&
				(this->particles.size() < Utils::PARTICLES_NUMBER))
		{
			Particle* son = particles[i]->createParticle();
			particles.push_back(son);
		}
	}
}


Particle* LocalizationManager::getBestParticle()
{
	int bestParticle = 0;

	for(unsigned int i = 0; i < particles.size(); i++)
	{
		if (particles[bestParticle]->belief < particles[i]->belief)
		{
			bestParticle = i;
		}
	}

	return particles[bestParticle];
}
