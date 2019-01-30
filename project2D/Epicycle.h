#pragma once
#include "Vector2.h"

struct WaveData
{
	float fAmp = 0;
	float fFreq = 0;
	float fPhase = 0;
	float fPhaseOffset = 0;
};

class Epicycle
{
public:
	Epicycle(Vector2 v2Pos, WaveData dat);
	~Epicycle();

	inline void SetPos(Vector2 v2Pos) { m_v2Pos = v2Pos; };
	inline Vector2 GetPos() { return m_v2Pos; };

	inline float GetRadius() { return m_WaveData.fAmp; };

	Vector2 PosAtAngle(float fTheta);

private:
	Vector2 m_v2Pos;
	WaveData m_WaveData;
};

