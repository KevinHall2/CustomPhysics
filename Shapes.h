#pragma once
#include <cstdint>
#include "glm/vec2.hpp"

struct Circle
{
	float Radius = 1.0f;
};

struct AABB
{
	//Represents 2 floats, or 4 bytes * 2, or 8 bytes total
	glm::vec2 HalfExtents;
};

enum class ShapeType : uint8_t
{
	NONE = 0,
	CIRCLE = 1 << 0,
	AABB = 1 << 1
};

struct Shape
{
	ShapeType Type;

	//Anonymous union that holds the data for the shape defined by this object
	//Access to its members aren't done via a name, but through directly referencing its members
	union
	{
		Circle CircleData;
		AABB AABBData;
	};
};