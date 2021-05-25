#ifndef APP_HPP
#define APP_HPP

#include <SDL.h>
#include "Window.hpp"
#include "Paddle.hpp"

class App
{
private:
    bool isRunning;
    WindowWithBackground gameWindow;
    SDL_Event event;

    Paddle leftPaddle;
    Paddle rightPaddle;
public:
    App();
    void run();
    void pause();
    void sleep(Uint32 miliseconds);
    ~App();
private:
    void gameLoop();
    void update(const double delta_time);
    void draw();
};

#endif 