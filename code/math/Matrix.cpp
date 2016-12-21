#include "Matrix.h"

Matrix4x4::Matrix4x4()
{
	for (int i = 0; i < 4; i++)
	{
		vector[i].x = 0;
		vector[i].y = 0;
		vector[i].z = 0;
		vector[i].w = 0;
	}
}

Matrix4x4::Matrix4x4(float eulerAngleX, float eulerAngleY, float eulerAngleZ)
{
	float angleX = eulerAngleX / 180 * M_PI;
	float sinX = std::sin(angleX);
	float cosX = std::cos(angleX);
	Matrix4x4 rotationX(
		Vector3(1, 0, 0),
		Vector3(0, cosX, sinX),
		Vector3(0, -sinX, cosX),
		Vector3(0, 0, 0)
	);

	float angleY = eulerAngleY / 180 * M_PI;
	float sinY = std::sin(angleY);
	float cosY = std::cos(angleY);
	Matrix4x4 rotationY(
		Vector3(cosY, 0, -sinY),
		Vector3(0, 1, 0),
		Vector3(sinY, 0, cosY),
		Vector3(0, 0, 0)
	);

	float angleZ = eulerAngleZ / 180 * M_PI;
	float sinZ = std::sin(angleZ);
	float cosZ = std::cos(angleZ);
	Matrix4x4 rotationZ(
		Vector3(cosZ, sinZ, 0),
		Vector3(-sinZ, cosZ, 0),
		Vector3(0, 0, 1),
		Vector3(0, 0, 0)
	);

	Matrix4x4 result = rotationZ * rotationX * rotationY;
	for (int i = 0; i < 4; i++)
	{
		vector[i].x = result.vector[i].x;
		vector[i].y = result.vector[i].y;
		vector[i].z = result.vector[i].z;
		vector[i].w = result.vector[i].w;
	}
}

Matrix4x4::Matrix4x4(Vector3& vec1, Vector3& vec2, Vector3& vec3, Vector3& vec4)
{
	vector[0] = Vector4(vec1, 0);
	vector[1] = Vector4(vec2, 0);
	vector[2] = Vector4(vec3, 0);
	vector[3] = Vector4(vec4, 1);
}

Vector4 Matrix4x4::operator*(const Vector4& vec)
{
	Vector4 result;
	result.x = vec.x * vector[0].x + vec.y * vector[1].x + vec.z * vector[2].x + vec.w + vector[3].x;
	result.y = vec.x * vector[0].y + vec.y * vector[1].y + vec.z * vector[2].y + vec.w + vector[3].y;
	result.z = vec.x * vector[0].z + vec.y * vector[1].z + vec.z * vector[2].z + vec.w + vector[3].z;
	result.w = vec.x * vector[0].w + vec.y * vector[1].w + vec.z * vector[2].w + vec.w + vector[3].w;
	return result;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& matrix)
{
	float x[4][4], y[4][4], z[4][4];
	for (int i = 0; i < 4; i++)
	{
		x[i][0] = vector[i].x;
		x[i][1] = vector[i].y;
		x[i][2] = vector[i].z;
		x[i][3] = vector[i].w;

		y[i][0] = matrix.vector[i].x;
		y[i][1] = matrix.vector[i].y;
		y[i][2] = matrix.vector[i].z;
		y[i][3] = matrix.vector[i].w;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			z[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				z[i][j] += x[i][k] * y[k][j];
			}
		}
	}

	Matrix4x4 result;
	for (int i = 0; i < 4; i++)
	{
		result.vector[i].x = z[i][0];
		result.vector[i].y = z[i][1];
		result.vector[i].z = z[i][2];
		result.vector[i].w = z[i][3];
	}

	return result;
}
