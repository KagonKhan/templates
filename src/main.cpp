#include "app/app.hpp"

#include "utils/logger.hpp"

#include <spdlog/spdlog.h>
#include <iostream>
class TestBase : LoggerBase
{
public:
    TestBase()
        : LoggerBase("TestBase")
    {
        LOG_CRITICAL("Your mom is {} kg phat", 2002);
    }
};

class TestCRTP : LoggerCRTP<TestCRTP>
{
public:
    static std::string name() { return "TestCRTP"; }

    TestCRTP()
    {
        LOG_CRITICAL("Your mom is {} kg phat", 2002);
    }
};


#define LOG LoggerMacro::get("TestMacro")


void doMacro()
{
    LOG.TRACE("Some macro logger test");
    LOG.DEBUG("Some macro logger test");
    LOG.INFO("Some macro logger test");
    LOG.WARNING("Some macro logger test");
    LOG.ERROR("Some macro logger test");
    LOG.CRITICAL("Some macro logger test");
}

int main()
{
    TestBase base;
    TestCRTP crtp;

    doMacro();
    std::cout << "\n\n";
    spdlog::set_level(spdlog::level::trace);
    doMacro();

    // App app {"Template Project"};
    // app.run();
}
