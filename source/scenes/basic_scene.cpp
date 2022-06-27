#include "basic_scene.h"
#include <iostream>

BasicScene::BasicScene() : 
		snake(new Snake(6, 5)), 
		grub(new Grub(Vector2f(10, 10), Color(255, 255, 0), RectangleShape(Vector2f(20.0f, 20.0f)))),
		gameUI(new GameUI())
{

}

void BasicScene::Init(RenderWindow* window)
{
	m_window = window;
}

void BasicScene::Update(const Time& deltaTime)
{
	grub->Update(deltaTime);
	snake->Update(deltaTime);
	gameUI->Update();
	if (grub->GetPosition() == snake->GetHeadPosition()) 
	{
		vector<Vector2f> tempVector = snake->GetBodyPosition();
		grub->NewPosition(tempVector);
		snake->AddBody();
		snake->IncreaseSpeed();
		gameUI->IncreaseScore();
	}

	if (snake->OffScreen() || snake->EatenTail())
	{
		GameOver();
	}
}

void BasicScene::Render()
{
	grub->Render(*m_window);
	snake->Render(*m_window);
	gameUI->Render(*m_window);
}

void BasicScene::Input()
{
	Event event;
	while (m_window->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_window->close();
		}
		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Escape)
			{
				m_window->close();
			}

			snake->Input(event);
			gameUI->Input(event, this);
		}
	}
}

void BasicScene::GameOver() 
{
	snake->SetIsDead(true);
	gameUI->SetGameOver(true);
}

void BasicScene::RestartScene()
{
	snake = new Snake(6, 5);
	grub = new Grub(Vector2f(10, 10), Color(255, 255, 0), RectangleShape(Vector2f(20.0f, 20.0f)));
	gameUI = new GameUI();
}