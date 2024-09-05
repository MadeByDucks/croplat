#pragma once


#include <string>
#include <map>

class ConfigReader {
public:
    // Constructor to load config file
    ConfigReader(const std::string& filename);

    // Method to get a value by key
    std::string get(const std::string& key) const;

    // Method to check if a key exists
    bool contains(const std::string& key) const;

private:
    std::map<std::string, std::string> configMap;

    // Helper method to trim whitespace
    std::string trim(const std::string& str) const;

    // Method to load the config file
    void loadConfigFile(const std::string& filename);
};


