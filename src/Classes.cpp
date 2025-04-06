#include "Classes.h"

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
    
}

