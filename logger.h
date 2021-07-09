//
// Created by Никита Рыданов on 09/07/2021.
//

#pragma once

#include <fstream>

class Logger {
public:
    enum LogLevel {
        ERROR,
        WARNING,
        INFO
    };
    virtual void error(const std::string &errorMessage) = 0;
    virtual void warning(const std::string &warningMessage) = 0;
    virtual void info(const std::string &infoMessage) = 0;
protected:
    LogLevel logLevel = ERROR;
};

class FileLogger : Logger {
public:
    void error(const std::string &errorMessage) override;
    void warning(const std::string &warningMessage) override;
    void info(const std::string &infoMessage) override;
    explicit FileLogger(std::ofstream& destination, LogLevel logLevel);

private:
    std::ofstream &destination;
};

class ConsoleLogger : Logger {
public:
    void error(const std::string &errorMessage) override;
    void warning(const std::string &warningMessage) override;
    void info(const std::string &infoMessage) override;
    explicit ConsoleLogger(std::ostream& destination, LogLevel logLevel);
private:
    std::ostream &destination;
};

