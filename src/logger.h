#pragma once



#include <fstream>
#include <mutex>
#include <memory>
#include <string>

class Logger 
{
private:
    static std::unique_ptr<Logger> instance;  // Unique instance of the Logger class
    static std::mutex mtx;  // Mutex for thread safety
    std::ofstream logFile;  // Output file stream for logging

    // Private constructor to prevent instantiation from outside
    Logger();

    // Delete copy constructor and assignment operator to prevent copying
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    // Static method to get the singleton instance
    static Logger* getInstance();

    // Method to log a message to the file
    void log(const std::string& message);

    // Destructor to close the log file
    ~Logger();
};




/*

#pragma once

#pragma warning( push )
#pragma warning(disable:4996) //_CRT_SECURE_NO_WARNINGS



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


#include <fstream>
#include <string>
#include <sstream>

#define LOG_ERROR( Function, MSG ) LOG_MSG( "Error",Function, MSG )
#define LOG_WARN( Function,MSG ) LOG_MSG( "Warnning",Function, MSG )
#define LOG_INFO( Function,MSG ) LOG_MSG( "Info",Function, MSG )
#define LOG_DEBUG( Function,MSG ) LOG_MSG( "Debug",Function, MSG )

#define LOG_MSG( Type,Function, MSG ) \
{ \
    std::stringstream ss; \
    ss<< Type << "-" << #Function << " : " << MSG << std::endl; \
    std::string temp = ss.str(); \
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




class dpUtilLog
{
public:
    dpUtilLog();
    ~dpUtilLog();

    static void PressEnterToContinue();
    static void outputMessageBox( std::string mesg );
    static void outputProgress( std::string mesg );
    static void outputProgressLine(std::string mesg);
    static void outputErrorMessageAndPause( std::string mesg );
};


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////





//https://stackoverflow.com/questions/1149620/how-to-write-to-the-output-window-in-visual-studio

//void CClass::Output(const char* szFormat, ...)
//{
//    char szBuff[1024];
//    va_list arg;
//    va_start(arg, szFormat);
//    _vsnprintf(szBuff, sizeof(szBuff), szFormat, arg);
//    va_end(arg);
//
//    OutputDebugString(szBuff);
//}


////////////////////////////////////////////////////////////////////////
//
//
//#define DBOUT( s )            \
//{                             \
//   std::ostringstream os_;    \
//   os_ << s;                   \
//   OutputDebugString( os_.str().c_str() );  \
//}
//This allows you to say things like :
//
//DBOUT("The value of x is " << x);
//
//
//////////////////////////////////////////////////////////////////////
//
//#include <Windows.h>
//#include <iostream>
//#include <sstream>
//
//#define DBOUT( s )            \
//{                             \
//   std::wostringstream os_;    \
//   os_ << s;                   \
//   OutputDebugStringW( os_.str().c_str() );  \
//}









#include <iostream>
#include <fstream>
#include <string>
#include <ctime>




class Logger {
public:
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::app);
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void log(const std::string& message) {
        if (logFile.is_open()) {
            // Get the current timestamp
            std::time_t now = std::time(0);
            std::tm* localTime = std::localtime(&now);
            char timestamp[20];
            strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localTime);

            // Write the log message with a timestamp to the file
            logFile << "[" << timestamp << "] " << message << std::endl;
        }
    }

private:
    std::ofstream logFile;
};

//int main() {
//    // Create a Logger instance
//    Logger logger("log.txt");
//
//    // Log some messages
//    logger.log("This is a log message.");
//    logger.log("Another log message.");
//
//    return 0;
//}
*/








/*
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger {
public:
    static Logger& instance(const std::string& filename) {
        static Logger logger(filename);  // This ensures a single instance is created.
        return logger;
    }

    void log(const std::string& message) {
        if (logFile.is_open()) {
            // Get the current timestamp
            std::time_t now = std::time(0);
            std::tm* localTime = std::localtime(&now);
            char timestamp[20];
            strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localTime);

            // Write the log message with a timestamp to the file
            logFile << "[" << timestamp << "] " << message << std::endl;
        }
    }

private:
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::app);
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    std::ofstream logFile;
};

int main() {
    // Access the global static instance of Logger
    Logger::instance("log.txt").log("This is a log message.");
    Logger::instance("log.txt").log("Another log message.");

    return 0;
}
*/









