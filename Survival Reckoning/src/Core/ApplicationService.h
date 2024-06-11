#ifndef APPLICATION_SERVICE_H
#define APPLICATION_SERVICE_H

#include "TimeSpam.h"
#include "Common.h"

#include <typeindex>

namespace SRMM
{
	using CallbackFunction = std::function<bool()>;

	enum class ApplicationFlag
	{
		WindowClose
	};

	class ApplicationService
	{
	public:
		ApplicationService() = default;
		virtual ~ApplicationService() = default;
		virtual bool Init() = 0;
		virtual void Update(TimeSpam& deltaTime) = 0;
		virtual void Shutdown() = 0;
	};

	class ServiceRegistry
	{
	public:
		ServiceRegistry() = default;

		void RegisterFlag(ApplicationFlag flag, const CallbackFunction& callback)
		{
			mFlagCallbacks[flag] = callback;
		}

		bool GetFlag(ApplicationFlag flag)
		{
			return mFlagCallbacks[flag]();
		}

		template<typename T>
		void RegisterService()
		{
			mServices[typeid(T)] = std::make_shared<T>();
			std::cout << "Initializing " << typeid(T).name() << " service." << std::endl;
		}

		template<typename T>
		Ref<T> FromService()
		{
			auto it = mServices.find(typeid(T));
			if (it != mServices.end()) {
				auto service = std::dynamic_pointer_cast<T>(it->second);
				if (service) {
					return service;
				}
			}
			return nullptr;
		}


		void UpdateServices(TimeSpam deltaTime) const;
		void ShutdownServices() const;

		std::unordered_map<std::type_index, Ref<ApplicationService>>::iterator begin()
		{
			return mServices.begin();
		}

		std::unordered_map<std::type_index, Ref<ApplicationService>>::iterator end()
		{
			return mServices.end();
		}

	private:
		std::unordered_map<std::type_index, Ref<ApplicationService>> mServices;
		std::unordered_map<ApplicationFlag, CallbackFunction> mFlagCallbacks;
	};
}

#endif