//
// Created by issbe on 17/08/2025.
//
#pragma once

#ifndef LOGGER_H
#define LOGGER_H
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

enum LOG_LEVEL {
    DEBUG,
    INFO,
    ERROR,
    WARNING
};

std::string GetLogLevelString(LOG_LEVEL level);

class Logger {
private:
    std::ofstream file;
    std::vector<std::string> logs;
public:
    Logger(const char* filename);
    ~Logger();

    std::vector<std::string> GetLogs() const {return logs;}

    template<typename... Args>
    void Log(LOG_LEVEL level, const std::string& logMessage, Args&&... args) {
        time_t timestamp;
        time(&timestamp);

        std::stringstream sstream;
        std::string timestr = ctime(&timestamp);
        timestr.pop_back();
        sstream << GetLogLevelString(level) << " - [" << timestr << "] - " << logMessage;
        ((sstream << args), ...);
        sstream << std::endl;

        std::cout << sstream.str();
        logs.emplace_back(sstream.str());
        if (file.is_open()) {
            file << sstream.str();
            // file.flush();
        }

    }
};

#endif //LOGGER_H