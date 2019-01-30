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

struct Vector2;
struct Vector3;

struct Vector4
{
	CBc_LIB_API Vector4();
	CBc_LIB_API Vector4(float x, float y, float z, float w);
	CBc_LIB_API ~Vector4();

	//------------------------------------------------------
	//	One
	//		Sets components to 1
	//------------------------------------------------------
	CBc_LIB_API void One();

	//------------------------------------------------------
	//	Zero
	//		Sets components to 0
	//------------------------------------------------------
	CBc_LIB_API void Zero();

	//------------------------------------------------------
	//	operator+
	//		Overloads - operator
	//
	//		Allows Integer promotion of Vectors
	//------------------------------------------------------
	CBc_LIB_API Vector4 operator+();

	//------------------------------------------------------
	//	operator-
	//		Overloads - operator
	//
	//		Allows Inverse of Vector
	//------------------------------------------------------
	CBc_LIB_API Vector4 operator-();
	
	//------------------------------------------------------
	//	operator+
	//		Overloads + operator
	//
	//		Allows Addition of Vectors
	//------------------------------------------------------
	CBc_LIB_API Vector4 operator+(Vector4 rhs);

	//------------------------------------------------------
	//	operator-
	//		Overloads - operator
	//
	//		Allows Subtraction of Vectors
	//------------------------------------------------------
	CBc_LIB_API Vector4 operator-(Vector4 rhs);

	//------------------------------------------------------
	//	operator*
	//		Overloads * operator
	//
	//		Allows Multiplication of Vector by rhs scalar
	//------------------------------------------------------
	CBc_LIB_API Vector4 operator*(float scalar);

	//------------------------------------------------------
	//	operator+=
	//		Overloads += operator
	//
	//		Allows Addition assignment of Vectors
	//------------------------------------------------------
	CBc_LIB_API Vector4& operator+=(Vector4 rhs);

	//------------------------------------------------------
	//	operator-
	//		Overloads - operator
	//
	//		Allows Subtraction assignment of Vectors
	//------------------------------------------------------
	CBc_LIB_API Vector4& operator-=(Vector4 rhs);

	//------------------------------------------------------
	//	operator*
	//		Overloads * operator
	//
	//		Allows Multiplication assignment of Vector by 
	//		rhs scalar
	//------------------------------------------------------
	CBc_LIB_API Vector4& operator*=(float scalar);

	//------------------------------------------------------
	//	operator==
	//		Overloads == operator
	//
	//		Allows 'Equal to' relational operator to check 
	//		Vectors against each other
	//------------------------------------------------------
	CBc_LIB_API bool operator==(Vector4 rhs);

	//------------------------------------------------------
	//	operator>
	//		Overloads > operator
	//
	//		Allows 'greater than' relational operator to check 
	//		Vectors against each other
	//------------------------------------------------------
	CBc_LIB_API bool operator>(Vector4 rhs);

	//------------------------------------------------------
	//	operator>=
	//		Overloads >= operator
	//
	//		Allows 'greater than or equals' relational operator to check 
	//		Vectors against each other
	//------------------------------------------------------
	CBc_LIB_API bool operator>=(Vector4 rhs);

	//------------------------------------------------------
	//	operator<
	//		Overloads < operator
	//
	//		Allows 'less than' relational operator to check 
	//		Vectors against each other
	//------------------------------------------------------
	CBc_LIB_API bool operator<(Vector4 rhs);

	//------------------------------------------------------
	//	operator<=
	//		Overloads <= operator
	//
	//		Allows 'less than or equals' relational operator to check 
	//		Vectors against each other
	//------------------------------------------------------
	CBc_LIB_API bool operator<=(Vector4 rhs);

	//------------------------------------------------------
	//	operator[]
	//		Overloads [] operator
	//
	//		Converts Vector4 to float* which is then
	//		accessed like a normal float array
	//------------------------------------------------------
	CBc_LIB_API float& operator[](int nIndex);

	//------------------------------------------------------
	//	operator float*
	//		(EXPLICIT) Overloads float* cast operator
	//
	//		Allows casting of Vector into float*
	//------------------------------------------------------
	CBc_LIB_API explicit operator float*();

	//------------------------------------------------------
	//	operator Vector2
	//		(EXPLICIT) Overloads Vector2 cast operator
	//
	//		Allows casting of Vector4 into Vector2
	//------------------------------------------------------
	CBc_LIB_API explicit operator Vector2();

	//------------------------------------------------------
	//	operator Vector3
	//		(EXPLICIT) Overloads Vector3 cast operator
	//
	//		Allows casting of Vector4 into Vector3
	//------------------------------------------------------
	CBc_LIB_API explicit operator Vector3();

	//------------------------------------------------------
	//	dot
	//		Dot Product of two Vectors
	//
	//			return (float):
	//				dot product
	//------------------------------------------------------
	CBc_LIB_API float dot(Vector4 rhs);

	//------------------------------------------------------
	//	cross
	//		Cross Product of two Vectors
	//
	//			return (Vector4):
	//				Vector at right angle to both input vectors
	//------------------------------------------------------
	CBc_LIB_API Vector4 cross(Vector4 rhs);

	//------------------------------------------------------
	//	magnitude
	//		Calculates magnitude of vector
	//
	//			return (float):
	//				actual magnitude of vector
	//------------------------------------------------------
	CBc_LIB_API float magnitude();

	//------------------------------------------------------
	//	magnitudeSqr
	//		Faster than magnitude
	//
	//		Calculates magnitude of vector but doesnt sqrt,
	//		only useful for checking relative vectors.
	//
	//			return (float):
	//				square of magnitude of vector
	//------------------------------------------------------
	CBc_LIB_API float magnitudeSqr();

	//------------------------------------------------------
	//	normalise
	//		Normalises the vector
	//
	//			return (float):
	//				magnitude before normalisation
	//------------------------------------------------------
	CBc_LIB_API float normalise();

	//------------------------------------------------------
	//	Swizzle
	//		Swizzle the vector
	//
	//			xyzw (char*):
	//				only allows characters (x,X),(y,Y),(z,Z),(w,W) 
	//				any other characters will cause an assert
	//				must have 4 characters
	//
	//			return (Vector4):
	//				Swizzled Vector4
	//------------------------------------------------------
	CBc_LIB_API Vector4 Swizzle(const char* xyzw);

	//------------------------------------------------------
	//	SwizzleRGBA
	//		Swizzle the vector
	//
	//			xyzw (char*):
	//				only allows characters (r,R),(g,G),(b,B),(a,A) 
	//				any other characters will cause an assert
	//				must have 4 characters
	//
	//			return (Vector4):
	//				Swizzled Vector4
	//------------------------------------------------------
	CBc_LIB_API Vector4 SwizzleRGBA(const char* rgba);

	// Variables
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		struct
		{
			float r;
			float g;
			float b;
			float a;
		};
	};
};

//------------------------------------------------------
//	operator*
//		Overloads * operator
//
//			Allows vector multiplication with lhs scalar
//------------------------------------------------------
static Vector4 operator*(float scalar, Vector4 vec)
{
	Vector4 outVec;
	outVec.x = vec.x * scalar;
	outVec.y = vec.y * scalar;
	outVec.z = vec.z * scalar;
	outVec.w = vec.w * scalar;

	return outVec;
}
