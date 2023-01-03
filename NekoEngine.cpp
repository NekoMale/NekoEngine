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


class A {
public:
	A() { printf("cons\n"); }
	A(const A& a) { printf("copycons\n"); }
	~A() { printf("des\n"); }
	A& operator=(const A& other) { printf("assign\n"); return *this; }
};

void F(const A& f, A* g, A h)
{
	*g = f;
}

A F()
{
	printf("46\n");
	A tmp;
	printf("48\n");
	return tmp;
}

#define CALLS(a, b) f(a, b)

int f(int a, int b)
{
	int res = (a) > (b) ? (a) : (b);
	std::cout << a << " > " << b << std::endl;
	return res;
}



template<typename T>
class no {
public:
	no(const char* name, const T& value) {
		nameValue = name;
		ov = value;
		printf("blo");
	}
	no(const std::string& name, const T& value) {
		nameValue = name; ov = value;
		printf("bla");
	}

private:
	std::string& nameValue;
	T ov;
};

class TimeKeeper {
public:
	TimeKeeper();
	~TimeKeeper();
};

class WindowsClick : public TimeKeeper {};
class LinuxClock : public TimeKeeper {};

int main(int argc, char** argv)
{
	//int a = 5, b = 0;
	//std::cout << CALLS(++a, b) << std::endl;
	//std::cout << CALLS(++a, b + 10) << std::endl;

	TimeKeeper* getTimeKeeper();

	TimeKeeper* ptk = getTimeKeeper();

//
//	SDL_Init(SDL_INIT_VIDEO);
//
//	_player = Entity();
//
//	Window::GetInstance().SetWindowSize(8 * 64, 8 * 64);
//
//	Input::GetInstance().Initialize();
//
//	Input::GetInstance().OnDownKeyPress.AddSubscriber(std::bind(&DownKeyPress));
//	Input::GetInstance().OnUpKeyPress.AddSubscriber(std::bind(&UpKeyPress));
//	Input::GetInstance().OnLeftKeyPress.AddSubscriber(std::bind(&LeftKeyPress));
//	Input::GetInstance().OnRightKeyPress.AddSubscriber(std::bind(&RightKeyPress));
//
//	double elapsedTime = 1;
//
//	while (Window::GetInstance().GetIsActive())
//	{
//		GameTime::GetInstance().Update();
//		Input::GetInstance().Update();
//
//		if (elapsedTime >= 1)
//		{
//			std::cout << "Time: " << GameTime::GetInstance().GetTime() << " | Delta-Time: " << GameTime::GetInstance().GetDeltaTime() << std::endl;
//			elapsedTime = 0;
//		}
//		elapsedTime += GameTime::GetInstance().GetDeltaTime();
//
//		for (uint32_t row = 0; row < 8; row++)
//		{
//			for (uint32_t col = 0; col < 8; col++)
//			{
//				Window::GetInstance().DrawRect(Color::Green(), col * 64, row * 64, 64, 64);
//			}
//		}
//
//		Window::GetInstance().DrawRect(Color::Blue(), _player.GetTransform().GetEntity().GetTransform().GetPosition().GetX(), _player.GetTransform().GetPosition().GetY(), 64, 64);
//
//		Window::GetInstance().Update();
//	}
//
//	SDL_Log("End reached");
//
//quit:
//	SDL_Quit();
	return 0;
}
