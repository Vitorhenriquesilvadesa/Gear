#include "Engine.h"
#include "GraphicsAPI.h"
#include "PoolAPI.h"

namespace SRMM
{
	Engine* Engine::sInstance = new Engine();

	void Engine::Run()
	{
		mGame->OnStart();
		while(!mServices.GetFlag(ApplicationFlag::WindowClose))
		{
			TimeSpam deltaTime = mTime.GetDeltaTime();

			Update(deltaTime);
			mGame->OnUpdate(deltaTime);
		}

		Shutdown();
	}

	void Engine::Update(const TimeSpam& deltaTime) const
	{
		mServices.UpdateServices(deltaTime);
	}

	void Engine::Shutdown() const
	{
		mServices.ShutdownServices();
	}

	void Engine::RegisterFlag(ApplicationFlag flag, const CallbackFunction& callback)
	{
		sInstance->mServices.RegisterFlag(flag, callback);
	}

	TimeSpam Engine::Time::GetDeltaTime() const
	{
		return { deltaTime };
	}

	void Engine::Time::Update()
	{
		float currentTime = static_cast<float>(glfwGetTime());
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;
	}
}
