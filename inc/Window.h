#pragma once
#include <SDL.h>
#include <iostream>
#include "Input.h"
#include "Color.h"

class Window
{
private:
	bool _isActive;

	SDL_Window* _window;
	SDL_Renderer* _renderer;

	Window()
	{
		_isActive = true;
		_window = SDL_CreateWindow("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		Input::GetInstance().OnQuitPress.AddSubscriber(std::bind(&Window::Close, this));
	}
public:
	Window(Window const&) = delete;
	void operator=(Window const&) = delete;

	void SetWindowSize(int width, int height)
	{
		SDL_SetWindowSize(_window, width, height);
	}

	static Window& GetInstance()
	{
		static Window instance;
		return instance;
	}

	void Update()
	{
		//SDL_SetRenderDrawColor(_renderer, 1, 1, 1, 0);
		//SDL_RenderClear(_renderer);

		SDL_RenderPresent(_renderer);
	}

	void DrawRect(Color color, int x, int y, int width, int height)
	{
		SDL_Rect rect = SDL_Rect();
		rect.w = width;
		rect.h = height;
		rect.x = x;
		rect.y = y;

		SDL_SetRenderDrawColor(_renderer, color.GetR(), color.GetG(), color.GetB(), color.GetA());
		SDL_RenderFillRect(_renderer, &rect);
	}

	bool GetIsActive()
	{
		return _isActive;
	}

	void SetTitle(std::string newTitle)
	{
		SDL_SetWindowTitle(_window, newTitle.c_str());
	}

	void Close()
	{
		_isActive = false;
	}
};