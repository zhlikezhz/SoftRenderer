#include "Matrix.h"

Vector4 Matrix::LinearTransformation(Vector4& vec, Matrix4x4& matrix)
{
	Vector4 result;
	result.x = vec.x * matrix.vec[0].x + vec.y * matrix.vec[1].x + vec.z * matrix.vec[2].x + vec.w + matrix.vec[3].x;
	result.y = vec.x * matrix.vec[0].y + vec.y * matrix.vec[1].y + vec.z * matrix.vec[2].y + vec.w + matrix.vec[3].y;
	result.z = vec.x * matrix.vec[0].z + vec.y * matrix.vec[1].z + vec.z * matrix.vec[2].z + vec.w + matrix.vec[3].z;
	result.w = vec.x * matrix.vec[0].w + vec.y * matrix.vec[1].w + vec.z * matrix.vec[2].w + vec.w + matrix.vec[3].w;
	return result;
}