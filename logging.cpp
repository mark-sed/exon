#include "logging.hpp"
#include <iostream>

void error(const std::string msg, int code) {
    std::cerr << "Error: " << msg << std::endl;
    exit(code);
}

void warning(const std::string msg) {
    std::cerr << "Warning: " << msg << std::endl;
}

BaseLogger::BaseLogger() : disable(false), log_everything(false), logging_level{0} {

}

BaseLogger::~BaseLogger() {
    for(auto s: streams){
        s->flush();
    }
}

Logger::Logger() : BaseLogger() {
    streams.push_back(&std::cerr);
}

Logger::~Logger() {
    
}

Logger &Logger::get() {
    static Logger instance;
    return instance;
}

void Logger::debug(unsigned level, const std::string &file_func, const std::string &message) {
    if (disable || level > logging_level) {
        return;
    }
    // Check if function has logging enabled
    if (!log_everything) {
        if(enabled.find(file_func) == enabled.end()){
            return;
        }
    }
    // Output log to all registered streams
    for (auto s: streams) {
        (*s) << std::boolalpha << file_func << ": " << message << std::endl;
    }
}
