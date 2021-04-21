#ifndef APP_HPP
#define APP_HPP

#include <SDL2/SDL.h>

class App
{
private:
    bool isRunning;
    static SDL_Renderer renderer;
public:
    void run();
    void pause();
    void sleep(Uint32 miliseconds);
    ~App();
private:
    void gameLoop();
};

#endif 