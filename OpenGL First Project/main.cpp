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

	// GLAD manages function pointers for OpenGL - Finding OpenGL functions is up to the developer
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { // gladLoadGLLoader is a function responsible for loading OpenGL function pointers for your system
		std::cout << "Failed to initialize GLAD\n";
		return -1;
	}

	glViewport(0, 0, 800, 600); // Specifies the rendering rectangle: Parameters (left x-coordinate, bottom y-coordinate, width, height)

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // Tell our window to call framebuffer_size_callback whenever it is resized

	while (!glfwWindowShouldClose(window)) { // render loop; like game loops used in SFML
		glfwSwapBuffers(window); // OpenGL uses double buffers to prevent artifacting. Buffers draw pixel by pixel to the screen and we don't want the user to see this, so we draw to an invisible buffer that is switched to upon completion.
		glfwPollEvents(); // like processEvents() in SFML
	}

	glfwTerminate(); // If we've made it past the rendering loop, it's time to say goodbye.
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) { // When user resizes window, must adjust viewport as well. Use callback function on window when resized
	glViewport(0, 0, width, height);
}