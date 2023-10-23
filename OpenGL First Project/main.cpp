// Include GLAD before GLFW

#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {

	glfwInit(); // Initializes GLFW library. Must be done before using most GLFW functions. Returns GL_TRUE if successful, and GL_FALSE if not.
	// "window hint": a setting or configuration option to guide GLFW on intended window behavior
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Tell GLFW which major version of OpenGL we are using - 3.x
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Tell GLFW which minor version of OpenGL we are using - x.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Tell GLFW we are using the core-profile of OpenGL; as opposed to the old compatibility

	return 0;
}