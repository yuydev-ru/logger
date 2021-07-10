//
// Created by Никита Рыданов on 09/07/2021.
//
#pragma once

#include <fstream>
#include <set>

// Logging levels:
// ERROR - only error messages appear
// WARNING - error and warning messages appear
// INFO - all messages appear
enum LogLevel {
    ERROR,
    WARNING,
    INFO
};

// Pure virtual class (interface)
class Logger {
public:
    virtual void error(const std::string &errorMessage) = 0;
    virtual void warning(const std::string &warningMessage) = 0;
    virtual void info(const std::string &infoMessage) = 0;
protected:
    LogLevel logLevel = ERROR;
};

// Logging manager class
class LoggerController {
public:
    void addLogger(Logger* logger);
    void removeLogger(Logger* logger);
    void error(const std::string &errorMessage);
    void warning(const std::string &warningMessage);
    void info(const std::string &infoMessage);
protected:
    LogLevel logLevel = ERROR;
private:
    std::set<Logger*> loggers;
};

// File stream logger
class FileLogger : Logger {
public:
    void error(const std::string &errorMessage) override;
    void warning(const std::string &warningMessage) override;
    void info(const std::string &infoMessage) override;
    explicit FileLogger(std::ofstream& destination, LogLevel logLevel);

private:
    std::ofstream &destination;
};

// Console stream logger
class ConsoleLogger : Logger {
public:
    void error(const std::string &errorMessage) override;
    void warning(const std::string &warningMessage) override;
    void info(const std::string &infoMessage) override;
    explicit ConsoleLogger(std::ostream& destination, LogLevel logLevel);
private:
    std::ostream &destination;
};

