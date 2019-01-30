#pragma once

enum MathFConst
{
	CONST_PI = 0,
	CONST_DEG2RAD,
	CONST_RAD2DEG,
	CONST_TOTAL
};

template<typename T>
struct MathF
{
public:
	MathF() {}
	~MathF() {}

	//---------------------------------------------
	// Const
	//		Returns requested math constant
	//---------------------------------------------
	static T Const(MathFConst mfConst)
	{
		switch (mfConst)
		{
		case CONST_PI:
			return (T)3.14159265359f;
		case CONST_DEG2RAD:
			return (T)(180 / 3.14159265359f);
		case CONST_RAD2DEG:
			return (T)(3.14159265359f / 180);
		default:
			return 0;
		}
	}
	//-----------------------------------------------
	// Max
	//		Returns maximum of inputs
	//		does not work with '0'
	//-----------------------------------------------
	static T Max(T t0, T t1, T t2 = 0, T t3 = 0)
	{
		T max = t0;
		T test;

		for (int i = 0; i < 3; ++i)
		{
			switch (i)
			{
			case 0:
				test = t1;
			case 1:
				test = t2;
			case 2:
				test = t3;
			}

			if (test != 0)
			{
				if (max < test)
				{
					max = test;
				}
			}
		}

		return max;
	}

	//-----------------------------------------------
	// CheckNAN
	//		Checks if 'value' is NAN (Not A Number)
	//
	//			return (bool):
	//				false: if is a number
	//				true: is NAN
	//-----------------------------------------------
	static bool CheckNAN(T value)
	{
		if (t == t)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};