#include <SDLpp.h>

int main() {
    sdl::Init();
    sdl::Window window{"Offscreen Drawing", 800, 600};
    sdl::Renderer *renderer = window.CreateRenderer();
    renderer->Clear();

    // Make a blank texture with dimensions 200x400
    sdl::Texture *tex = renderer->CreateTexture(200, 400);

    // Load boy image into another texture
    sdl::Texture *boy = renderer->CreateTexture(
        "../examples/offscreen_drawing/Character Boy.png");

    // Load the cat girl as well
    sdl::Texture *cat_girl = renderer->CreateTexture(
        "../examples/offscreen_drawing/Character Cat Girl.png");

    // Create a sprite from the boy and the girl
    sdl::Sprite boy_sprite(*boy);
    sdl::Sprite cat_girl_sprite(*cat_girl);

    // Move the cat girl 100 pixels to the right
    cat_girl_sprite.Move(sdl::Vector2f{100, 0});

    // Draw the two sprites onto the blank texture
    tex->Draw(boy_sprite);
    tex->Draw(cat_girl_sprite);

    // Make a sprite from the combination and draw it
    sdl::Sprite combo(*tex);
    renderer->Draw(combo);

    // Repeat but swap the positions of the boy and girl and move
    // the whole thing elsewhere on screen
    sdl::Texture *tex1 = renderer->CreateTexture(200, 400);
    cat_girl_sprite.Move(sdl::Vector2f{-100, 0});
    boy_sprite.Move(sdl::Vector2f{100, 0});
    tex1->Draw(boy_sprite);
    tex1->Draw(cat_girl_sprite);
    sdl::Sprite combo1(*tex1);
    combo1.Move(sdl::Vector2f{200, 300});
    renderer->Draw(combo1);

    renderer->Present();
    SDL_Delay(2000);
}
