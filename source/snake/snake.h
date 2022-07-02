#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "direction.h"
#include "snake_part.h"

using namespace sf;
using namespace std;

class Snake
{
private:
	Direction m_direction;
	Direction m_prevDirection;
	float m_maxMoveTime;
	float m_moveTime;
	float m_speedUpAmount;
	bool m_isDead;

	vector<Texture> m_textures;
	vector<Sprite> m_sprites;

	SnakePart m_head;
	vector<SnakePart> m_body;

	void Move();
	void SwitchUp();
	void SwitchDown();
	void SwitchLeft();
	void SwitchRight();
	void UpdateSprites();
public:
	Snake(int posX, int posY);

	void Update(const Time& deltaTime);
	void Render(RenderWindow& window);
	void Input(Event& event);
	void AddBody();
	void IncreaseSpeed();

	bool OffScreen();
	bool EatenTail();

	Vector2f GetHeadPosition();
	vector<Vector2f> GetBodyPosition();

	void SetIsDead(bool isDead);
};