#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <vector>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication
{
public:
	void run();

private:
	GLFWwindow* window;
	VkInstance instance;	// Initialize Vulkan Library. // Instance is the connection between our Application and the Vulkan library

	void initWindow();
	void intVulkan();
	void mainLoop();
	void cleanUp();

	void createInstance();
};

