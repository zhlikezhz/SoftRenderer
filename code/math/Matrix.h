#pragma once
#include "Vector3.h"

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

struct Matrix4x4
{
	Vector4 vec[4];

	Matrix4x4(Vector4 vec1, Vector4 vec2, Vector4 vec3, Vector4 vec4)
	{
		vec[0] = vec1;
		vec[1] = vec2;
		vec[2] = vec3;
		vec[3] = vec4;
	}
};

class Matrix
{
private:
	virtual ~Matrix() = 0;

public:
	static Vector4 LinearTransformation(Vector4& vec, Matrix4x4& matrix);
};

