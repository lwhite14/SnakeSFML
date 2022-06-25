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
		scene->Init();

		MainLoop(scene);
		return 0;
	}

private:
	int m_width, m_height;
	RenderWindow m_window;

	void MainLoop(Scene* scene) 
	{
		while (m_window.isOpen())
		{
			Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == Event::Closed) 
				{
					m_window.close();
				}
			}

			scene->Update();

			m_window.clear();
			scene->Render(m_window);
			m_window.display();
		}
	}
};