#pragma once
#include <typeindex>
#include <unordered_map>
#include <vector>
#include <iostream>
#include "Component.h"
#include "Transform.h"

class Entity
{
private:
	std::unordered_map<std::type_index, std::vector<Component*>> _components;
	Transform* _transform;

public:
	Entity()
	{
		_transform = AddComponent<Transform>();
	}

	Transform& GetTransform()
	{
		return *_transform;
	}

	template<class T>
	typename std::enable_if<std::is_base_of<Component, T>::value, T*>::type AddComponent()
	{
		T* newComponent = new T(this);
		std::type_index insertingType = typeid(T);
		if (_components.find(insertingType) == _components.end())
		{
			_components.insert({ insertingType, std::vector<Component*>() });
		}
		_components[insertingType].push_back(newComponent);
		return newComponent;
	}

	template<typename T>
	typename std::enable_if<std::is_base_of<Component, T>::value, T*>::type GetComponent()
	{
		return static_cast<T*>(_components[typeid(T)].at(0));
	}
};