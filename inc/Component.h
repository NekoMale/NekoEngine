#pragma once
class Entity; // Forward declaration

class Component
{
private:
	Entity* _myEntity;

public:
	Component(Entity* entity) : _myEntity(entity)
	{
	}

	virtual ~Component() = default;

	Entity& GetEntity()
	{
		return *_myEntity;
	}
};