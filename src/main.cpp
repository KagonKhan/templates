#include <vk_engine.h>

#include <spdlog/spdlog.h>

int main(int argc, char* argv[]) {
	spdlog::set_level(spdlog::level::trace);
	spdlog::info("Welcome to spdlog version {}.{}.{}  !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
	VulkanEngine engine;
	
	engine.run();	

	return 0;
}
