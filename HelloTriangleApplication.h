#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <optional>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif // NDEBUG

namespace Debug {
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
}

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	bool isComplete() {
		return graphicsFamily.has_value();
	}
};

class HelloTriangleApplication
{
public:
	void run();

private:
	GLFWwindow* window;
	VkInstance instance;	// Initialize Vulkan Library. // Instance is the connection between our Application and the Vulkan library
	VkDebugUtilsMessengerEXT debugMessenger;	// for debugCallback
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;	// stores Graphics card that is selected
	VkDevice device;	// Logical Device Handle
	VkQueue grapicsQueue;	// Store handle to the graphics queue

	void initWindow();
	void intVulkan();
	void mainLoop();
	void cleanUp();

	void createInstance();

	bool checkValidationLayerSupport();	// checks if all of the requested Validation Layers are available
	std::vector<const char*> getRequiredExtensions();
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);	// 1.VkDebugUtilsMessageSeverityFlagBitsEXT => specifies the severity of the message
	void setupDebugMessenger();
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

	void pickPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);

	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

	void createLogicalDevice();
};

