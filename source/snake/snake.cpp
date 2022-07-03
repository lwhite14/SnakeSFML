#include "snake.h"
#include <iostream>

Snake::Snake(int posX, int posY)
{
	m_direction = {false, true, false, false};
	m_prevDirection = {false, true, false, false};

	m_maxMoveTime = 0.55f;
	m_moveTime = m_maxMoveTime;
	m_speedUpAmount = 0.98f;
	m_isDead = false;

	m_textures = vector<Texture>(14);
	m_sprites = vector<Sprite>(14);

	m_textures[0].loadFromFile("media/textures/snake-body-bottomright.png");
	m_sprites[0].setTexture(m_textures[0]);
	m_sprites[0].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[1].loadFromFile("media/textures/snake-body-leftbottom.png");
	m_sprites[1].setTexture(m_textures[1]);
	m_sprites[1].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[2].loadFromFile("media/textures/snake-body-leftright.png");
	m_sprites[2].setTexture(m_textures[2]);
	m_sprites[2].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[3].loadFromFile("media/textures/snake-body-topbottom.png");
	m_sprites[3].setTexture(m_textures[3]);
	m_sprites[3].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[4].loadFromFile("media/textures/snake-body-topleft.png");
	m_sprites[4].setTexture(m_textures[4]);
	m_sprites[4].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[5].loadFromFile("media/textures/snake-body-topright.png");
	m_sprites[5].setTexture(m_textures[5]);
	m_sprites[5].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[6].loadFromFile("media/textures/snake-head-down.png");
	m_sprites[6].setTexture(m_textures[6]);
	m_sprites[6].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[7].loadFromFile("media/textures/snake-head-left.png");
	m_sprites[7].setTexture(m_textures[7]);
	m_sprites[7].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[8].loadFromFile("media/textures/snake-head-right.png");
	m_sprites[8].setTexture(m_textures[8]);
	m_sprites[8].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[9].loadFromFile("media/textures/snake-head-up.png");
	m_sprites[9].setTexture(m_textures[9]);
	m_sprites[9].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[10].loadFromFile("media/textures/snake-tail-down.png");
	m_sprites[10].setTexture(m_textures[10]);
	m_sprites[10].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[11].loadFromFile("media/textures/snake-tail-left.png");
	m_sprites[11].setTexture(m_textures[11]);
	m_sprites[11].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[12].loadFromFile("media/textures/snake-tail-right.png");
	m_sprites[12].setTexture(m_textures[12]);
	m_sprites[12].setScale(Vector2f(0.3125f, 0.3125f));

	m_textures[13].loadFromFile("media/textures/snake-tail-up.png");
	m_sprites[13].setTexture(m_textures[13]);
	m_sprites[13].setScale(Vector2f(0.3125f, 0.3125f));

	m_head = SnakePart(Vector2f(posX, posY), m_sprites[0], nullptr, new Direction{ true, false, false, false });
	m_body = vector<SnakePart>
	{
		SnakePart(Vector2f(posX, posY - 1), m_sprites[1], new Direction{ false, true, false, false }, new Direction{ true, false, false, false }),
		SnakePart(Vector2f(posX, posY - 2), m_sprites[1], new Direction{ false, true, false, false }, new Direction{ true, false, false, false }),
		SnakePart(Vector2f(posX, posY - 3), m_sprites[1], new Direction{ false, true, false, false }, nullptr)
	};

	UpdateSprites();
}

void Snake::Update(const Time& deltaTime)
{
	if (!m_isDead) 
	{
		m_moveTime -= deltaTime.asSeconds();
		if (m_moveTime < 0)
		{
			m_moveTime = m_maxMoveTime;

			Move();
			UpdateSprites();
		}
	}
}

void Snake::Render(RenderWindow& window)
{
	if (!m_isDead)
	{
		m_head.Render(window);
		for (unsigned int i = 0; i < m_body.size(); i++)
		{
			m_body[i].Render(window);
		}
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
	m_body.push_back(SnakePart(Vector2f(m_body[m_body.size() - 1].GetPosition().x, m_body[m_body.size() - 1].GetPosition().y), m_body[m_body.size() - 1].GetSprite()));
}

void Snake::IncreaseSpeed() 
{
	m_maxMoveTime *= m_speedUpAmount;
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
	m_prevDirection = m_direction;

	vector<SnakePart> tempBody = m_body;
	for (unsigned int i = 0; i < m_body.size(); i++)
	{
		if (i == 0)
		{
			tempBody[i].SetPosition(m_head.GetPosition());
			tempBody[i].SetInfrontDirection(new Direction{m_direction.up, m_direction.down, m_direction.left, m_direction.right});
			tempBody[i].SetBehindDirection(new Direction{m_head.GetBehindDirection().up, m_head.GetBehindDirection().down, m_head.GetBehindDirection().left, m_head.GetBehindDirection().right});
		}
		else
		{
			tempBody[i].SetPosition(m_body[i - 1].GetPosition());

			tempBody[i].SetInfrontDirection(new Direction{ m_body[i - 1].GetInfrontDirection().up, m_body[i - 1].GetInfrontDirection().down, m_body[i - 1].GetInfrontDirection().left, m_body[i - 1].GetInfrontDirection().right });
			
			
			if (i == m_body.size() - 1) 
			{
				tempBody[i].SetBehindDirection(nullptr);
			}
			else 
			{
				tempBody[i].SetBehindDirection(new Direction{ m_body[i - 1].GetBehindDirection().up, m_body[i - 1].GetBehindDirection().down, m_body[i - 1].GetBehindDirection().left, m_body[i - 1].GetBehindDirection().right });
			}
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
	if (m_prevDirection.up) { m_head.SetBehindDirection(new Direction{ false, true, false, false }); }
	if (m_prevDirection.down) { m_head.SetBehindDirection(new Direction{ true, false, false, false }); }
	if (m_prevDirection.left) { m_head.SetBehindDirection(new Direction{ false, false, false, true }); }
	if (m_prevDirection.right) { m_head.SetBehindDirection(new Direction{ false, false, true, false }); }
}

void Snake::SwitchUp() 
{
	if (!m_prevDirection.down)
	{
		m_direction.up = true;
		m_direction.down = false;
		m_direction.left = false;
		m_direction.right = false;
	}
}

void Snake::SwitchDown()
{
	if (!m_prevDirection.up)
	{
		m_direction.up = false;
		m_direction.down = true;
		m_direction.left = false;
		m_direction.right = false;
	}
}

void Snake::SwitchLeft()
{
	if (!m_prevDirection.right)
	{
		m_direction.up = false;
		m_direction.down = false;
		m_direction.left = true;
		m_direction.right = false;
	}
}

void Snake::SwitchRight()
{
	if (!m_prevDirection.left)
	{
		m_direction.up = false;
		m_direction.down = false;
		m_direction.left = false;
		m_direction.right = true;
	}
}

void Snake::UpdateSprites() 
{
	if (m_head.GetBehindDirection().up) 
	{
		m_head.SetSprite(m_sprites[6]);
	}	
	if (m_head.GetBehindDirection().down)
	{
		m_head.SetSprite(m_sprites[9]);
	}	
	if (m_head.GetBehindDirection().left)
	{
		m_head.SetSprite(m_sprites[8]);
	}	
	if (m_head.GetBehindDirection().right)
	{
		m_head.SetSprite(m_sprites[7]);
	}


	for (unsigned int i = 0; i < m_body.size(); i++)
	{
		if (m_body[i].GetInfrontDirection().up) 
		{
			if (m_body[i].GetBehindDirectionPtr() != nullptr) 
			{
				if (m_body[i].GetBehindDirection().down) { m_body[i].SetSprite(m_sprites[3]); }
				if (m_body[i].GetBehindDirection().left) { m_body[i].SetSprite(m_sprites[4]); }
				if (m_body[i].GetBehindDirection().right) { m_body[i].SetSprite(m_sprites[5]); }
			}
			else 
			{
				m_body[i].SetSprite(m_sprites[10]);
			}
		}
		if (m_body[i].GetInfrontDirection().down) 
		{ 
			if (m_body[i].GetBehindDirectionPtr() != nullptr) 
			{
				if (m_body[i].GetBehindDirection().up) { m_body[i].SetSprite(m_sprites[3]); }
				if (m_body[i].GetBehindDirection().left) { m_body[i].SetSprite(m_sprites[1]); }
				if (m_body[i].GetBehindDirection().right) { m_body[i].SetSprite(m_sprites[0]); }
			}
			else
			{
				m_body[i].SetSprite(m_sprites[13]);
			}
		}
		if (m_body[i].GetInfrontDirection().left) 
		{
			if (m_body[i].GetBehindDirectionPtr() != nullptr) 
			{
				if (m_body[i].GetBehindDirection().up) { m_body[i].SetSprite(m_sprites[4]); }
				if (m_body[i].GetBehindDirection().down) { m_body[i].SetSprite(m_sprites[1]); }
				if (m_body[i].GetBehindDirection().right) { m_body[i].SetSprite(m_sprites[2]); }
			}
			else
			{
				m_body[i].SetSprite(m_sprites[12]);
			}
		}
		if (m_body[i].GetInfrontDirection().right) 
		{
			if (m_body[i].GetBehindDirectionPtr() != nullptr) 
			{
				if (m_body[i].GetBehindDirection().up) { m_body[i].SetSprite(m_sprites[5]); }
				if (m_body[i].GetBehindDirection().down) { m_body[i].SetSprite(m_sprites[0]); }
				if (m_body[i].GetBehindDirection().left) { m_body[i].SetSprite(m_sprites[2]); }
			}
			else
			{
				m_body[i].SetSprite(m_sprites[11]);
			}
		}
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

void Snake::SetIsDead(bool isDead) 
{
	m_isDead = isDead;
}
