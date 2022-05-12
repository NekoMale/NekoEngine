#include <SDL.h>
#include <iostream>
#include "Input.h"
#include "Entity.h"
#include "GameTime.h"
#include "Window.h"

Entity _player;
double _moveSpeed = 30.;
void UpKeyPress()
{
	_player.GetTransform().SetPosition(_player.GetTransform().GetPosition() + Vector3(0, -1, 0) * _moveSpeed * GameTime::GetInstance().GetDeltaTime());
}

void DownKeyPress()
{
	_player.GetTransform().SetPosition(_player.GetTransform().GetPosition() + Vector3(0, 1, 0) * _moveSpeed * GameTime::GetInstance().GetDeltaTime());
}

void LeftKeyPress()
{
	_player.GetTransform().SetPosition(_player.GetTransform().GetPosition() + Vector3(-1, 0, 0) * _moveSpeed * GameTime::GetInstance().GetDeltaTime());
}

void RightKeyPress()
{
	_player.GetTransform().SetPosition(_player.GetTransform().GetPosition() + Vector3(1, 0, 0) * _moveSpeed * GameTime::GetInstance().GetDeltaTime());
}

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_VIDEO);

	_player = Entity();

	Window::GetInstance().SetWindowSize(8 * 64, 8 * 64);

	Input::GetInstance().Initialize();

	Input::GetInstance().OnDownKeyPress.AddSubscriber(std::bind(&DownKeyPress));
	Input::GetInstance().OnUpKeyPress.AddSubscriber(std::bind(&UpKeyPress));
	Input::GetInstance().OnLeftKeyPress.AddSubscriber(std::bind(&LeftKeyPress));
	Input::GetInstance().OnRightKeyPress.AddSubscriber(std::bind(&RightKeyPress));

	double elapsedTime = 1;

	while (Window::GetInstance().GetIsActive())
	{
		GameTime::GetInstance().Update();
		Input::GetInstance().Update();

		if (elapsedTime >= 1)
		{
			std::cout << "Time: " << GameTime::GetInstance().GetTime() << " | Delta-Time: " << GameTime::GetInstance().GetDeltaTime() << std::endl;
			elapsedTime = 0;
		}
		elapsedTime += GameTime::GetInstance().GetDeltaTime();

		for (uint32_t row = 0; row < 8; row++)
		{
			for (uint32_t col = 0; col < 8; col++)
			{
				Window::GetInstance().DrawRect(Color::Green(), col * 64, row * 64, 64, 64);
			}
		}

		Window::GetInstance().DrawRect(Color::Blue(), _player.GetTransform().GetEntity().GetTransform().GetPosition().GetX(), _player.GetTransform().GetPosition().GetY(), 64, 64);

		Window::GetInstance().Update();
	}

	SDL_Log("End reached");

quit:
	SDL_Quit();
	return 0;
}