#pragma once

// STATIC/DLL Definition
#ifdef CBc_LIB_STATIC
#define CBc_LIB_API
#else // NOT STATIC
#ifdef CBc_LIB_DLL
#define CBc_LIB_API __declspec(dllexport)
#else
#define CBc_LIB_API __declspec(dllimport)
#endif // DLL
#endif // STATIC
#include "Vector4.h"

struct Vector4;
struct Vector3;

struct Matrix4
{
	CBc_LIB_API Matrix4();
	CBc_LIB_API Matrix4(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33);
	CBc_LIB_API ~Matrix4();

	CBc_LIB_API void Identity();

	CBc_LIB_API void LocalTransform(Matrix4 posMat, Matrix4 rotMat, Matrix4 scaleMat);
	CBc_LIB_API void GlobalTransform(Matrix4 parentsGlobalTransform, Matrix4 localTransform);

	CBc_LIB_API Vector4 operator*(Vector4 rhs);
	CBc_LIB_API Matrix4 operator*(Matrix4 rhs);

	CBc_LIB_API Vector4& operator[](int nIndex);
	CBc_LIB_API explicit operator float*();

	CBc_LIB_API void setRotateX(float fRadians);
	CBc_LIB_API void setRotateY(float fRadians);
	CBc_LIB_API void setRotateZ(float fRadians);

	CBc_LIB_API void SetPosition(float x, float y, float z);
	CBc_LIB_API void SetPosition(Vector3 pos);

	CBc_LIB_API void SetScale(float x, float y, float z);
	CBc_LIB_API void SetScale(Vector3 scale);

	CBc_LIB_API Vector3 GetPosition();
	CBc_LIB_API Vector3 GetRight();
	CBc_LIB_API Vector3 GetUp();
	CBc_LIB_API Vector3 GetFacing();

	// Variables
	union
	{
		float m1[16];
		float m2[4][4];
		Vector4 vec4[4];
	};
};

