#pragma once
#include <glm/vec2.hpp>

class PhysObject
{
public:
	//Known as Location in UE
	glm::vec2 Position;

	glm::vec2 Velocity;

	PhysObject();

	PhysObject AddForce(glm::vec2 force);

	void TickPhys(float Delta);
};