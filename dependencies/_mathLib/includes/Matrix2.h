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
#include "Vector2.h"

struct Vector2;

class Matrix2
{
public:
	CBc_LIB_API Matrix2();
	CBc_LIB_API Matrix2(
		float m00, float m01,
		float m10, float m11);
	CBc_LIB_API ~Matrix2();

	CBc_LIB_API void Identity();

	CBc_LIB_API Vector2 operator*(Vector2 rhs);
	CBc_LIB_API Matrix2 operator*(Matrix2 rhs);
	
	CBc_LIB_API Vector2& operator[](int nIndex);
	CBc_LIB_API explicit operator float*();

	CBc_LIB_API void setRotate(float fRadians);

	CBc_LIB_API Vector2 GetRight();
	CBc_LIB_API Vector2 GetUp();

	// Variables
	union
	{
		float m1[4];
		float m2[2][2];
		Vector2 vec2[2];
	};
};

