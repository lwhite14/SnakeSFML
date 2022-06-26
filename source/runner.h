#pragma once

#include <SFML/Graphics.hpp>
#include "scenes/scene.h"

using namespace sf;

class Runner 
{
public:
	Runner(int width, int height, const char* windowTitle) :

		m_width(width),
		m_height(height),
		m_window(VideoMode(width, height), windowTitle)
	{

	}

	int Run(Scene* scene) 
	{
		scene->SetDimensions(m_width, m_height);
		scene->Init(&m_window);

		MainLoop(scene);
		return 0;
	}

private:
	int m_width, m_height;
	RenderWindow m_window;

	void MainLoop(Scene* scene) 
	{
		Clock clock;
		while (m_window.isOpen())
		{
			Time elapsed = clock.restart();

			scene->Input();
			scene->Update(elapsed);

			m_window.clear();
			scene->Render();
			m_window.display();
		}
	}
};