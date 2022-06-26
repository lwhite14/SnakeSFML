#include "basic_scene.h"
#include <iostream>

BasicScene::BasicScene() : 
		snake(new Snake(6, 5)), 
		grub(new Grub(Vector2f(10, 10), Color(255, 255, 0), RectangleShape(Vector2f(20.0f, 20.0f))))
{

}

void BasicScene::Init()
{
	grub->Init();
}

void BasicScene::Update(const Time& deltaTime)
{
	grub->Update(deltaTime);
	snake->Update(deltaTime);
	if (grub->GetPosition() == snake->GetHeadPosition()) 
	{
		vector<Vector2f> tempVector = snake->GetBodyPosition();
		grub->NewPosition(tempVector);
	}
}

void BasicScene::Render(RenderWindow& window)
{
	grub->Render(window);
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