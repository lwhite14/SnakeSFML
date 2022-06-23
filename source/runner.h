#pragma once

#include <SFML/Graphics.hpp>
#include "scenes/scene.h"

using namespace sf;

class Runner 
{
public:
	Runner(int width, int height, const char* windowTitle) :
		window(VideoMode(width, height), windowTitle),
		shape(100.0f)
	{
		shape.setFillColor(Color::Green);
		shape.setPosition((width / 2) - 100.0f, (height / 2) - 100.0f);
	}

	int Run(Scene* scene) 
	{
		MainLoop(scene);
		return 0;
	}

private:
	RenderWindow window;
	CircleShape shape;

	void MainLoop(Scene* scene) 
	{
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed) 
				{
					window.close();
				}
			}

			window.clear();
			window.draw(shape);
			window.display();
		}
	}
};