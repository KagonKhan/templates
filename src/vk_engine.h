// vulkan_guide.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vk_types.h>
#include <memory>
#include <vector>

class VulkanEngine {
public:
	VulkanEngine();
	~VulkanEngine();

	void draw();
	void run();

private:
	void init();
	void initVulkan();
	void initSwapchain();
	void initCommands();
	void initDefaultRenderpass();
	void initFramebuffers();
	void initSyncStructures();

	void cleanup();





	struct WindowDeleter {
		void operator()(struct SDL_Window* window);
	};
	std::unique_ptr<SDL_Window, WindowDeleter> sdl_window{ nullptr };
	VkExtent2D windowExtent{ 1700 , 900 };
	int frame_number{ 0 };



	VkInstance instance; // Vulkan library handle
	VkDebugUtilsMessengerEXT debug_messenger; // Vulkan debug output handle
	
	VkPhysicalDevice chosenGPU; // GPU chosen as the default device
	VkDevice device; // Vulkan device for commands
	VkSurfaceKHR surface; // Vulkan window surface




	VkSwapchainKHR swapchain; // from other articles
	// image format expected by the windowing system
	VkFormat swapchainImageFormat;
	//array of images from the swapchain
	std::vector<VkImage> swapchainImages;
	//array of image-views from the swapchain
	std::vector<VkImageView> swapchainImageViews;





	VkQueue graphicsQueue; //queue we will submit to
	uint32_t graphicsQueueFamily; //family of that queue

	VkCommandPool commandPool; //the command pool for our commands
	VkCommandBuffer mainCommandBuffer; //the buffer we will record into








	VkRenderPass renderPass;

	std::vector<VkFramebuffer> framebuffers;








	VkSemaphore presentSemaphore, renderSemaphore;
	VkFence renderFence;
};
