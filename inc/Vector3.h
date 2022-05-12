#pragma once
#include <iostream>

class Vector3
{
private:
	float _x, _y, _z;

public:
	Vector3() : Vector3(0, 0, 0) { }

	Vector3(const float x, const float y, const float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	float GetX() const
	{
		return _x;
	}

	float GetY() const
	{
		return _y;
	}

	float GetZ() const
	{
		return _z;
	}

	void SetX(const float x)
	{
		_x = x;
	}

	void SetY(const float y)
	{
		_y = y;
	}

	void SetZ(const float z)
	{
		_z = z;
	}

	Vector3 operator+(const Vector3& other)
	{
		return Vector3(this->_x + other._x, this->_y + other._y, this->_z + other._z);
	}

	Vector3 operator+=(const Vector3& other)
	{
		this->_x += other._x;
		this->_y += other._y;
		this->_z += other._z;
		return *this;
	}

	Vector3 operator-(const Vector3& other)
	{
		return Vector3(this->_x - other._x, this->_y - other._y, this->_z - other._z);
	}

	Vector3 operator-=(const Vector3& other)
	{
		this->_x -= other._x;
		this->_y -= other._y;
		this->_z -= other._z;
		return *this;
	}

	Vector3 operator*(const float number)
	{
		return Vector3(this->_x * number, this->_y * number, this->_z * number);
	}

	Vector3 operator*=(const float number)
	{
		this->_x *= number;
		this->_y *= number;
		this->_z *= number;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector3& vector3)
	{
		os << "(" << vector3._x << ", " << vector3._y << ", " << vector3._z << ")";
		return os;
	}

	static Vector3 Zero()
	{
		return Vector3(0, 0, 0);
	}

	static Vector3 One()
	{
		return Vector3(1, 1, 1);
	}
};