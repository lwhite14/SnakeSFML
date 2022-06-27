#include "grub.h"
#include <stdlib.h>
#include <time.h>

Grub::Grub() { }

Grub::Grub(Vector2f position, Color color, RectangleShape rectangle)
{
	m_position = position;
	m_color = color;
	m_rectangle = rectangle;

	m_rectangle = RectangleShape(Vector2f(20.0f, 20.0f));
	m_rectangle.setFillColor(m_color);
	m_rectangle.setPosition(m_position.x, m_position.y);
}


void Grub::Update(const Time& deltaTime)
{

}

void Grub::Render(RenderWindow& window)
{
	float trueX, trueY;
	trueX = m_position.x * 20;
	trueY = m_position.y * 20;
	m_rectangle.setPosition(trueX, trueY);
	window.draw(m_rectangle);
}

void Grub::SetPosition(Vector2f newPosition)
{
	m_position = newPosition;
}

Vector2f Grub::GetPosition()
{
	return m_position;
}

void Grub::NewPosition(std::vector<Vector2f>& notAllowed)
{
	srand(time(NULL));
	bool foundNewPosition = false;
	Vector2f newPos = Vector2f(0, 0);
	while (!foundNewPosition)
	{
		int newX = rand() % 20 + 0;
		int newY = rand() % 20 + 0;
		newPos = Vector2f(newX, newY);
		foundNewPosition = true;
		for (unsigned int i = 0; i < notAllowed.size(); i++)
		{
			if (notAllowed[i] == newPos) 
			{
				foundNewPosition = false;
			}
		}
	}
	SetPosition(newPos);
}
