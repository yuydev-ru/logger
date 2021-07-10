//
// Created by Никита Рыданов on 09/07/2021.
//

#include "logger.h"

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
ConsoleLogger::ConsoleLogger(std::ostream &destination, LogLevel logLevel = ERROR): destination(destination)
{
    this->logLevel = logLevel;
}

FileLogger::FileLogger(std::ofstream &destination, LogLevel logLevel) : destination(destination)
{
    this->logLevel = logLevel;
}

// LoggerDestination controller methods

void
Logger::addLogger(LoggerDestination *loggerRef)
{
    loggers.insert(loggerRef);
}

void
Logger::removeLogger(LoggerDestination *loggerRef)
{
    loggers.erase(loggerRef);
}

void
Logger::error(const std::string &errorMessage) {
    for (auto logger : loggers)
    {
        logger->error(errorMessage);
    }
}

void
Logger::warning(const std::string &errorMessage) {
    for (auto logger : loggers)
    {
        logger->warning(errorMessage);
    }
}

void
Logger::info(const std::string &errorMessage) {
    for (auto logger : loggers)
    {
        logger->info(errorMessage);
    }
}

