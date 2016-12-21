#pragma once
#include "Vector3.h"

class Quaternion
{
public:
	float x, y, z, w;
	
public:
	Quaternion();
	~Quaternion();
	Quaternion(float, float, float);
	Quaternion(float, float, float, float);

	float Mod();
	Quaternion operator*(const Quaternion& quat);
	Quaternion operator+(const Quaternion& quat);

public:
	static Quaternion EulerAngleToQuaternion(const Vector3& vec);
	static float Dot(const Quaternion& quat1, const Quaternion& quat2);
};

