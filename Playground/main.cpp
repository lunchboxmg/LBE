#include <LbeCore.hpp>

#include <iostream>
#include <bitset>

int main()
{
    std::cout << "LOADING PLAYGROUND ..." << std::endl;

    LBE::Application* app = new LBE::Application();
    int result = app->Initialize(640, 480, "PLAYGROUND Test Application");
    std::cout << "\tAPPLICATION INITIALIZED = " << result << std::endl;

    app->Start();
    LBE::KeyState esc = app->GetKeyboard().GetKeyState(GLFW_KEY_ESCAPE);
    std::cout << "[ESC] KEY STATE :" << std::endl;
    std::cout << "  state = " << std::bitset<8>(esc.state) << std::endl;
    std::cout << "  mods  = " << std::bitset<32>(esc.mods) << std::endl;
    delete app;

    return 1;
}