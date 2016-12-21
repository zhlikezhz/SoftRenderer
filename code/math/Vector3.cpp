#include <cmath>
#include "Vector3.h"

Vector3::Vector3()
: x(0.0f)
, y(0.0f)
, z(0.0f)
{

}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{

}

float Vector3::Mod() const
{
	float mod = x * x + y * y + z * z;
	return std::sqrt(mod);
}

Vector3 Vector3::operator*(float num) const
{
	Vector3 result;
	result.x = y * num;
	result.y = y * num;
	result.z = z * num;
	return result;
}

Vector3 Vector3::operator+(const Vector3& vec) const
{
	Vector3 result;
	result.x = x + vec.x;
	result.y = y + vec.y;
	result.z = z + vec.z;
	return result;
}

Vector3 Vector3::operator-(const Vector3& vec) const
{
	Vector3 result;
	result.x = x - vec.x;
	result.y = y - vec.y;
	result.z = z - vec.z;
	return result;
}

Vector3 Vector3::Normalize(const Vector3& vec)
{
	float mod = vec.Mod();
	return Vector3(vec.x / mod, vec.y / mod, vec.z / mod);
}

float Vector3::Dot(const Vector3& vec1, const Vector3& vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec1.z);
}

float Vector3::Angle(const Vector3& vec1, const Vector3& vec2)
{
	float angle = 0.0f;
	float dot = Vector3::Dot(vec1, vec2);
	angle = std::acos(dot / (vec1.Mod() * vec2.Mod()));
}

Vector3 Vector3::Cross(const Vector3& vec1, const Vector3& vec2)
{
	Vector3 result;
	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return result;
}

float Vector3::Distance(const Vector3& vec1, const Vector3& vec2)
{
	float dis = 0.0f;
	dis = std::pow(vec1.x - vec2.x, 2);
	dis += std::pow(vec1.y - vec2.y, 2);
	dis += std::pow(vec1.z - vec2.z, 2);
	return std::sqrt(dis);
}