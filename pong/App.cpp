#include "App.hpp"
#include "Initialization.hpp"
#include "Window.hpp"

void App::run()
{
    initializeEverything();
    isRunning = false;
    WindowWithBackground window("CyberPong", 1280, 720, "PURPLE");
    sleep(1000);
    
    sleep(1000);

    gameLoop();
}

void App::gameLoop()
{
    while(isRunning)
    {

    }
}

void App::pause()
{

}

void App::sleep(Uint32 miliseconds)
{
    SDL_Delay(miliseconds);
}

void App::~App()
{
    SDL_Quit();
}