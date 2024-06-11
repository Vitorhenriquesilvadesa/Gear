#ifndef SURVIVAL_RECKONING_H
#define SURVIVAL_RECKONING_H

#include "SRMM.h"

using namespace SRMM;

class SurvivalReckoning : public SRMMGame
{
	void OnStart();
	void OnUpdate(TimeSpam& deltaTime);
};

#endif