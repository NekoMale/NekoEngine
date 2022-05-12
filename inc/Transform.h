#pragma once
#include "Component.h"
#include "Vector3.h"

class Transform : public Component
{
private:
	Vector3 _position;
	Vector3 _scale;

public:
	Transform(Entity* entity) : Component(entity)
	{

	}

	Vector3 GetPosition()
	{
		return _position;
	}

	void SetPosition(float x, float y, float z)
	{
		_position.SetX(x);
		_position.SetY(y);
		_position.SetZ(z);
	}

	void SetPosition(Vector3 newPosition)
	{
		_position = newPosition;
	}
};