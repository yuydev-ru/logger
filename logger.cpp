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
FileLogger::info(const std::string &infoMessage) {
    if (this->logLevel != INFO)
    {
        return;
    }
    this->destination << "[INFO] " << infoMessage << std::endl << "===================" << std::endl;
}

void
FileLogger::warning(const std::string &warningMessage) {
    if (this->logLevel != ERROR)
    {
        this->destination << "[WARNING] " << warningMessage << std::endl << "===================" << std::endl;
    }
}

void
ConsoleLogger::error(const std::string &errorMessage)
{
    this->destination << "[ERROR] " << errorMessage << std::endl << "===================" << std::endl;
}

void
ConsoleLogger::info(const std::string &infoMessage) {
    if (this->logLevel != INFO)
    {
        return;
    }
    this->destination << "[INFO] " << infoMessage << std::endl << "===================" << std::endl;
}

void
ConsoleLogger::warning(const std::string &warningMessage) {
    if (this->logLevel != ERROR)
    {
        this->destination << "[WARNING] " << warningMessage << std::endl << "===================" << std::endl;
    }
}

// Constructors
ConsoleLogger::ConsoleLogger(std::ostream &dest, LogLevel logLevel = ERROR): destination(dest) {
    this->logLevel = logLevel;
}

FileLogger::FileLogger(std::ofstream &destination, LogLevel logLevel) : destination(destination) {
    this->logLevel = logLevel;
}
