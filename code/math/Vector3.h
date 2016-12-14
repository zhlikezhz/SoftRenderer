#pragma once
class Vector3
{
public:
	float x, y, z;

public:
	Vector3();
	~Vector3();

	float Mod() const;
	Vector3 operator*(float num) const;
	Vector3 operator+(const Vector3& vec) const;
	Vector3 operator-(const Vector3& vec) const;

public:
	static float Dot(const Vector3& vec1, const Vector3& vec2);
	static float Angle(const Vector3& vec1, const Vector3& vec2);
	static Vector3 Cross(const Vector3& vec1, const Vector3& vec2);
	static float Distance(const Vector3& vec1, const Vector3& vec2);
};

