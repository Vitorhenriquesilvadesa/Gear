#ifndef GRAPHICS_CONTEXT_H
#define GRAPHICS_CONTEXT_H

#include "Common.h"
#include "Window.h"

namespace SRMM
{

	class GraphicsContext
	{
	public:
		GraphicsContext();
		void Clear();
		void SwapBuffers();
		void PollEvents();
		void Destroy();
		bool IsWindowClosed();

	private:
		void setupCallbacks();
		void windowResizeCallback(GLFWwindow* window, int width, int height);
		void windowCloseCallback(GLFWwindow* window);

		GLFWwindow* mNativeWindow;
		Window mWindow;
	};
}

#endif