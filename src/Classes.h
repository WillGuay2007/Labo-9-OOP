#include <vector>
#include "entrypoint.h"
#include <raylib.h>

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
    public:
    Circle(float x, float y, float radius, Color color = RED) 
    : GameObject(x, y, radius, radius, color), radius(radius) {};
    void Draw() override;
    void Update(float dt) override;
};

class MyGame : public game {
public:
    MyGame() {
        AddGameObject(new Circle(200, 200, 30, RED));
        AddGameObject(new Circle(300, 200, 50, BLUE));
    }
};