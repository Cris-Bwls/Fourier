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
struct Vector4;

struct Vector3
{
	CBc_LIB_API Vector3();
	CBc_LIB_API Vector3(float x, float y, float z);
	CBc_LIB_API ~Vector3();

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
	//	Right
	//		Sets x to 1
	//		all others set to 0
	//------------------------------------------------------
	CBc_LIB_API void Right();

	//------------------------------------------------------
	//	Left
	//		Sets x to -1
	//		all others set to 0
	//------------------------------------------------------
	CBc_LIB_API void Left();

	//------------------------------------------------------
	//	Up
	//		Sets y to 1
	//		all others set to 0
	//------------------------------------------------------
	CBc_LIB_API void Up();

	//------------------------------------------------------
	//	Down
	//		Sets y to -1
	//		all others set to 0
	//------------------------------------------------------
	CBc_LIB_API void Down();

	//------------------------------------------------------
	//	Forward
	//		Sets z to 1
	//		all others set to 0
	//------------------------------------------------------
	CBc_LIB_API void Forward();

	//------------------------------------------------------
	//	Back
	//		Sets z to -1
	//		all others set to 0
	//------------------------------------------------------
	CBc_LIB_API void Back();

	//------------------------------------------------------
	//	operator+
	//		Overloads - operator
	//
	//		Allows Integer promotion of Vectors
	//------------------------------------------------------
	CBc_LIB_API Vector3 operator+();

	//------------------------------------------------------
	//	operator-
	//		Overloads - operator
	//
	//		Allows Inverse of Vector
	//------------------------------------------------------
	CBc_LIB_API Vector3 operator-();
	
	//------------------------------------------------------
	//	operator+
	//		Overloads + operator
	//
	//		Allows Addition of Vectors
	//------------------------------------------------------
	CBc_LIB_API Vector3 operator+(Vector3 rhs);

	//------------------------------------------------------
	//	operator-
	//		Overloads - operator
	//
	//		Allows Subtraction of Vectors
	//------------------------------------------------------
	CBc_LIB_API Vector3 operator-(Vector3 rhs);

	//------------------------------------------------------
	//	operator*
	//		Overloads * operator
	//
	//		Allows Multiplication of Vector by rhs scalar
	//------------------------------------------------------
	CBc_LIB_API Vector3 operator*(float scalar);

	//------------------------------------------------------
	//	operator+=
	//		Overloads += operator
	//
	//		Allows Addition assignment of Vectors
	//------------------------------------------------------
	CBc_LIB_API Vector3& operator+=(Vector3 rhs);

	//------------------------------------------------------
	//	operator-
	//		Overloads - operator
	//
	//		Allows Subtraction assignment of Vectors
	//------------------------------------------------------
	CBc_LIB_API Vector3& operator-=(Vector3 rhs);

	//------------------------------------------------------
	//	operator*
	//		Overloads * operator
	//
	//		Allows Multiplication assignment of Vector by 
	//		rhs scalar
	//------------------------------------------------------
	CBc_LIB_API Vector3& operator*=(float scalar);

	//------------------------------------------------------
	//	operator==
	//		Overloads == operator
	//
	//		Allows 'Equal to' relational operator to check 
	//		Vectors against each other
	//------------------------------------------------------
	CBc_LIB_API bool operator==(Vector3 rhs);

	//------------------------------------------------------
	//	operator>
	//		Overloads > operator
	//
	//		Allows 'greater than' relational operator to check 
	//		Vectors against each other
	//------------------------------------------------------
	CBc_LIB_API bool operator>(Vector3 rhs);

	//------------------------------------------------------
	//	operator>=
	//		Overloads >= operator
	//
	//		Allows 'greater than or equals' relational operator to check 
	//		Vectors against each other
	//------------------------------------------------------
	CBc_LIB_API bool operator>=(Vector3 rhs);

	//------------------------------------------------------
	//	operator<
	//		Overloads < operator
	//
	//		Allows 'less than' relational operator to check 
	//		Vectors against each other
	//------------------------------------------------------
	CBc_LIB_API bool operator<(Vector3 rhs);

	//------------------------------------------------------
	//	operator<=
	//		Overloads <= operator
	//
	//		Allows 'less than or equals' relational operator to check 
	//		Vectors against each other
	//------------------------------------------------------
	CBc_LIB_API bool operator<=(Vector3 rhs);

	//------------------------------------------------------
	//	operator[]
	//		Overloads [] operator
	//
	//		Converts Vector3 to float* which is then
	//		accessed like a normal float array
	//------------------------------------------------------
	CBc_LIB_API float& operator[](int nIndex);

	//------------------------------------------------------
	//	operator float*
	//		Overloads float* cast operator
	//
	//		Allows casting of Vector into float*
	//------------------------------------------------------
	CBc_LIB_API explicit operator float*();

	//------------------------------------------------------
	//	operator Vector2
	//		(EXPLICIT) Overloads Vector2 cast operator
	//
	//		Allows casting of Vector3 into Vector2
	//------------------------------------------------------
	CBc_LIB_API explicit operator Vector2();

	//------------------------------------------------------
	//	operator Vector4
	//		(EXPLICIT) Overloads Vector4 cast operator
	//
	//		Allows casting of Vector3 into Vector4
	//------------------------------------------------------
	CBc_LIB_API explicit operator Vector4();

	//------------------------------------------------------
	//	dot
	//		Dot Product of two Vectors
	//
	//			return (float):
	//				dot product
	//------------------------------------------------------
	CBc_LIB_API float dot(Vector3 rhs);

	//------------------------------------------------------
	//	cross
	//		Cross Product of two Vectors
	//
	//			return (Vector3):
	//				Vector at right angle to both input vectors
	//------------------------------------------------------
	CBc_LIB_API Vector3 cross(Vector3 rhs);

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
	//			xyz (char*):
	//				only allows characters (x,X),(y,Y),(z,Z)
	//				any other characters will cause an assert
	//				must have 3 characters
	//
	//			return (Vector3):
	//				Swizzled Vector3
	//------------------------------------------------------
	CBc_LIB_API Vector3 Swizzle(const char* xyz);

	// Variables
	float x;
	float y;
	float z;
};

//------------------------------------------------------
//	operator*
//		Overloads * operator
//
//			Allows vector multiplication with lhs scalar
//------------------------------------------------------
static Vector3 operator*(float scalar, Vector3 vec)
{
	Vector3 outVec;
	outVec.x = vec.x * scalar;
	outVec.y = vec.y * scalar;
	outVec.z = vec.z * scalar;

	return outVec;
}

