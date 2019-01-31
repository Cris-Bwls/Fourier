#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

#define CIRCLE_COUNT 1000

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	auto SeriesFunc = [](int iter)->WaveData
	{
		WaveData data;
		data.fFreq = float(iter + 1);
		float var = -data.fFreq;

		if (iter % 2)
			var *= -1;

		data.fAmp = (2.0f / (var * 3.14f));

		return data;
	};

	m_pFourierSeries = new FourierSeries(CIRCLE_COUNT , SeriesFunc);
	
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_pFourierSeries;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	m_pFourierSeries->Update(deltaTime);

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_pFourierSeries->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}