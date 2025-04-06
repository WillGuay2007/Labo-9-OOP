#include <vector>
#include "entrypoint.h"
#include <raylib.h>

#define WIDTH 780
#define HEIGHT 420

class GameObject {
    protected:
    float x;
    float y;
    float width;
    float height;
    Color color;

    public:
    GameObject(float _x = 0, float _y = 0, float _width = 0, float _height = 0, Color _color = WHITE) 
    : x(_x), y(_y), width(_width), height(_height), color(_color) {};
    virtual void Draw() = 0;
    virtual void Update(float dt) = 0;
};

class game {
    protected:
    void AddGameObject(GameObject* obj);
    private:

    void DrawObjects();
    void UpdateObjects();
    std::vector<GameObject*> gameObjects;
    public:

    void Run();
};

class Circle : public GameObject {
    private:
    float radius;
    float dirX = 1;
    float dirY = 1;
    public:
    Circle(float x, float y, float radius, Color color = RED) 
    : GameObject(x, y, radius, radius, color), radius(radius) {
        int randX = GetRandomValue(0, 100);
        int randY = GetRandomValue(0, 100);
        
        dirX = (randX < 50) ? 1 : -1;
        dirY = (randY < 50) ? 1 : -1;
    };
    void Draw() override;
    void Update(float dt) override;
};

class line : public GameObject {
    private:
    float x2; float y2;
    public:
    line(float x1, float _x2, float y1, float _y2, Color color = RED) : GameObject(x1, y1, 0, 0, color), x2(_x2), y2(_y2) {};
    void Draw() override;
    void Update(float dt) override;
};

class rect : public GameObject {
    public:
    rect(float _x, float _y, float _width, float _height, Color color = RED) : GameObject(_x, _y, _width, _height, color) {};
    void Draw() override;
    void Update(float dt) override;
};

class MyGame : public game {
public:
    MyGame() {}

    void AddObject(GameObject* obj) {
        AddGameObject(obj);
    }
    
};