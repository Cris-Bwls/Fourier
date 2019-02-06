#include "FourierDrawing.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define DEFAULT_RADIUS_MULTIPLIER 1.0f
#define DEFAULT_LINE_SIZE 2.0f
#define DEFAULT_MAX_DRAWING_LENGTH 1000



FourierDrawing::FourierDrawing(vector<Vector2> aDrawing)
{
	m_fRadiusMultiplier = DEFAULT_RADIUS_MULTIPLIER;
	m_fLineSize = DEFAULT_LINE_SIZE;
	m_nDrawingLength = DEFAULT_MAX_DRAWING_LENGTH;

	m_v2EpicycleYCenter = { 150.0f, WINDOW_HEIGHT / 2 };
	m_fYOffset = m_v2EpicycleXCenter.x * 2;

	m_v2EpicycleXCenter = { WINDOW_WIDTH / 2 , WINDOW_HEIGHT - 150.0f };
	m_fXOffset = (WINDOW_HEIGHT / 2) -m_v2EpicycleXCenter.y * 2;

	if (aDrawing.size() > 0)
		m_aDrawing = aDrawing;
	else
		DefaultDrawing();

	Start();
}

FourierDrawing::~FourierDrawing()
{
	DestroyEpicycles();
}

void FourierDrawing::Update(float fDeltaTime)
{
	if (!m_bIsActive)
		return;

	m_fTime += (float)M_2_PI / (m_apEpicyclesX.size() * 10);
	/*if (m_fTime > (float)M_2_PI * 4)
	{
		m_fTime = 0.0f;
		m_aPath = vector<Vector2>();
	}*/

	Vector2 v2PathSegment;

	Vector2 v2Pos = m_v2EpicycleXCenter;
	for (int i = 0; i < m_apEpicyclesX.size(); ++i)
	{
		auto var = m_apEpicyclesX[i];
		var->SetPos(v2Pos);
		v2Pos = var->PosAtAngle(m_fTime);
	}
	v2PathSegment.x = v2Pos.x;

	v2Pos = m_v2EpicycleYCenter;
	for (int i = 0; i < m_apEpicyclesY.size(); ++i)
	{
		auto var = m_apEpicyclesY[i];
		var->SetPos(v2Pos);
		v2Pos = var->PosAtAngle(m_fTime);
	}
	v2PathSegment.y = v2Pos.y;

	m_aPath.insert(m_aPath.begin(), v2PathSegment);

	if (m_aPath.size() > m_nDrawingLength)
		m_aPath.pop_back();
}

void FourierDrawing::Draw(aie::Renderer2D * pRenderer)
{
	if (!m_bIsActive)
		return;

	Vector2 prevPos = m_v2EpicycleXCenter;
	for (int i = 0; i < m_apEpicyclesX.size(); ++i)
	{
		auto var = m_apEpicyclesX[i];
		Vector2 v2Pos = var->GetPos();
		pRenderer->setRenderColour(0xFF0000FF);
		pRenderer->drawCircle(v2Pos.x, v2Pos.y, var->GetRadius(), 50.0f);
		pRenderer->setRenderColour(0xFFFFFFFF);
		pRenderer->drawLine(prevPos.x, prevPos.y, v2Pos.x, v2Pos.y, m_fLineSize);

		prevPos = v2Pos;
	}
	Vector2 tempX = m_apEpicyclesX.back()->PosAtAngle(m_fTime);
	pRenderer->drawLine(prevPos.x, prevPos.y, tempX.x, tempX.y, m_fLineSize);

	prevPos = m_v2EpicycleYCenter;
	for (int i = 0; i < m_apEpicyclesY.size(); ++i)
	{
		auto var = m_apEpicyclesY[i];
		Vector2 v2Pos = var->GetPos();
		pRenderer->setRenderColour(0x00FF00FF);
		pRenderer->drawCircle(v2Pos.x, v2Pos.y, var->GetRadius(), 50.0f);
		pRenderer->setRenderColour(0xFFFFFFFF);
		pRenderer->drawLine(prevPos.x, prevPos.y, v2Pos.x, v2Pos.y, m_fLineSize);

		prevPos = v2Pos;
	}

	Vector2 tempY = m_apEpicyclesY.back()->PosAtAngle(m_fTime);
	pRenderer->drawLine(prevPos.x, prevPos.y, tempY.x, tempY.y, m_fLineSize);

	pRenderer->drawLine(tempX.x, tempX.y, m_aPath[0].x, m_aPath[0].y, m_fLineSize * 2);
	pRenderer->drawLine(tempY.x, tempY.y, m_aPath[0].x, m_aPath[0].y, m_fLineSize * 2);

	for (int i = 0; i < m_aPath.size() - 1; ++i)
	{
		pRenderer->drawLine(m_aPath[i].x, m_aPath[i].y, m_aPath[i + 1].x, m_aPath[i + 1].y, m_fLineSize);
	}
}

void FourierDrawing::Start()
{
	vector<float> drawingX;
	vector<float> drawingY;
	for (int i = 0; i < m_aDrawing.size(); ++i)
	{
		drawingX.push_back(m_aDrawing[i].x);
		drawingY.push_back(m_aDrawing[i].y);
	};
	auto fourierX = DFT(drawingX);
	auto fourierY = DFT(drawingY);

	Vector2 v2Pos = m_v2EpicycleXCenter;
	for each (WaveData var in fourierX)
	{
		var.fAmp *= m_fRadiusMultiplier;

		Epicycle* pTemp = new Epicycle(v2Pos, var);
		m_apEpicyclesX.insert(m_apEpicyclesX.begin(), pTemp);

		v2Pos.x += var.fAmp * 1;	//cos(0) = 1
		v2Pos.y += var.fAmp * 0;	//sin(0) = 0
	}

	v2Pos = m_v2EpicycleYCenter;
	for each (WaveData var in fourierY)
	{
		var.fAmp *= m_fRadiusMultiplier;
		var.fPhaseOffset = (float)M_PI_2;

		Epicycle* pTemp = new Epicycle(v2Pos, var);
		m_apEpicyclesY.insert(m_apEpicyclesY.begin(), pTemp);

		v2Pos.x += var.fAmp * 1;	//cos(0) = 1
		v2Pos.y += var.fAmp * 0;	//sin(0) = 0
	}
}

void FourierDrawing::DestroyEpicycles()
{
	while (m_apEpicyclesX.size() > 0)
	{
		delete m_apEpicyclesX.back();
		m_apEpicyclesX.pop_back();
	}

	while (m_apEpicyclesY.size() > 0)
	{
		delete m_apEpicyclesY.back();
		m_apEpicyclesY.pop_back();
	}
}

void FourierDrawing::DefaultDrawing()
{
	m_aDrawing.push_back(Vector2(-100.0f, 100.0f));
	m_aDrawing.push_back(Vector2(100.0f, 100.0f));
	//m_aDrawing.push_back(Vector2(100.0f, -100.0f));
	//m_aDrawing.push_back(Vector2(-100.0f, -100.0f));
}

vector<WaveData> FourierDrawing::DFT(vector<float>& in)
{
	vector<WaveData> result;

	int size = in.size();
	for (int k = 0; k < size; ++k)
	{
		float re = 0.0f;
		float im = 0.0f;
		for (int n = 0; n < size; ++n)
		{
			float phi = ((float)M_2_PI * k * n) / size;
			re += in[n] * cosf(phi);
			im += in[n] * sinf(phi);
		}
		re /= size;
		im /= size;

		WaveData data;
		data.fFreq = k;
		data.fAmp = sqrtf(re * re + im * im);
		data.fPhase = atan2(im, re);

		result.push_back(data);
	}

	return result;
}
