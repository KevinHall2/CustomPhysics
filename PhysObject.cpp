#include "PhysObject.h"
#include "raylib-cpp.hpp"

PhysObject::PhysObject() : Position({ 0,0 }), Velocity({ 0,0 }), PendingAcceleration({ 0,0 })
{
}

void PhysObject::ContinuousTick(float Delta)
{
	Velocity += PendingAcceleration * Delta;
	PendingAcceleration = {};
	Position += Velocity * Delta;
}

void PhysObject::InstantaneousTick(float Delta)
{
	Position += Velocity * Delta;
}

void PhysObject::DrawPhysicsCircleOne() const
{
	DrawCircle(Position.x, Position.y, 30, raylib::Color::Red());
}

void PhysObject::DrawPhysicsCircleTwo() const
{
	DrawCircle(Position.x+75, Position.y+75, 30, raylib::Color::Blue());
}

//Applies continuous forces on objects of any mass equally like gravity
void PhysObject::AddAcceleration(const glm::vec2& Acceleration)
{
	PendingAcceleration += Acceleration;
}

//Applies instantaneous forces on objects of any mass equally to emulate platform movement
void PhysObject::AddVelocity(const glm::vec2& velocity)
{
	Velocity += velocity;
}

//Applies continuous forces that consider objects' mass
void PhysObject::AddForce(const glm::vec2& Force)
{
	PendingAcceleration += Force / Mass;
}

//Applies instantaneous forces that consider objects' mass
void PhysObject::AddImpulses(const glm::vec2& Impulse)
{
	Velocity += Impulse / Mass;
}
