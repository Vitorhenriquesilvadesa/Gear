#ifndef POOL_API_H
#define POOL_API_H

#pragma once

#include "ApplicationService.h"
#include "Renderer.h"
#include "Component.h"

namespace SRMM
{
	class PoolAPI : public ApplicationService
	{
	public:
		bool Init() override;
		void Update(TimeSpam& deltaTime) override;
		void Shutdown() override;

		void AddRenderer(const Ref<Renderer>& renderer) { mRenderers.push_back(renderer); }

		const GameObject& Instantiate() 
		{ 
			Ref<GameObject> gameObject = std::make_shared<GameObject>();
			mGameObjects.push_back(gameObject);
			return *gameObject;
		}

	private:
		std::vector<Ref<Renderer>> mRenderers;
		std::vector<Ref<GameObject>> mGameObjects;
	};
}

#endif