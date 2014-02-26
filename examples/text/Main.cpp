#include <SDLpp.h>
#include <string>

int main(int argc, char *argv[]) {
    sdl::Init();

    sdl::Window window{"Test window", 800, 600};
    sdl::Renderer *renderer = window.CreateRenderer();

    // Loads a font with 14 pt size, ttf and otf supported
    sdl::Font font("../examples/text/SCPR.otf", 14);

    // Create a text object
    sdl::Text text(font, "Hello, World!", sdl::Colors::Green);

    renderer->Clear();

    // Draw text object to the screen (default position is at the origin)
    renderer->Draw(text);

    renderer->Present();
    SDL_Delay(2000);
    return 0;
}
