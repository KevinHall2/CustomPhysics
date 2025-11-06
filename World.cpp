#include "World.h"
#include "raylib.h"

World::World() : AccumulatedFixedTime(0), TargetFixedStep(1.0f / 30.0f)
{
}

void World::Init()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    OnInit();
}

void World::Tick()
{
    AccumulatedFixedTime += GetFrameTime();

    OnTick();
}

void World::TickFixed()
{
    AccumulatedFixedTime -= TargetFixedStep;

    for (auto& physicsObjectOne : PhysObjects)
    {
        physicsObjectOne.physicsEnabled = true;
        if (physicsObjectOne.physicsEnabled)
        {
            physicsObjectOne.AddAcceleration({ 0,10 });
            physicsObjectOne.ContinuousTick(TargetFixedStep);
        }
    }

    OnTickFixed();
}

void World::Draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    for (auto& physicsObjectOne : PhysObjects)
    {
        physicsObjectOne.DrawPhysicsCircle();
    }

    EndDrawing();

    OnDraw();
}

void World::Exit()
{
    OnExit();

    CloseWindow();        // Close window and OpenGL context
}

bool World::ShouldClose() const
{
	return WindowShouldClose();
}

bool World::ShouldTickFixed() const
{
    return AccumulatedFixedTime >= TargetFixedStep;
}

//Runs at the end of Init()

inline void World::OnInit() 
{
    PhysObject newObject;
    newObject.Collider.Type = ShapeType::CIRCLE;
    newObject.Collider.CircleData.Radius = 10.0f;
    newObject.Position = { 100, 100 };
    PhysObjects.push_back(newObject);

    newObject.Position = { 500, 200 };
    PhysObjects.push_back(newObject);

    newObject.Position = { 300, 150 };
    PhysObjects.push_back(newObject);
}
