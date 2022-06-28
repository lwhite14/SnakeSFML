#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class SnakePart
{
private:
	Color m_color;
	RectangleShape m_rectangle;
	Vector2f m_position;
	float m_margin;

public:
	SnakePart() { }

	SnakePart(Vector2f position, Color color, RectangleShape rectangle, float margin = 0.0f)
	{
		m_position = position;
		m_color = color;
		m_rectangle = rectangle;
		m_rectangle.setSize(Vector2f(m_rectangle.getSize().x - (margin * 2), m_rectangle.getSize().y - (margin * 2)));

		m_rectangle.setFillColor(m_color);
		m_rectangle.setPosition(m_position.x, m_position.y);

		m_margin = margin;
	}

	void Render(RenderWindow& window) 
	{
		float trueX, trueY;
		trueX = m_position.x * 20;
		trueY = m_position.y * 20;
		trueX += m_margin;
		trueY += m_margin;
		m_rectangle.setPosition(trueX, trueY);
		window.draw(m_rectangle);
	}

	void Move(Vector2f toAdd) 
	{
		m_position += toAdd;
	}

	void SetPosition(Vector2f newPosition) 
	{
		m_position = newPosition;
	}

	Vector2f GetPosition() 
	{
		return m_position;
	}
};