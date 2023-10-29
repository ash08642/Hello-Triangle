#include "HelloTriangleApplication.h"

//#define GLFW_INCLUDE_VULKAN
//#include <GLFW/glfw3.h>

void HelloTriangleApplication::run() {
	initWindow();	// ohne GLFW nicht möglich
	intVulkan();
	mainLoop();
	cleanUp();
}

void HelloTriangleApplication::initWindow() {
	glfwInit();	// initializes the GLFW library

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);	// not create an OpenGl context, because GLFW was originally desinged for OpenGl
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);	// handling resizable windows, False -> Ignorieren

	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);	// width, height, title of window, monitor, -relevant only to OpenGl
}

void HelloTriangleApplication::intVulkan() {
	createInstance();
}

void HelloTriangleApplication::mainLoop() {
	while (!glfwWindowShouldClose(window))	// Loops and checks for events like pressing the X button until window has been closed
	{
		glfwPollEvents();
	}
}

void HelloTriangleApplication::cleanUp() {
	vkDestroyInstance(instance, nullptr);

	glfwDestroyWindow(window);

	glfwTerminate();
}

void HelloTriangleApplication::createInstance() {
	VkApplicationInfo appInfo{};	// Information about our Application(Optional). Useful for Optimization
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_3;	// 1_0 in tutorial pdf

	VkInstanceCreateInfo createInfo{};	// Tells Vulkan driver which global Extensions and Validation layers we want to use
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionCount = 0;	//GLFW has a handy built - in function that returns the extension(s) it needs (ti interface with the window system) to do that which we can pass to the struct
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	/*	Show Number of Extensions Available Out put their Names
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount,
		nullptr);
	std::vector<VkExtensionProperties> extensions(extensionCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount,
		extensions.data());
	std::cout << "available extensions:\n" << extensionCount << std::endl;
		for (const auto& extension : extensions) {
		std::cout << '\t' << extension.extensionName << '\n';
	}
	*/

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;

	createInfo.enabledExtensionCount = 0;	// Create an Instance
	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
		throw std::runtime_error("failed to create instance!");
	}
}