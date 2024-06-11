#include "Window.h"

namespace SRMM
{
	Window::Window(const Size& size, const std::string& title)
		: mTitle(title), mClearColor({ 0.0f }), mWidth(size.Width), mHeight(size.Height) 
	{ 
		Init();
	}

	bool Window::Init()
	{
		mNativeWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), 0, 0);

		if (!mNativeWindow)
		{
			std::cerr << "Error: cannot create a GLFW window." << std::endl;
		}

		glfwMakeContextCurrent(mNativeWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cerr << "Error: failed to initialize GLAD." << std::endl;
		}

		return mNativeWindow;
	}

	int Window::GetWidth()
	{
		return mWidth;
	}

	int Window::GetHeight()
	{
		return mHeight;
	}

	Size Window::GetSize()
	{
		return { mWidth, mHeight };
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(mNativeWindow);
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}

	void Window::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.x, color.y, color.z, color.w);
	}

	GLFWwindow* Window::GetNativeWindow()
	{
		return mNativeWindow;
	}
}