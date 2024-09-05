#include "ConfigReader.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>



/*

host=127.0.0.1
port=8080
username=admin
password=secret




#include <iostream>
#include "ConfigReader.h"

int main() {
    try {
        ConfigReader config("config.txt");
        std::string host = config.get("host");
        std::string port = config.get("port");
        
        std::cout << "Host: " << host << std::endl;
        std::cout << "Port: " << port << std::endl;

        if (config.contains("username")) {
            std::cout << "Username: " << config.get("username") << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


*/















ConfigReader::ConfigReader(const std::string& filename) {
    loadConfigFile(filename);
}

void ConfigReader::loadConfigFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open config file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines and comments
        }

        std::istringstream lineStream(line);
        std::string key;
        if (std::getline(lineStream, key, '=')) {
            std::string value;
            if (std::getline(lineStream, value)) {
                key = trim(key);
                value = trim(value);
                configMap[key] = value;
            }
        }
    }
    file.close();
}

std::string ConfigReader::get(const std::string& key) const {
    auto it = configMap.find(key);
    if (it != configMap.end()) {
        return it->second;
    } else {
        throw std::runtime_error("Key not found: " + key);
    }
}

bool ConfigReader::contains(const std::string& key) const {
    return configMap.find(key) != configMap.end();
}

std::string ConfigReader::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    if (first == std::string::npos || last == std::string::npos)
        return "";
    return str.substr(first, last - first + 1);
}
