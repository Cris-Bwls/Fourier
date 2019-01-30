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
#include "Vector3.h"

struct Vector3;
struct Vector2;

struct Matrix3
{
	CBc_LIB_API Matrix3();
	CBc_LIB_API Matrix3(
		float m00, float m01, float m02, 
		float m10, float m11, float m12,
		float m20, float m21, float m22);
	CBc_LIB_API ~Matrix3();

	CBc_LIB_API void Identity();

	CBc_LIB_API void LocalTransform(Matrix3 posMat, Matrix3 rotMat, Matrix3 scaleMat);
	CBc_LIB_API void GlobalTransform(Matrix3 parentsGlobalTransform, Matrix3 localTransform);

	CBc_LIB_API Vector3 operator*(Vector3 rhs);
	CBc_LIB_API Matrix3 operator*(Matrix3 rhs);

	CBc_LIB_API Vector3& operator[](int nIndex);
	CBc_LIB_API explicit operator float*();

	CBc_LIB_API void setRotateX(float fRadians);
	CBc_LIB_API void setRotateY(float fRadians);
	CBc_LIB_API void setRotateZ(float fRadians);

	CBc_LIB_API void SetRotate2D(float fRadians);

	CBc_LIB_API void SetPosition(float x, float y);
	CBc_LIB_API void SetPosition(Vector2 pos);

	CBc_LIB_API void SetScale(float x, float y);
	CBc_LIB_API void SetScale(Vector2 scale);

	CBc_LIB_API Vector2 GetPosition();
	CBc_LIB_API Vector2 GetRight();
	CBc_LIB_API Vector2 GetUp();
	CBc_LIB_API Vector2 GetFacing2D();

	// Variables
	union
	{
		float m1[9];
		float m2[3][3];
		Vector3 vec3[3];
	};
};

