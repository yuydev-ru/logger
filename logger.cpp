//
// Created by Никита Рыданов on 09/07/2021.
//

#include "logger.h"
#include <iostream>
#include <chrono>

using namespace logger;

// Overriding methods
void
FileLogger::error(const std::string &errorMessage)
{
    auto currentTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
    auto tm = gmtime(&time);
    std::string h = std::to_string(tm->tm_hour);
    std::string m = std::to_string(tm->tm_min);
    std::string s = std::to_string(tm->tm_sec);

    this->destination << "[" + h + ":" + m + ":" + s + "]" + "[ERROR] " << errorMessage << std::endl;
}

void
FileLogger::info(const std::string &infoMessage)
{
    auto currentTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
    auto tm = gmtime(&time);
    std::string h = std::to_string(tm->tm_hour);
    std::string m = std::to_string(tm->tm_min);
    std::string s = std::to_string(tm->tm_sec);
    this->destination << "[" + h + ":" + m + ":" + s + "]" + "[INFO] " << infoMessage << std::endl;
}

void
FileLogger::warning(const std::string &warningMessage)
{
    auto currentTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
    auto tm = gmtime(&time);
    std::string h = std::to_string(tm->tm_hour);
    std::string m = std::to_string(tm->tm_min);
    std::string s = std::to_string(tm->tm_sec);
    this->destination << "[" + h + ":" + m + ":" + s + "]" + "[WARNING] " << warningMessage << std::endl;;
}

void
ConsoleLogger::error(const std::string &errorMessage)
{
    auto currentTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
    auto tm = gmtime(&time);
    std::string h = std::to_string(tm->tm_hour);
    std::string m = std::to_string(tm->tm_min);
    std::string s = std::to_string(tm->tm_sec);
    this->destination << "[" + h + ":" + m + ":" + s + "]" + "[ERROR] " << errorMessage << std::endl;
}

void
ConsoleLogger::info(const std::string &infoMessage)
{
    auto currentTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
    auto tm = gmtime(&time);
    std::string h = std::to_string(tm->tm_hour);
    std::string m = std::to_string(tm->tm_min);
    std::string s = std::to_string(tm->tm_sec);
    this->destination << "[" + h + ":" + m + ":" + s + "]" + "[INFO] " << infoMessage << std::endl;
}

void
ConsoleLogger::warning(const std::string &warningMessage)
{
    auto currentTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
    auto tm = gmtime(&time);
    std::string h = std::to_string(tm->tm_hour);
    std::string m = std::to_string(tm->tm_min);
    std::string s = std::to_string(tm->tm_sec);
    this->destination << "[" + h + ":" + m + ":" + s + "]" + "[WARNING] " << warningMessage << std::endl;
}

// Constructors
ConsoleLogger::ConsoleLogger(std::ostream &destination): destination(destination) {};

FileLogger::FileLogger(std::ofstream &destination, LogLevel logLevel) : destination(destination) {};

// LoggerDestination controller methods

void
Logger::addDestination(LoggerDestination *loggerRef)
{
    loggerDestinations.insert(loggerRef);
}

void
Logger::removeDestination(LoggerDestination *loggerRef)
{
    loggerDestinations.erase(loggerRef);
}

void
Logger::error(const std::string &errorMessage) const
{
    if (priority.at(ERROR) < priority.at(logLevel))
    {
        return;
    }

    for (auto destination : loggerDestinations)
    {
        destination->error(errorMessage);
    }
}

void
Logger::warning(const std::string &errorMessage) const
{
    if (priority.at(WARNING) < priority.at(logLevel))
    {
        return;
    }

    for (auto destination : loggerDestinations)
    {
        destination->warning(errorMessage);
    }
}

void
Logger::info(const std::string &errorMessage) const
{
    if (priority.at(INFO) < priority.at(logLevel))
    {
        return;
    }

    for (auto destination : loggerDestinations)
    {
        destination->info(errorMessage);
    }
}

Logger::Logger()
{
    this->logLevel = ERROR;
    priority[ERROR] = 3;
    priority[WARNING] = 2;
    priority[INFO] = 1;
}

ConsoleLogger::ConsoleLogger() : destination(std::cout) {}

Logger::Logger(LogLevel logLevel) : Logger()
{
    this->logLevel = logLevel;
}

