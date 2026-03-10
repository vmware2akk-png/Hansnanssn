#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <cmath>

const int MAX_DOTS = 1000;

struct Dot {
    float x, y, vx, vy;
    bool active;
};

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init(); // Инициализация шрифтов

    SDL_DisplayMode dm;
    SDL_GetCurrentDisplayMode(0, &dm);
    int W = dm.w, H = dm.h;
    int UI_W = W * 0.25;

    SDL_Window* win = SDL_CreateWindow("Space Pro", 0, 0, W, H, SDL_WINDOW_FULLSCREEN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    // ЗАГРУЗКА ШРИФТА (Стандартный путь для Android)
    TTF_Font* font = TTF_OpenFont("/system/fonts/Roboto-Regular.ttf", 64);
    if (!font) {
        // Если Roboto не нашелся, попробуем другой (на всякий случай)
        font = TTF_OpenFont("/system/fonts/DroidSans.ttf", 64);
    }

    auto renderText = [&](const char* text, int x, int y) {
        if (!font) return;
        SDL_Color white = {255, 255, 255, 255};
        SDL_Surface* surf = TTF_RenderText_Blended(font, text, white);
        SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surf);
        SDL_Rect dst = { x, y, surf->w, surf->h };
        // Центрируем текст по кнопке немного
        dst.x = (UI_W - surf->w) / 2;
        SDL_RenderCopy(ren, tex, NULL, &dst);
        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
    };

    std::vector<Dot> dots(MAX_DOTS);
    int tool = 0; // 0: Star, 1: Hole
    bool running = true;
    SDL_Event ev;

    while (running) {
        int mx, my;
        uint32_t mState = SDL_GetMouseState(&mx, &my);

        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) running = false;
            if (ev.type == SDL_MOUSEBUTTONDOWN) {
                if (mx < UI_W) {
                    if (my < H / 3) tool = 0;
                    else if (my < (H / 3) * 2) tool = 1;
                    else { for (auto& d : dots) d.active = false; }
                } else if (tool == 0) {
                    for (auto& d : dots) if (!d.active) {
                        d.x = mx; d.y = my; d.vx = rand() % 10 - 5; d.vy = rand() % 10 - 5;
                        d.active = true; break;
                    }
                }
            }
        }

        // Логика частиц
        for (auto& d : dots) {
            if (!d.active) continue;
            if ((mState & SDL_BUTTON(1)) && mx > UI_W && tool == 1) {
                float dx = mx - d.x, dy = my - d.y;
                float dist = sqrt(dx * dx + dy * dy) + 1;
                d.vx += dx / dist * 0.8f; d.vy += dy / dist * 0.8f;
            }
            d.x += d.vx; d.y += d.vy;
            if (d.x < UI_W || d.x > W) d.vx *= -1;
            if (d.y < 0 || d.y > H) d.vy *= -1;
        }

        SDL_SetRenderDrawColor(ren, 15, 15, 25, 255);
        SDL_RenderClear(ren);

        // UI
        SDL_SetRenderDrawColor(ren, 35, 35, 45, 255);
        SDL_Rect uiRect = { 0, 0, UI_W, H };
        SDL_RenderFillRect(ren, &uiRect);

        // Кнопки и ТЕКСТ
        renderText("ЗВЕЗДА", 0, H / 6 - 30);
        renderText("ДЫРА", 0, H / 2 - 30);
        renderText("СБРОС", 0, (H / 6) * 5 - 30);

        // Звезды
        SDL_SetRenderDrawColor(ren, 255, 255, 150, 255);
        for (auto& d : dots) if (d.active) {
            SDL_Rect r = { (int)d.x, (int)d.y, 6, 6 };
            SDL_RenderFillRect(ren, &r);
        }

        SDL_RenderPresent(ren);
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
