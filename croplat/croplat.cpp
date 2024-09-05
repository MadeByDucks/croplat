// croplat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "log.h"

const char* VERSION_STR = "Beta 0.1";

std::string buildGeneralUsage()
{
    std::string usage = "";
    usage += "Usage: coplat.exe \n";
    usage += "    /h           help/usage\n";
    usage += "    /help        help/usage\n";
    usage += "    /v /ver      version\n";
    usage += "    /log         logging test\n";
    usage += "\n";
    return usage;
}

void showUsage()
{
    std::string usage = buildGeneralUsage();
    std::cout << usage << std::endl;
}

void testLogging()
{
/*
//std::cout << "StressTester Version" << "\n";
//std::cout << "StressTester Version" << "\n";
//std::cout << "StressTester Version" << "\n";

// TRACE("TESTING TRACE");
 std::string tmp = "testind debug testind debug testind debug testind debug";

 std::wostringstream os_;
 os_ << tmp.c_str();
 OutputDebugStringW(os_.str().c_str());

 LOG_DEBUG(main, "TESTING LOGS: ");
 LOG_DEBUG(main, "TESTING LOGS: ");
 LOG_DEBUG(main, "TESTING LOGS: ");
 */


    Logger::getInstance()->log("This is a test log message.");
    Logger::getInstance()->log("Logging another message.");
    LOG_DEBUG(testLogging, "TESTING LOG_DEBUG");
}

void processParams(std::vector<std::string> &args, bool& abort)
{
    //process all from argc/argv
    //or process one from functions params
    for (int cmd = 0; cmd < args.size(); cmd++)
    {
        if ((args[cmd] == "/h") || (args[cmd] == "/help"))
        {
            showUsage();
            abort = true;
        }
        else if ((args[cmd] == "/v") || (args[cmd] == "/ver") || (args[cmd] == "/version"))
        {
            std::cout << "Version: " << VERSION_STR << std::endl;
            abort = true;
        }
        else if (args[cmd] == "/log")
        {
            testLogging();
        }
    }
}

int main(int argc, char* argv[])
{
    bool abort = false;
    std::vector<std::string> args(argv + 1, argv + argc);

    if (args.size() == 0)
    {
        showUsage();
        abort = true;
    }

    if (!abort)
    {
        processParams(args, abort);
    }
}
