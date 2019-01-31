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

	inline void SetMaxEpicycles(int nMaxEpicycles) { m_nMaxEpicycles = nMaxEpicycles; ResetSeries(); };
	inline void SetSeriesFunc(function<WaveData(int)> newFunc) { m_SeriesFunc = newFunc; ResetSeries(); };
	inline void SetMaxWaveCount(int nMaxWaveCount) { m_nMaxWaveCount = nMaxWaveCount; };
	inline void SetRadiusMulti(float fRadiusMulti) { m_fRadiusMultiplier = fRadiusMulti; };
	inline void SetEpicycleCenter(Vector2 v2Pos) { m_v2EpicycleCenter = v2Pos, m_fWaveOffset = v2Pos.x * 2; };
	inline void SetLineSize(float fLineSize) { m_fLineSize = 2.0f; };

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

	bool m_bIsActive = true;

private:
	void DefaultSeriesFunc();
	void StartSeries();
	void ResetSeries();

	int m_nMaxEpicycles = 0;
	int m_nMaxWaveCount = 1000;
	float m_fRadiusMultiplier = 50.0f;
	float m_fLineSize = 2.0f;

	function<WaveData(int)> m_SeriesFunc;
	vector<Epicycle*> m_apEpicyles;
	vector<float> m_afWave;
	float m_fLastX;

	Vector2 m_v2EpicycleCenter;
	float m_fWaveOffset;

	float fTime = 0.0f;
};

