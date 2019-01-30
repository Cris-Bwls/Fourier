#pragma once

#include "Renderer2D.h"
#include <vector>
#include "Epicycle.h"
#include <functional>

using std::vector;
using std::function;

class FourierSeries
{
public:
	FourierSeries(int nMaxEpicycles, function<WaveData(int)> seriesFunc = nullptr);
	~FourierSeries();

	inline void SetSeriesFunc(function<WaveData(int)> newFunc) { m_SeriesFunc = newFunc; };

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

	bool m_bIsActive = true;

private:
	void DefaultSeriesFunc();

	function<WaveData(int)> m_SeriesFunc;
	vector<Epicycle*> m_apEpicyles;
	vector<float> m_afWave;
	float m_fLastX;

	Vector2 m_v2EpicycleCenter;
	float m_fWaveOffset;

	float fTime = 0.0f;
};

