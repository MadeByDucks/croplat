#pragma once
#include <string>

class KeyEm
{
public:
    KeyEm();
    ~KeyEm();
    bool getMousePos(int& x, int& y);
    bool setMousePos(int x, int y);
    void mousePosLocator();
    void DoubleClick(int x, int y);
    void SingleClick(int x, int y);
    void keyboardInputVirtualKeyDesktop(int vk);
    void keyboardInputCharDesktop(char sendChar);
    void keyboardInputStringDesktop(std::string sendStr);
    //int main(int argc, char* argv[]);
};

