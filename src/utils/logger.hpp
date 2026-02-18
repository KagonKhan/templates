#ifndef PROJECT_UTILS_LOGGER_HPP
#define PROJECT_UTILS_LOGGER_HPP

#include "meta.hpp"

#include <spdlog/logger.h>
#include <spdlog/sinks/base_sink.h>
#include <spdlog/spdlog.h>

#include <iostream>
/*
    Conclusions:
      Negatives:
        - Calling the base constructor for every loggable class is a chore
        - Every class instance has shared_pointer to logger with a class name - minor waste of space -
          cannot be used for instance-heavy classes
        - For very customized logger names (for example based on derived arguments)
          requires manually calling something like `setLoggerName`)
      Positives:
        - Children are not required to implement any structure as with CRTP example
*/
class LoggerBase
{
public:
    template <typename ... Args>
    void LOG_TRACE(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->trace(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void LOG_DEBUG(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->debug(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void LOG_INFO(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->info(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void LOG_WARNING(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->warn(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void LOG_ERROR(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->error(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void LOG_CRITICAL(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->critical(fmt, std::forward<Args>(args)...);
    }

protected:
    explicit LoggerBase(std::string name)
        : logger_(spdlog::get(name))
    {
        if (!logger_) {
            logger_ = defaultLogger().clone(std::move(name));
            spdlog::register_logger(logger_);
        }
    }

private:
    std::shared_ptr<spdlog::logger> logger_;

    static spdlog::logger& defaultLogger()
    {
        static std::shared_ptr<spdlog::logger> instance = spdlog::default_logger();
        return *instance.get();
    }
};


/*
    Conclusions:
      Negatives:
        - Children are required to implement a `name` function
      Positives:
        - The logger can be static between class intances eliminating memory
        - Base constructor doesn't need to be called, like in the LoggerBase case.
*/
template <typename Derived>
class LoggerCRTP
{
public:
    template <typename ... Args>
    void LOG_TRACE(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->trace(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void LOG_DEBUG(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->debug(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void LOG_INFO(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->info(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void LOG_WARNING(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->warn(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void LOG_ERROR(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->error(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void LOG_CRITICAL(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->critical(fmt, std::forward<Args>(args)...);
    }

protected:
    LoggerCRTP()
    {
        if (!logger_) {
            logger_ = spdlog::get(std::string(type_name<Derived>()));

            if (!logger_) {
                logger_ = defaultLogger().clone(std::string(type_name<Derived>()));
                spdlog::register_logger(logger_);
            }
        }
    }

private:
    inline static std::shared_ptr<spdlog::logger> logger_;

    static spdlog::logger& defaultLogger()
    {
        static std::shared_ptr<spdlog::logger> instance = spdlog::default_logger();
        return *instance.get();
    }
};

/*
    Conclusions:
      Negatives:
        - Cannot be used in header files -> macro pollution
      Positives:
        - Doesn't have to pollute children at all
*/
class LoggerMacro
{
public:
    template <typename ... Args>
    void TRACE(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->trace(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void DEBUG(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->debug(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void INFO(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->info(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void WARNING(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->warn(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void ERROR(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->error(fmt, std::forward<Args>(args)...);
    }

    template <typename ... Args>
    void CRITICAL(spdlog::format_string_t<Args...> fmt, Args&&... args)
    {
        logger_->critical(fmt, std::forward<Args>(args)...);
    }

    static LoggerMacro get(std::string name)
    {
        auto logger = spdlog::get(name);
        if (!logger) {
            logger = defaultLogger().clone(name);
            spdlog::register_logger(logger);
        }

        return LoggerMacro {logger};
    }

private:
    std::shared_ptr<spdlog::logger> logger_;

    explicit LoggerMacro(std::shared_ptr<spdlog::logger> logger)
        : logger_(logger) {}

    static spdlog::logger& defaultLogger()
    {
        static std::shared_ptr<spdlog::logger> instance = spdlog::default_logger();
        return *instance.get();
    }
};


#endif // PROJECT_UTILS_LOGGER_HPP
