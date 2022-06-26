#include "snake.h"
#include <iostream>

Snake::Snake(int posX, int posY)
{
	m_direction = {false, true, false, false};

	m_maxMoveTime = 0.55f;
	m_moveTime = m_maxMoveTime;
	m_speedUpAmount = 0.015f;

	m_head = SnakePart(Vector2f(posX, posY), Color(0, 255, 0), RectangleShape(Vector2f(20.0f, 20.0f)));
	m_body = vector<SnakePart>
	{
		SnakePart(Vector2f(posX, posY - 1), Color(0, 125, 0), RectangleShape(Vector2f(20.0f, 20.0f))),
		SnakePart(Vector2f(posX, posY - 2), Color(0, 125, 0), RectangleShape(Vector2f(20.0f, 20.0f))),
		SnakePart(Vector2f(posX, posY - 3), Color(0, 125, 0), RectangleShape(Vector2f(20.0f, 20.0f)))
	};
}

void Snake::Update(const Time& deltaTime)
{
	m_moveTime -= deltaTime.asSeconds();
	if (m_moveTime < 0) 
	{
		Move();
		m_moveTime = m_maxMoveTime;
	}
}

void Snake::Render(sf::RenderWindow& window)
{
	m_head.Render(window);
	for (unsigned int i = 0; i < m_body.size(); i++) 
	{
		m_body[i].Render(window);
	}
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

void Snake::AddBody() 
{
	m_body.push_back(SnakePart(Vector2f(m_body[m_body.size() - 1].GetPosition().x, m_body[m_body.size() - 1].GetPosition().y), Color(0, 125, 0), RectangleShape(Vector2f(20.0f, 20.0f))));
}

void Snake::IncreaseSpeed() 
{
	m_maxMoveTime -= m_speedUpAmount;
}

bool Snake::OffScreen() 
{
	bool output = false;
	Vector2f headPosition = GetHeadPosition();
	if (headPosition.x > 19 || headPosition.x < 0 || headPosition.y > 19 || headPosition.y < 0) 
	{
		output = true;
	}
	return output;
}

bool Snake::EatenTail() 
{
	bool output = false;
	vector<Vector2f> bodyPositions = GetBodyPosition();
	Vector2f headPosition = GetHeadPosition();

	for (unsigned int i = 0; i < bodyPositions.size(); i++) 
	{
		if (bodyPositions[i] == headPosition) 
		{
			output = true;
		}
	}

	return output;
}

void Snake::Move() 
{
	vector<SnakePart> tempBody = m_body;
	for (unsigned int i = 0; i < m_body.size(); i++)
	{
		if (i == 0)
		{
			tempBody[i].SetPosition(m_head.GetPosition());
		}
		else
		{
			tempBody[i].SetPosition(m_body[i - 1].GetPosition());
		}
	}
	m_body = tempBody;


	Vector2f toAdd = Vector2f(0, 0);
	if (m_direction.up) 
	{
		toAdd.y = -1;
	}
	if (m_direction.down) 
	{
		toAdd.y = 1;
	}
	if (m_direction.left) 
	{
		toAdd.x = -1;
	}
	if (m_direction.right) 
	{
		toAdd.x = 1;
	}
	m_head.Move(toAdd);
}

void Snake::SwitchUp() 
{
	if (!m_direction.down) 
	{
		m_direction.up = true;
		m_direction.down = false;
		m_direction.left = false;
		m_direction.right = false;
	}
}

void Snake::SwitchDown()
{
	if (!m_direction.up)
	{
		m_direction.up = false;
		m_direction.down = true;
		m_direction.left = false;
		m_direction.right = false;
	}
}

void Snake::SwitchLeft()
{
	if (!m_direction.right)
	{
		m_direction.up = false;
		m_direction.down = false;
		m_direction.left = true;
		m_direction.right = false;
	}
}

void Snake::SwitchRight()
{
	if (!m_direction.left)
	{
		m_direction.up = false;
		m_direction.down = false;
		m_direction.left = false;
		m_direction.right = true;
	}
}

Vector2f Snake::GetHeadPosition() 
{
	return m_head.GetPosition();
}

vector<Vector2f> Snake::GetBodyPosition()
{
	vector<Vector2f> output;
	for (unsigned int i = 0; i < m_body.size(); i++) 
	{
		output.push_back(m_body[i].GetPosition());
	}
	return output;
}
