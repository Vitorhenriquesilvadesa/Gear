#ifndef GRAPHICS_API_H
#define GRAPHICS_API_H

#include "ApplicationService.h"
#include "GraphicsContext.h"

namespace SRMM
{
	class GraphicsAPI : public ApplicationService
	{
	public:
		GraphicsAPI() : mContext() { }
		bool Init() override;
		void Update(TimeSpam& deltaTime) override;
		void Shutdown() override;
		bool IsWindowClosed();

	private:
		GraphicsContext mContext;
	};
}

#endif