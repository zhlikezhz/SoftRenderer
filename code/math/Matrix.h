#pragma once
#include "Vector3.h"
#define M_PI 3.14159265358979323846
#include <cmath>

struct Vector4
{
	float x, y, z, w;

	Vector4() 
	: x(0.0f)
	, y(0.0f)
	, z(0.0f)
	, w(0.0f)
	{ }

	Vector4(Vector3& vec, float w)
	{
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
		this->w = w;
	}
};

class Matrix4x4
{
private:
	Vector4 vector[4];

public:
	Matrix4x4();
	Matrix4x4(float, float, float);
	Matrix4x4(Vector3&, Vector3&, Vector3&, Vector3&);
	Matrix4x4 operator*(const Matrix4x4&);
	Vector4 operator*(const Vector4& vec);
};