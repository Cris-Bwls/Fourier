#include "Epicycle.h"

#define _USE_MATH_DEFINES
#include <math.h>


Epicycle::Epicycle(Vector2 v2Pos, WaveData dat)
{
	m_v2Pos = v2Pos;
	m_WaveData = dat;
}

Epicycle::~Epicycle()
{
}

Vector2 Epicycle::PosAtAngle(float fTheta)
{
	Vector2 result = m_v2Pos;

	float fPhi = m_WaveData.fFreq * fTheta + m_WaveData.fPhase + m_WaveData.fPhaseOffset;

	result.x += m_WaveData.fAmp * cosf(fPhi) ;
	result.y += m_WaveData.fAmp * sinf(fPhi);

	return result;
}


