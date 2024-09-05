#pragma warning( push )
#pragma warning(disable:4996) //_CRT_SECURE_NO_WARNINGS

#include "logger.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <ctime>

std::string LOGFILE = "D:\\projects\\log.txt";



////////std::cout << "StressTester Version" << "\n";
////////std::cout << "StressTester Version" << "\n";
////////std::cout << "StressTester Version" << "\n";
//////
//////// TRACE("TESTING TRACE");
////// std::string tmp = "testind debug testind debug testind debug testind debug";
//////
////// std::wostringstream os_;
////// os_ << tmp.c_str();
////// OutputDebugStringW(os_.str().c_str());
//////
////// LOG_DEBUG(main, "TESTING LOGS: ");
////// LOG_DEBUG(main, "TESTING LOGS: ");
////// LOG_DEBUG(main, "TESTING LOGS: ");



// Initialize static members
std::unique_ptr<Logger> Logger::instance = nullptr;
std::mutex Logger::mtx;

// Private constructor
Logger::Logger() 
{
    logFile.open(LOGFILE, std::ios::out | std::ios::app);  // Open the log file in append mode
    if (!logFile) 
    {
        throw std::runtime_error("Unable to open log file");
    }
}

// Static method to get the singleton instance
Logger* Logger::getInstance() 
{
    if (!instance) 
    {  // Double-checked locking
        std::lock_guard<std::mutex> lock(mtx);
        if (!instance) 
        {
            instance.reset(new Logger());
        }
    }
    return instance.get();
}

// Method to log a message to the file
void Logger::log(const std::string& message) 
{
    std::lock_guard<std::mutex> lock(mtx);  // Lock for thread safety
    if (logFile.is_open()) 
    {
        //std::time_t now = std::time(0);
        //std::tm* localTime = std::localtime(&now);
        //char timestamp[20];
        //strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localTime);


        std::time_t t = std::time(0);   // get time now
        std::tm* now = std::localtime(&t);
        std::string timestamp = std::to_string(now->tm_year + 1900) + '.' +
            std::to_string(now->tm_mon + 1) + '.' + std::to_string(now->tm_mday) + " - " +
            std::to_string(now->tm_hour ) + ':' + std::to_string(now->tm_min) + ":" +
            std::to_string(now->tm_sec );


        logFile << "[" << timestamp << "] "  << message << std::endl;
    }
}

// Destructor to close the log file
Logger::~Logger() 
{
    if (logFile.is_open()) 
    {
        logFile.close();
    }
}


/*
#include "dpUtilLog.h"
#include <stdio.h>
#include <iostream>
#include <string>

dpUtilLog::dpUtilLog()
{
}

dpUtilLog::~dpUtilLog()
{
}

void dpUtilLog::PressEnterToContinue()
{
    //std::cout << "Press ENTER to continue... " << std::flush;
    //std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    int c;
    printf("Press ENTER to continue... ");
    std::fflush(stdout);
    do c = getchar(); while ((c != '\n') && (c != EOF));
}

void dpUtilLog::outputMessageBox(std::string mesg)
{
    //puts("*********************************************************");
    //puts("*********************************************************");
    //puts(mesg.c_str());
    //puts("*********************************************************");
    //puts("*********************************************************");
    std::cout << "*********************************************************" << std::endl;
    std::cout << "*********************************************************" << std::endl;
    std::cout << mesg << std::endl;
    std::cout << "*********************************************************" << std::endl;
    std::cout << "*********************************************************" << std::endl;
}

void dpUtilLog::outputProgress(std::string mesg)
{
    //puts(mesg.c_str());
    std::cout << mesg;
}

void dpUtilLog::outputProgressLine(std::string mesg)
{
    //puts(mesg.c_str());
    std::cout << mesg << std::endl;
}

void dpUtilLog::outputErrorMessageAndPause(std::string mesg)
{
    //puts("*** ERROR *** ERROR *** ERROR *** ");
    //puts(mesg.c_str());
    std::cout << "*** ERROR *** ERROR *** ERROR *** " << std::endl;
    std::cout << mesg << std::endl;
    PressEnterToContinue();
}
*/

#pragma warning (pop)