#ifndef GAME_H
#define GAME_H

#include "TimeSpam.h"
#include "GraphicsAPI.h"
#include "PoolAPI.h"
#include "Common.h"
#include "SRMMGame.h"

namespace SRMM
{
	class Engine
	{
	public:
		Engine() {
			mTime = Time();
		}

		template<typename T>
		void Init()
		{
			if (!std::is_base_of<SRMMGame, T>::value)
			{
				throw std::runtime_error("Game type must be derive from SRMMGame.");
			}

			mGame = std::make_shared<T>();
			mServices.RegisterService<GraphicsAPI>();
			mServices.RegisterService<PoolAPI>();

			mServices.RegisterFlag(ApplicationFlag::WindowClose, [&] { return FromService<GraphicsAPI>()->IsWindowClosed(); });
		}
		void Run();
		void Update(const TimeSpam& deltaTime) const;
		void Shutdown() const;

		template<typename T>
		static Ref<T> FromService()
		{
			return sInstance->mServices.FromService<T>();
		}

		static void RegisterFlag(ApplicationFlag flag, const CallbackFunction& callback);

		static Engine& GetInstance()
		{
			return *sInstance;
		}

	private:
		class Time
		{
		public:
			Time() = default;
			~Time() = default;
			TimeSpam GetDeltaTime() const;
			void Update();
		private:
			float lastTime;
			float deltaTime;
		};

	private:
		Time mTime;
		static Engine* sInstance;
		ServiceRegistry mServices;
		Ref<SRMMGame> mGame;
	};
}

#endif