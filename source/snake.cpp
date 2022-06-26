#include "snake.h"
#include <iostream>

Snake::Snake(int posX, int posY) : m_MOVETIME(0.75f)
{
	m_rectangle = RectangleShape(Vector2f(20.0f, 20.0f));
	m_rectangle.setFillColor(sf::Color::Green);
	m_rectangle.setPosition(0, 0);

	m_direction = {false, true, false, false};

	m_posX = posX;
	m_posY = posY;

	m_moveTime = m_MOVETIME;
	m_speedUpAmount = 0.015f;
}

void Snake::Update(Time deltaTime)
{
	m_moveTime -= deltaTime.asSeconds();
	if (m_moveTime < 0) 
	{
		Move();
		m_moveTime = m_MOVETIME;
	}
}

void Snake::Render(sf::RenderWindow& window)
{
	float trueX, trueY;
	trueX = m_posX * 20;
	trueY = m_posY * 20;
	m_rectangle.setPosition(trueX, trueY);
	window.draw(m_rectangle);
}

void Snake::Input(Event& event) 
{
	if (event.key.code == Keyboard::W)
	{
		SwitchUp();
	}
	if (event.key.code == Keyboard::S)
	{
		SwitchDown();
	}
	if (event.key.code == Keyboard::A)
	{
		SwitchLeft();
	}
	if (event.key.code == Keyboard::D)
	{
		SwitchRight();
	}
}

void Snake::Move() 
{
	if (m_direction.up) 
	{
		m_posY -= 1;
	}
	if (m_direction.down) 
	{
		m_posY += 1;
	}
	if (m_direction.left) 
	{
		m_posX -= 1;
	}
	if (m_direction.right) 
	{
		m_posX += 1;
	}
}

void Snake::SwitchUp() 
{
	m_direction.up = true;
	m_direction.down = false;
	m_direction.left = false;
	m_direction.right = false;
}

void Snake::SwitchDown()
{
	m_direction.up = false;
	m_direction.down = true;
	m_direction.left = false;
	m_direction.right = false;
}

void Snake::SwitchLeft()
{
	m_direction.up = false;
	m_direction.down = false;
	m_direction.left = true;
	m_direction.right = false;
}

void Snake::SwitchRight()
{
	m_direction.up = false;
	m_direction.down = false;
	m_direction.left = false;
	m_direction.right = true;
}
