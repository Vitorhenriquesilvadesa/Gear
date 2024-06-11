#ifndef SRMM_GAME_H
#define SRMM_GAME_H

#include "Common.h"
#include "TimeSpam.h"

namespace SRMM
{
	class SRMMGame
	{
	public:
		virtual void OnStart() = 0;
		virtual void OnUpdate(TimeSpam& deltaTime) = 0;
	};
}

#endif
