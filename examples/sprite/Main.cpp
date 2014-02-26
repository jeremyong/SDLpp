#include <SDLpp.h>

int main(int argc, char *argv[]) {
    sdl::Init();
    sdl::Window window{"Sprite Example", 800, 600};
    sdl::Renderer *renderer = window.CreateRenderer();
    renderer->Clear();

    // Load texture from image and grab it's pointer
    sdl::Texture *tex = renderer->CreateTexture("../examples/sprite/Character Cat Girl.png");

    // Create a sprite from a texture
    sdl::Sprite sprite(*tex);

    // Draw the sprite
    renderer->Draw(sprite);

    renderer->Present();
    SDL_Delay(2000);
    return 0;
}
