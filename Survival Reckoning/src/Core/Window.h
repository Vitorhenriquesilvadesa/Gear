#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Common.h"
#include "Util.h"
#include <glm/glm.hpp>

namespace SRMM
{
	class Window
	{
	public:
		Window() = default;
		Window(const Size& size, const std::string& title);
		bool Init();
		int GetWidth();
		int GetHeight();
		Size GetSize();
		void SwapBuffers();
		void PollEvents();
		void Clear();
		void SetClearColor(const glm::vec4& color);
		GLFWwindow* GetNativeWindow();

	private:
		int mWidth;
		int mHeight;
		std::string mTitle;
		GLFWwindow* mNativeWindow;
		glm::vec4 mClearColor;
	};
}

#endif
