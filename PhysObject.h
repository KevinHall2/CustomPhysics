#pragma once
#include <glm/vec2.hpp>
#include "glm/glm.hpp"
#include "Shapes.h"

class PhysObject
{
public:
	//Known as Location in UE
	glm::vec2 Position;

	glm::vec2 Velocity;

	glm::vec2 PendingAcceleration;

	//Determines whether an object is effected by gravity or not
	bool physicsEnabled;

	float Mass = 1.0f;

	Shape Collider;

	PhysObject();

	void ContinuousTick(float Delta);
	void InstantaneousTick(float Delta);
	void DrawPhysicsCircle() const;

	//Applies continuous forces on objects of any mass equally like gravity
	void AddAcceleration(const glm::vec2 & Acceleration);

	//Applies instantaneous forces on objects of any mass equally to emulate platform movement
	void AddVelocity(const glm::vec2& Velocity);

	//Applies continuous forces that consider objects' mass
	void AddForce(const glm::vec2& Force);

	//Applies instantaneous forces that consider objects' mass
	void AddImpulses(const glm::vec2& Impulse);

	//Calculates an impulse to object A and B, assuming they're in collision
	float ResolveCollisions(const glm::vec2& PositionA, const glm::vec2& VelocityA, float MassA,
		const glm::vec2& PositionB, const glm::vec2& VelocityB, float MassB,
		float Elasticity, const glm::vec2& Normal);

	//Resolves a collision between two PhysObject instances
	void ResolvePhysObjects(PhysObject& LeftHandSide, PhysObject& RightHandSide, float Elasticity, const glm::vec2& Normal, float Penetration);
};