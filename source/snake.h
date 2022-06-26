#pragma once

#include <SFML/Graphics.hpp>
#include "direction.h"

using namespace sf;

class Snake
{
private:
	RectangleShape m_rectangle;
	Direction m_direction;
	const float m_MOVETIME;
	int m_posX;
	int m_posY;
	float m_moveTime;
	float m_speedUpAmount;

	void Move();
	void SwitchUp();
	void SwitchDown();
	void SwitchLeft();
	void SwitchRight();
public:
	Snake(int posX, int posY);
	void Update(Time deltaTime);
	void Render(sf::RenderWindow& window);
	void Input(Event& event);
};