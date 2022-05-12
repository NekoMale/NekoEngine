#pragma once
//#include <SDL.h>

class Color
{
private:
	short _r, _g, _b, _a;

public:
	Color(const short r, const short g, const short b, const short a)
	{
		_r = r;
		_g = g;
		_b = b;
		_a = a;
	}

	Color(const short r, const short g, const short b) : Color(r, g, b, 255) { }

	Color() : Color(255, 255, 255, 255) {}
	
	//Color(const Color& other)
	//{
	//	_r = other._r;
	//	_g = other._g;
	//	_b = other._b;
	//	_a = other._a;
	//}

	short GetR() const
	{
		return _r;
	}

	short GetG() const
	{
		return _g;
	}

	short GetB() const
	{
		return _b;
	}

	short GetA() const
	{
		return _a;
	}

	friend std::ostream& operator<<(std::ostream& os, const Color& color)
	{
		os << "(" << color._r << ", " << color._g << ", " << color._b << ", " << color._a << ")";
		return os;
	}

	static Color Transparent()
	{
		return Color(255, 255, 255, 0);
	}

	static Color White()
	{
		return Color(255, 255, 255);
	}

	static Color Black()
	{
		return Color(0, 0, 0);
	}

	static Color Red()
	{
		return Color(255, 0, 0);
	}

	static Color Green()
	{
		return Color(0, 255, 0);
	}

	static Color Blue()
	{
		return Color(0, 0, 255);
	}
};