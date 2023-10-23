// Include GLAD before GLFW

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {

	glfwInit(); // Initializes GLFW library. Must be done before using most GLFW functions. Returns GL_TRUE if successful, and GL_FALSE if not.
	// "window hint": a setting or configuration option to guide GLFW on intended window behavior
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Tell GLFW which major version of OpenGL we are using - 3.x
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Tell GLFW which minor version of OpenGL we are using - x.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Tell GLFW we are using the core-profile of OpenGL; as opposed to the old compatibility

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL); // Create a window object of resolution 800x600. Leave monitor unspecified and do not share window with other windows.
	if (window == NULL) { // glfwCreateWindow returns NULL if it failed for whatever reason.
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate(); // Destroys all remaining windows and cursors, frees allocated resources
		return -1;
	}
	glfwMakeContextCurrent(window); // Each thread can only have a single current context at a time

	return 0;
}