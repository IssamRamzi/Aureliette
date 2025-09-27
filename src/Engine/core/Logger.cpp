#include "Logger.h"

#include <iostream>
#include <sstream>

Logger::Logger(const char *filename) {
    file.open(filename, std::ios_base::app);
}

Logger::~Logger() {
    file.close();
}

std::string GetLogLevelString(LOG_LEVEL level) {
    switch (level) {
        case INFO:
            return "[INFO]";
        case WARNING:
            return "[WARNING]";
        case DEBUG:
            return "[DEBUG]";
        case ERROR:
            return "[ERROR]";
    }
    return "[DEFAULT]";
}