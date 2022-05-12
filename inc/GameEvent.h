#pragma once
#include <functional>
#include <unordered_map>
#include <string>
#include <utility>

template<class ... T>
class GameEvent
{
private:
	std::unordered_map<std::string, std::function<void(T...)>> _subscribers;

public:
	GameEvent()
	{

	}

	~GameEvent()
	{
		_subscribers.clear();
	}

	void Notify(T... args)
	{
		for (const std::pair<std::string, std::function<void(T...)>>& pair : _subscribers)
		{
			pair.second(args...);
		}
	}

	void AddSubscriber(std::function<void(T...)> newSubscriber)
	{
		if (_subscribers.find(newSubscriber.target_type().name()) == _subscribers.end())
		{
			_subscribers.insert({ newSubscriber.target_type().name(), newSubscriber });
		}
	}

	void RemoveSubscriber(std::function<void(T...)> subscriberToRemove)
	{
		if (_subscribers.find(subscriberToRemove.target_type().name()) != _subscribers.end())
		{
			_subscribers.erase(subscriberToRemove.target_type().name());
		}
	}
};