#include "Quaternion.h"
#include <cmath>
#define M_PI 3.14159265358979323846

Quaternion::Quaternion()
: x(0)
, y(0)
, z(0)
, w(0)
{

}

Quaternion::~Quaternion()
{

}

Quaternion::Quaternion(float x, float y, float z)
{
	Quaternion quat = EulerAngleToQuaternion(Vector3(x, y, z));
	this->x = quat.x;
	this->y = quat.y;
	this->z = quat.z;
	this->w = quat.w;
}

Quaternion::Quaternion(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

float Quaternion::Mod()
{
	return std::sqrt(x*x + y*y + z*z + w*w);
}

Quaternion Quaternion::operator+(const Quaternion& quat)
{
	Quaternion result;
	result.x = x + quat.x;
	result.y = y + quat.y;
	result.z = z + quat.z;
	result.w = w + quat.w;
	return result;
}

/*
ij = k, ji = -k, jk = i, kj = -i, ki = j, ik = -j.

q = a + bi + cj + dk
p = t + xi + yj + zk
q * p = (at-bx-cy-dz) + (ax+bt+cz-dy)i + (ay-bz+ct+dx)j + (az+by-cx+dt)k
*/
Quaternion Quaternion::operator*(const Quaternion& quat)
{
	Quaternion result;
	result.w = w * quat.w - x * quat.x - y * quat.y - z * quat.z;
	result.x = w * quat.x + x * quat.w + y * quat.z - z * quat.y;
	result.y = w * quat.y - x * quat.z + y * quat.w + z * quat.x;
	result.z = w * quat.z + x * quat.y - y * quat.x + z * quat.w;
	return result;
}

Quaternion Quaternion::EulerAngleToQuaternion(const Vector3& vec)
{
	float cosHalfX = std::cos(vec.x / 360 * M_PI);
	float sinHalfX = std::sin(vec.x / 360 * M_PI);
	Quaternion quatX(sinHalfX, sinHalfX, sinHalfX, cosHalfX);

	float cosHalfY = std::cos(vec.y / 360 * M_PI);
	float sinHalfY = std::sin(vec.y / 360 * M_PI);
	Quaternion quatY(sinHalfY, sinHalfY, sinHalfY, cosHalfY);

	float cosHalfZ = std::cos(vec.z / 360 * M_PI);
	float sinHalfZ = std::sin(vec.z / 360 * M_PI);
	Quaternion quatZ(sinHalfZ, sinHalfZ, sinHalfZ, cosHalfZ);

	return quatZ * quatX * quatY;
}

float Quaternion::Dot(const Quaternion& quat1, const Quaternion& quat2)
{
	return quat1.x*quat2.x + quat1.y*quat2.y + quat1.z*quat2.z + quat1.w*quat2.w;
}