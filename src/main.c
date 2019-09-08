#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void resize_callback(GLFWwindow *window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

int main()
{
	GLFWwindow *window;

	/* initialize glfw and set hints for opengl profile and version */
	/* not really sure what the hints do! */
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* create a window */
	if (!(window = glfwCreateWindow(800, 600, "Learn OpenGL", NULL, NULL))) {
		puts("failed to create glfw window");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	/* let glad know how we want our functions loaded */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		puts("failed to initialize glad");
		glfwTerminate();
		return 2;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, resize_callback);

	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
