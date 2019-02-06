#pragma once
#include "Epicycle.h"
#include "Vector2.h"
#include "Renderer2D.h"
#include <vector>

using std::vector;

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280

class FourierDrawing
{
public:
	FourierDrawing(vector<Vector2> aDrawing = vector<Vector2>());
	~FourierDrawing();

	inline void SetDrawing(vector<Vector2> aDrawing) { m_aDrawing = aDrawing; Reset(); };
	inline void SetRadiusMulti(float fRadiusMulti) { m_fRadiusMultiplier = fRadiusMulti; };
	inline void SetEpicycleXCenter(Vector2 v2Pos) { m_v2EpicycleXCenter = v2Pos, m_fXOffset = v2Pos.x * 2; };
	inline void SetEpicycleYCenter(Vector2 v2Pos) { m_v2EpicycleYCenter = v2Pos, m_fYOffset = (WINDOW_HEIGHT / 2) -v2Pos.y * 2; };
	inline void SetLineSize(float fLineSize) { m_fLineSize = fLineSize; };

	inline void Reset() { DestroyEpicycles(); Start(); };
	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);



	bool m_bIsActive = true;

private:
	void Start();
	void DestroyEpicycles();
	void DefaultDrawing();

	vector<WaveData> DFT(vector<float>& in);

	// VAR
	vector<Vector2> m_aDrawing;
	vector<Vector2> m_aPath;
	int m_nDrawingLength;
	float m_fRadiusMultiplier;
	vector<Epicycle*> m_apEpicyclesX;
	vector<Epicycle*> m_apEpicyclesY;
	Vector2 m_v2EpicycleXCenter;
	Vector2 m_v2EpicycleYCenter;
	float m_fXOffset;
	float m_fYOffset;

	float m_fLineSize;
	float m_fTime = 0.0f;
};

