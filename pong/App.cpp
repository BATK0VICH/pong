#include "App.hpp"
#include "Initialization.hpp"
#include "Window.hpp"
#include "Menu.hpp"

App::App() :
    isRunning(false), gameWindow("CyberPong", 1280, 720, "WHITE"), 
    event(), leftPaddle(0, (400 / 2) - 50, Type::LEFT),
    rightPaddle(400 - 50, (400 / 2) - 50, Type::RIGHT)
{
}

void App::run()
{
    isRunning = true;
    gameLoop();
}

void App::gameLoop()
{
    while (isRunning)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            { 
            case SDL_QUIT:
                isRunning = false;
            }
            leftPaddle.handle_input(event);
            rightPaddle.handle_input(event);
        }
        this->update(1.0 / 60.0);
        this->draw();
    }
}

void App::update(const double delta_time)
{
    leftPaddle.update(delta_time);
    rightPaddle.update(delta_time);
}

void App::draw()
{
    SDL_RenderClear(gameWindow.renderer);
    leftPaddle.draw(gameWindow.renderer);
    rightPaddle.draw(gameWindow.renderer);
    SDL_RenderPresent(gameWindow.renderer);
}

void App::pause()
{

}

void App::sleep(Uint32 miliseconds)
{
    SDL_Delay(miliseconds);
}

App::~App()
{
    SDL_Quit();
}