#pragma once

#include "SurvivalReckoning.h"
#include "Core/FileSystem.h"
#include "Core/Shader.h"

void SurvivalReckoning::OnStart()
{
	GameObject object = Engine::FromService<PoolAPI>()->Instantiate();
	object.AddComponent<Transform>();

	object.GetComponent<Transform>();
}

void SurvivalReckoning::OnUpdate(TimeSpam& deltaTime)
{
	
}
