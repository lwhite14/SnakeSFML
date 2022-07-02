#pragma once

#include <SFML/Graphics.hpp>
#include "direction.h"

using namespace sf;

class SnakePart
{
private:
	Vector2f m_position;
	Sprite m_sprite;
	Direction* m_infrontDirection;
	Direction* m_behindDirection;

public:
	SnakePart() { }

	SnakePart(Vector2f position, Sprite sprite)
	{
		m_position = position;
		SetSprite(sprite);

		m_infrontDirection = nullptr;
		m_behindDirection = nullptr;
	}

	void Render(RenderWindow& window) 
	{
		float trueX, trueY;
		trueX = m_position.x * 20;
		trueY = m_position.y * 20;
		m_sprite.setPosition(trueX, trueY);
		window.draw(m_sprite);
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

	void SetSprite(Sprite sprite) 
	{
		m_sprite = sprite;
		m_sprite.setScale(Vector2f(0.3125f, 0.3125f));
	}

	Sprite GetSprite()
	{
		return m_sprite;
	}

	void SetBehindDirection(Direction& direction) 
	{
		m_behindDirection = &direction;
	}

	Direction GetBehindDirection() 
	{
		return *m_behindDirection;
	}

	void SetInfrontDirection(Direction& direction)
	{
		m_infrontDirection = &direction;
	}

	Direction GetInfrontDirection()
	{
		return *m_infrontDirection;
	}
};