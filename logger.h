//
// Created by Никита Рыданов on 09/07/2021.
//
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <set>
#include <map>

// Logging levels:
// ERROR - only error messages appear
// WARNING - error and warning messages appear
// INFO - all messages appear
namespace Log {


    enum LogLevel {
        ERROR,
        WARNING,
        INFO
    };

// Pure virtual class (interface)
    class LoggerDestination {
    public:
        virtual void error(const std::string &errorMessage) = 0;

        virtual void warning(const std::string &warningMessage) = 0;

        virtual void info(const std::string &infoMessage) = 0;
    };

    class Logger {
    public:
        void addDestination(LoggerDestination *logger);

        void removeDestination(LoggerDestination *logger);

        void error(const std::string &errorMessage) const;

        void warning(const std::string &warningMessage) const;

        void info(const std::string &infoMessage) const;

        Logger();

        explicit Logger(LogLevel logLevel);

    protected:
        LogLevel logLevel;
    private:
        std::set<LoggerDestination *> loggerDestinations;
        std::map<LogLevel, int> priority;
    };

// File stream logger
    class FileLogger : public LoggerDestination {
    public:
        void error(const std::string &errorMessage) override;

        void warning(const std::string &warningMessage) override;

        void info(const std::string &infoMessage) override;

        explicit FileLogger(std::ofstream &destination, LogLevel logLevel);

    private:
        std::ofstream &destination;
    };

// Console stream logger
    class ConsoleLogger : public LoggerDestination {
    public:
        void error(const std::string &errorMessage) override;

        void warning(const std::string &warningMessage) override;

        void info(const std::string &infoMessage) override;

        explicit ConsoleLogger(std::ostream &destination);

    private:
        std::ostream &destination;
    };

}
#endif