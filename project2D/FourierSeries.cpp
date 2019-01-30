#include "FourierSeries.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define RADIUS_MULTIPLIER 50.0f
#define LINE_SIZE 2.0f
#define MAX_WAVE_LENGTH 1000

FourierSeries::FourierSeries(int nMaxEpicycles, function<WaveData(int)> seriesFunc)
{
	m_v2EpicycleCenter = { 150.0f, 360.0f };
	m_fWaveOffset = m_v2EpicycleCenter.x + 100.0f;

	if (seriesFunc)
		m_SeriesFunc = seriesFunc;
	else
		DefaultSeriesFunc();

	Vector2 v2Pos = m_v2EpicycleCenter;

	for (int i = 0; i < nMaxEpicycles; ++i)
	{
		WaveData data = m_SeriesFunc(i);

		auto var = new Epicycle(v2Pos, data);
		m_apEpicyles.push_back(var);
		
		v2Pos.x += data.fAmp * 1;	//cos(0) = 1
		v2Pos.y += data.fAmp * 0;	//sin(0) = 0
	}
}

FourierSeries::~FourierSeries()
{
	for each (Epicycle* var in m_apEpicyles)
	{
		delete var;
	}
}

void FourierSeries::Update(float fDeltaTime)
{
	fTime += fDeltaTime;

	Vector2 v2Pos = m_v2EpicycleCenter;

	for (int i = 0; i < m_apEpicyles.size(); ++i)
	{
		auto var = m_apEpicyles[i];
		var->SetPos(v2Pos);
		v2Pos = var->PosAtAngle(fTime);
	}

	m_fLastX = v2Pos.x;
	m_afWave.insert(m_afWave.begin(), v2Pos.y);

	if (m_afWave.size() > MAX_WAVE_LENGTH)
		m_afWave.pop_back();
}

void FourierSeries::Draw(aie::Renderer2D * pRenderer)
{
	Vector2 prevPos = m_v2EpicycleCenter;
	for (int i = 0; i < m_apEpicyles.size(); ++i)
	{
		auto var = m_apEpicyles[i];
		Vector2 v2Pos = var->GetPos();
		pRenderer->setRenderColour(0xFF0000FF);
		pRenderer->drawCircle(v2Pos.x, v2Pos.y, var->GetRadius(), 50.0f);
		pRenderer->setRenderColour(0xFFFFFFFF);
		pRenderer->drawLine(prevPos.x, prevPos.y, v2Pos.x, v2Pos.y, LINE_SIZE);

		prevPos = v2Pos;
	}

	pRenderer->drawLine(prevPos.x, prevPos.y, m_fLastX, m_afWave[0], LINE_SIZE);

	float fWaveStartX = m_fWaveOffset + m_v2EpicycleCenter.x;
	pRenderer->drawLine(m_fLastX, m_afWave[0], fWaveStartX, m_afWave[0], LINE_SIZE * 2);

	for (int i = 0; i < m_afWave.size() - 1; ++i)
	{
		float fCurrentX = fWaveStartX + i;
		pRenderer->drawLine(fCurrentX, m_afWave[i], fCurrentX + 1, m_afWave[i + 1], LINE_SIZE);
	}
}

void FourierSeries::DefaultSeriesFunc()
{
	m_SeriesFunc = [](int iter)->WaveData
	{
		WaveData data;
		data.fFreq = float(iter * 2 + 1);
		data.fAmp = (4.0f / (data.fFreq * (float)M_PI)) * RADIUS_MULTIPLIER;

		return data;
	};
}
