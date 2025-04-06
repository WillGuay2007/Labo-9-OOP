#include "Classes.h"

void rect::Draw() {
    DrawRectangle(x, y, width, height, color);
}

void rect::Update(float dt) {
    // Pas de logique pour ici
}

void line::Draw()
{
    DrawLine(x, y, x2, y2, color);
}

void line::Update(float dt)
{
    // Pas de logique pour ici
}

void game::AddGameObject(GameObject *obj)
{
    gameObjects.push_back(obj);
}

void game::DrawObjects()
{
    for (int i = 0; i < gameObjects.size() ; i++) {
        gameObjects[i]->Draw();
    }
}

void game::UpdateObjects()
{
    for (int i = 0; i < gameObjects.size() ; i++) {
        gameObjects[i]->Update(GetFrameTime());
    }
}


void game::Run()
{
    UpdateObjects();
    DrawObjects();
}

void Circle::Draw()
{
    DrawCircle(x, y, radius, color);
}

void Circle::Update(float dt)
{
    x += WIDTH/4 * dt * dirX;
    y += HEIGHT/4 * dt * dirY;
    if ((x + radius) > WIDTH) {x = WIDTH - radius; dirX = -1;};
    if ((y + radius) > HEIGHT) {y = HEIGHT - radius; dirY = -1;};
    if ((x - radius) < 0) {x = 0 + radius; dirX = 1;};
    if ((y - radius) < 0) {y = 0 + radius; dirY = 1;};
}

