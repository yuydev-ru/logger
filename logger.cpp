//
// Created by Никита Рыданов on 09/07/2021.
//

#include "logger.h"

using namespace log;

// Overriding methods
void
FileLogger::error(const std::string &errorMessage)
{
    this->destination << "[ERROR] " << errorMessage << std::endl << "===================" << std::endl;
}

void
FileLogger::info(const std::string &infoMessage)
{
    this->destination << "[INFO] " << infoMessage << std::endl << "===================" << std::endl;
}

void
FileLogger::warning(const std::string &warningMessage)
{
    this->destination << "[WARNING] " << warningMessage << std::endl << "===================" << std::endl;
}

void
ConsoleLogger::error(const std::string &errorMessage)
{
    this->destination << "[ERROR] " << errorMessage << std::endl << "===================" << std::endl;
}

void
ConsoleLogger::info(const std::string &infoMessage)
{
    this->destination << "[INFO] " << infoMessage << std::endl << "===================" << std::endl;
}

void
ConsoleLogger::warning(const std::string &warningMessage)
{
    this->destination << "[WARNING] " << warningMessage << std::endl << "===================" << std::endl;
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

Logger::Logger(LogLevel logLevel) : Logger()
{
    this->logLevel = logLevel;
}

