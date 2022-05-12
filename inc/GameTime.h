#pragma once
#include <SDL.h>

class GameTime
{
private:
	double _deltaTime;
	Uint64 _time;

	GameTime() : _deltaTime(0), _time(0)
	{

	}

	GameTime(GameTime const&) = delete;
	void operator=(GameTime const&) = delete;
public:
	static GameTime& GetInstance()
	{
		static GameTime instance;
		return instance;
	}
	
	double GetDeltaTime()
	{
		return _deltaTime;
	}

	Uint64 GetTime()
	{
		return _time;
	}

	void Update()
	{
		//Uint64 currentTime = SDL_GetPerformanceCounter();
		//_deltaTime = (double)((currentTime - _time) / (double) SDL_GetPerformanceFrequency());

		Uint64 currentTime = SDL_GetTicks64();
		_deltaTime = (double)((currentTime - _time) * 0.001);

		_time = currentTime;
	}
};
