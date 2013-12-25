#include <SDLpp.h>

int main() {
    sdl::Init();

    // Makes a full screen window with desktop resolution
    //sdl::Window window{"Test window"};

    // Makes a centered 800x600 window
    sdl::Window window{"Test window", 800, 600};

    // Create a renderer attached to the window and retrieve a pointer to it
    sdl::Renderer *renderer = window.CreateRenderer();

    // Clear the screen black (default color)
    renderer->Clear();

    // Display it
    renderer->Present();

    // 2 second pause
    SDL_Delay(2000);

    // No need to call SDL_Quit, this is done automatically from sdl::Init()
}
