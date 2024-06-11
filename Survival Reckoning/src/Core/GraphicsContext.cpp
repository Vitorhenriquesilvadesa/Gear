#include "GraphicsContext.h"

namespace SRMM
{
	GraphicsContext::GraphicsContext()
	{
		if (!glfwInit())
		{
			throw std::runtime_error("Failed to initialize GLFW");
		}

		mWindow = Window(Size(1280, 720), "Survival Reckoning");

		mNativeWindow = mWindow.GetNativeWindow();
	}

	void GraphicsContext::Clear()
	{
		mWindow.Clear();
	}

	void GraphicsContext::SwapBuffers()
	{
		mWindow.SwapBuffers();
	}

	void GraphicsContext::PollEvents()
	{
		mWindow.PollEvents();
	}

	void GraphicsContext::Destroy()
	{
		glfwDestroyWindow(mWindow.GetNativeWindow());
		glfwTerminate();
	}

	bool GraphicsContext::IsWindowClosed()
	{
		return glfwWindowShouldClose(mNativeWindow);
	}

	void GraphicsContext::setupCallbacks()
	{
	}

	void GraphicsContext::windowResizeCallback(GLFWwindow* window, int width, int height)
	{
	}

	void GraphicsContext::windowCloseCallback(GLFWwindow* window)
	{
	}
}