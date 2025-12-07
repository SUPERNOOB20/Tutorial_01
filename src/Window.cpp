#include "Window.h"

Window::Window(int width, int height):
	m_width(width),
	m_height(height)
{
	glfwInit();

	// OpenGL 3.3. Modern OpenGL 1.0 ==== 4.5
	// Vulkan
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window_ptr = glfwCreateWindow(width, height, "Tutorial_01", NULL, NULL);	// Creates a pointer to the window which will be OpenGL's context.
	if(window_ptr ==  nullptr)
	{
		cout << "Error initializing GLFW :c" << endl;
		return;
	}

	glfwMakeContextCurrent(window_ptr);

	if(glewInit())
	{
		cout << "Error initializing GLEW :c" << endl;
		return;
	}
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Input()
{
	if(glfwGetKey(window_ptr, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(window_ptr, true);
	}
}

void Window::Resize()
{
	bool size_does_not_match = (width != m_width || height != m_height);
	int width,height;
	glfwGetWindowSize(window_ptr, &width, &height);
	if(size_does_not_match)
	{
		// Changes size accordingly so that it matches the given values.
		m_width = width;
		m_height = height;
		glViewport(0, 0, width, height);
		printf("resized \n");
	}
}

void Window::Mainloop()
{
	// For each frame...
	while (!glfwWindowShouldClose(window_ptr))
	{
		
		Resize();
		Input();

		glClearColor(0.5f, 0.8f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// all drawing goes here ..









		
		glfwSwapBuffers(window_ptr);
		glfwPollEvents();
	}
}
