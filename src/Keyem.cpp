#include "keyem.h"
#include <iostream>
#include <chrono>
#include <thread>

#ifdef _WIN32
    #include <Windows.h>
#elif __linux__
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
#elif __APPLE__
    #include <ApplicationServices/ApplicationServices.h>
#endif

//#include "WinInfoUtil.h"
//#include "WinInput.h"
//#include "dpUtilLog.h"


KeyEm::KeyEm()
{
}

KeyEm::~KeyEm()
{
}


///////////////////////////////////////////////////////////////////////////////
// mouse //////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


bool KeyEm::getMousePos(int &x, int &y)
{
    bool found = false;
#ifdef _WIN32
    POINT p;
    if (!(GetAsyncKeyState(VK_ESCAPE)))
    {
        if (GetCursorPos(&p))
        {
            x = p.x;
            y = p.y;
            found = true;
        }
    }
#endif
    return found;
}


bool KeyEm::setMousePos(int x, int y)
{
#ifdef _WIN32
    return SetCursorPos(x, y);
#elif __linux__
    //////////////////////////////////////////////////g++ your_program.cpp -o your_program -lX11
    Display* display = XOpenDisplay(NULL);
    if (display == NULL) {
        // Handle error
        return false;
    }

    Window root = DefaultRootWindow(display);
    XWarpPointer(display, None, root, 0, 0, 0, 0, x, y);
    XFlush(display);
    XCloseDisplay(display);

    return true;
#elif __APPLE__
    ////////////////////////////////////////////////////g++ your_program.cpp -o your_program -framework ApplicationServices
    CGEventRef moveEvent = CGEventCreateMouseEvent(NULL, kCGEventMouseMoved, CGPointMake(x, y), kCGMouseButtonLeft);
    CGEventPost(kCGHIDEventTap, moveEvent);
    CFRelease(moveEvent);
    return true;
#endif
}


void KeyEm::mousePosLocator()
{
    int x;
    int y;

    while (getMousePos(x, y))
    {
        std::cout << x << "   " << y << "\n";
    }
//#ifdef _WIN32
//    POINT p;
//    while (!(GetAsyncKeyState(VK_ESCAPE)))
//    {
//        if (GetCursorPos(&p))
//        {
//            if (GetCursorPos(&p))
//            {
//                std::cout << p.x << "   " << p.y << "\n";
//            }
//        }
//    }
//#endif
}

void KeyEm::DoubleClick(int x, int y)
{
#ifdef _WIN32
    const double XSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CXSCREEN) - 1);
    const double YSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CYSCREEN) - 1);

    POINT cursorPos;
    GetCursorPos(&cursorPos);

    double cx = cursorPos.x * XSCALEFACTOR;
    double cy = cursorPos.y * YSCALEFACTOR;

    double nx = x * XSCALEFACTOR;
    double ny = y * YSCALEFACTOR;

    INPUT Input = { 0 };
    Input.type = INPUT_MOUSE;

    Input.mi.dx = (LONG)nx;
    Input.mi.dy = (LONG)ny;

    Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;

    SendInput(1, &Input, sizeof(INPUT));
    SendInput(1, &Input, sizeof(INPUT));

    Input.mi.dx = (LONG)cx;
    Input.mi.dy = (LONG)cy;

    Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

    SendInput(1, &Input, sizeof(INPUT));
#endif
}


void KeyEm::SingleClick(int x, int y)
{
#ifdef _WIN32
    const double XSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CXSCREEN) - 1);
    const double YSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CYSCREEN) - 1);

    POINT cursorPos;
    GetCursorPos(&cursorPos);

    double cx = cursorPos.x * XSCALEFACTOR;
    double cy = cursorPos.y * YSCALEFACTOR;

    double nx = x * XSCALEFACTOR;
    double ny = y * YSCALEFACTOR;

    INPUT Input = { 0 };
    Input.type = INPUT_MOUSE;

    Input.mi.dx = (LONG)nx;
    Input.mi.dy = (LONG)ny;

    Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;

    SendInput(1, &Input, sizeof(INPUT));

    Input.mi.dx = (LONG)cx;
    Input.mi.dy = (LONG)cy;

    Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

    SendInput(1, &Input, sizeof(INPUT));
#endif
}


///////////////////////////////////////////////////////////////////////////////
// keyboard ///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void KeyEm::keyboardInputVirtualKeyDesktop(int vk)
{
#ifdef _WIN32
    INPUT ip;

    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; //hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ip.ki.wVk = vk;//https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
#endif
}

void KeyEm::keyboardInputCharDesktop(char sendChar)
{
#ifdef _WIN32
    bool isShift = false;
    if (((sendChar >= 'A') && (sendChar <= 'Z')) || (sendChar == '*'))
    {
        isShift = true;
    }

    INPUT input = { 0 };

    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0; //hardware scan code for key
    input.ki.time = 0;
    input.ki.dwExtraInfo = GetMessageExtraInfo();

    //shift down    
    if (isShift)
    {
        input.ki.wVk = VK_SHIFT;
        input.ki.dwFlags = 0; // 0 for key press
        SendInput(1, &input, sizeof(INPUT));
    }

    //char down
    input.ki.wVk = VkKeyScanEx(sendChar, GetKeyboardLayout(0));
    input.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &input, sizeof(INPUT));

    //char up
    input.ki.wVk = VkKeyScanEx(sendChar, GetKeyboardLayout(0));
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));

    //shift up
    if (isShift)
    {
        input.ki.wVk = VK_SHIFT;
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));
    }
#endif
}

void KeyEm::keyboardInputStringDesktop(std::string sendStr)
{
    for (int i = 0; i < sendStr.length(); i++)
    {
        keyboardInputCharDesktop(sendStr[i]);
    }
}


//int KeyEm::main(int argc, char* argv[])
//{
//    /*
//    int x = 200;
//    int y = 200;
//
//    std::this_thread::sleep_for(std::chrono::milliseconds(30000));
//
//    DoubleClick(100, 100);
//
//    //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
//    //keyboardInputVirtualKeyDesktop(VK_UP);
//    //keyboardInputStringDesktop("Yoda yoda yooodle\n");
//
//    //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
//    //keyboardInputVirtualKeyDesktop(VK_UP);
//    //keyboardInputStringDesktop("booskksk gioosk \n");
//
//    for (int i = 0; i < 15; i++)
//    {
//        //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
//        //std::cout << "move mouse x, y\n";
//        //SetCursorPos(x, y);
//
//        //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//        //keyboardInputVirtualKeyDesktop(VK_UP);
//        //keyboardInputStringDesktop("2030\n");
//
//        x += 10;
//        y += 10;
//    }
//    */
//
//    return 0;
//}
