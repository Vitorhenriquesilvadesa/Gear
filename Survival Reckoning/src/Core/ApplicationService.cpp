#pragma once
#include "ApplicationService.h"

namespace SRMM
{
    void ServiceRegistry::UpdateServices(TimeSpam deltaTime) const
    {
        for (auto& service : mServices) {
            if (service.second) {
                service.second->Update(deltaTime);
            }
        }
    }

    void ServiceRegistry::ShutdownServices() const
    {
        for (auto& service : mServices) {
            if (service.second) {
                service.second->Shutdown();
                std::cout << "Finishing " << typeid(*service.second).name() << " service." << std::endl;
            }
        }
    }
}