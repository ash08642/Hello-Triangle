//#include <vulkan/vulkan.h>	// Vulkan header from the LunarG SDK, which provides the functions, structures and enumerations.
//#define GLFW_INCLUDE_VULKAN
//#include <GLFW/glfw3.h>	// GLFW will include its own definitions and automatically load the Vulkan header with it.

#include <iostream>
#include <stdexcept>
#include <cstdlib>	// provides the EXIT_SUCCESS and EXIT_FAILURE macros.

#include "HelloTriangleApplication.h"

int main() {
	HelloTriangleApplication app;

	try
	{
		app.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


