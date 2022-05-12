#pragma once
#include <SDL.h>
#include <iostream>
#include <map>
#include "GameEvent.h"

typedef struct {
	bool LastState;
	bool CurrentState;
} KeyState;

class Input {
private:
	std::map<SDL_Keycode, KeyState> _keyStates;
	std::map<SDL_Keycode, std::vector<GameEvent<>*>> _keyBinds;

	Input() { }

	Input(Input const&) = delete;
	void operator=(Input const&) = delete;
public:
	static Input& GetInstance()
	{
		static Input instance;
		return instance;
	}

	void Initialize()
	{
		_keyStates = std::map<SDL_Keycode, KeyState>();
		_keyStates.insert({ SDLK_RIGHT, { false, false} });
		_keyStates.insert({ SDLK_LEFT, { false, false} });
		_keyStates.insert({ SDLK_DOWN, { false, false} });
		_keyStates.insert({ SDLK_UP, { false, false} });

		_keyBinds = std::map<SDL_Keycode, std::vector<GameEvent<>*>>();
		_keyBinds.insert({ SDLK_RIGHT, { &OnRightKeyPress, &OnRightKeyReleased } });
		_keyBinds.insert({ SDLK_LEFT, { &OnLeftKeyPress, &OnLeftKeyReleased } });
		_keyBinds.insert({ SDLK_DOWN, { &OnDownKeyPress, &OnDownKeyReleased } });
		_keyBinds.insert({ SDLK_UP, { &OnUpKeyPress, &OnUpKeyReleased } });
	}

	void Update() {
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				OnQuitPress.Notify();
			}
			if (event.type == SDL_KEYDOWN)
			{
				if (_keyStates.find(event.key.keysym.sym) != _keyStates.end())
				{
					_keyStates[event.key.keysym.sym].CurrentState = true;
				}
			}
			if (event.type == SDL_KEYUP)
			{
				if (_keyStates.find(event.key.keysym.sym) != _keyStates.end())
				{
					_keyStates[event.key.keysym.sym].LastState = true;
					_keyStates[event.key.keysym.sym].CurrentState = false;
				}
			}
		}

		for (std::pair<SDL_Keycode, KeyState> pair : _keyStates)
		{
			if (pair.second.CurrentState)
			{
				_keyBinds[pair.first][0]->Notify();
			}
			else if (pair.second.LastState)
			{
				_keyStates[pair.first].LastState = false;
				_keyBinds[pair.first][1]->Notify();
			}
		}
	}

	GameEvent<> OnQuitPress = GameEvent<>();

	GameEvent<> OnLeftKeyPress = GameEvent<>();
	GameEvent<> OnRightKeyPress = GameEvent<>();
	GameEvent<> OnUpKeyPress = GameEvent<>();
	GameEvent<> OnDownKeyPress = GameEvent<>();

	GameEvent<> OnLeftKeyReleased = GameEvent<>();
	GameEvent<> OnRightKeyReleased = GameEvent<>();
	GameEvent<> OnUpKeyReleased = GameEvent<>();
	GameEvent<> OnDownKeyReleased = GameEvent<>();
};