#include <SDLpp.h>

int main(int argc, char *argv[]) {
    sdl::Init();
    sdl::Window window{"Test window", 800, 600};
    sdl::Renderer *renderer = window.CreateRenderer();
    renderer->Clear();

    sdl::Texture *tex = renderer->CreateTexture("../examples/sprite/Character Cat Girl.png");

    // Create a sprite from a texture modulated green
    sdl::Sprite green_sprite(*tex);
    green_sprite.SetColor(sdl::Colors::Green);

    // Create a sprite that is alpha modulated
    sdl::Sprite transparent_sprite(*tex);
    transparent_sprite.SetColor(sdl::Color{255, 255, 255, 100});
    transparent_sprite.Move(sdl::Vector2f{200, 0});

    // Create a sprite that isn't color modulated
    sdl::Sprite sprite(*tex);
    sprite.Move(sdl::Vector2f{400, 0});

    // Draw all sprites
    renderer->Draw(green_sprite);
    renderer->Draw(transparent_sprite);
    renderer->Draw(sprite);

    renderer->Present();
    SDL_Delay(2000);
    return 0;
}
