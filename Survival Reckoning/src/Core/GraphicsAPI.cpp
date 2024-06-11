#include "GraphicsAPI.h"

namespace SRMM
{
	bool GraphicsAPI::Init()
	{
		return true;
	}

	void GraphicsAPI::Update(TimeSpam& deltaTime)
	{
		mContext.Clear();
		mContext.SwapBuffers();
		mContext.PollEvents();
	}

	void GraphicsAPI::Shutdown()
	{
		mContext.Destroy();
	}

	bool GraphicsAPI::IsWindowClosed()
	{
		return mContext.IsWindowClosed();
	}
}
