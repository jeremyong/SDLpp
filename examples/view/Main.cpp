#include <SDLpp.h>

int main(int argc, char *argv[]) {
    sdl::Init();
    sdl::Window window{"View Example", 800, 600};
    sdl::Renderer *renderer = window.CreateRenderer();

    sdl::Texture *tex = renderer->CreateTexture("../examples/view/Character Horn Girl.png");
    sdl::Sprite sprite(*tex);

    // Construct a view
    sdl::View view{sdl::Vector2f{0.f, 0.f}, sdl::Vector2f{800.f, 600.f}};

    renderer->SetView(view);
    renderer->Clear();
    renderer->Draw(sprite);
    renderer->Present();
    SDL_Delay(2000);

    // Shift the view 100px to the left and redraw
    view.Move(sdl::Vector2f{-100.f, 0.f});
    renderer->SetView(view);
    renderer->Clear();
    renderer->Draw(sprite);
    renderer->Present();
    SDL_Delay(2000);
    return 0;
}
