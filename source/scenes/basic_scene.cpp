#include "basic_scene.h"
#include <iostream>

BasicScene::BasicScene() : snake(new Snake(6, 5))
{

}

void BasicScene::Init()
{

}

void BasicScene::Update(const Time& deltaTime)
{
	snake->Update(deltaTime);
}

void BasicScene::Render(RenderWindow& window)
{
	snake->Render(window);
}

void BasicScene::Input(RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
		}
		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Escape)
			{
				window.close();
			}

			snake->Input(event);
		}
	}
}