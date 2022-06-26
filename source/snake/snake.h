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
	const float m_MOVETIME;
	float m_moveTime;
	float m_speedUpAmount;

	SnakePart m_head;
	vector<SnakePart> m_body;

	void Move();
	void SwitchUp();
	void SwitchDown();
	void SwitchLeft();
	void SwitchRight();
public:
	Snake(int posX, int posY);

	void Update(const Time& deltaTime);
	void Render(RenderWindow& window);
	void Input(Event& event);
	void AddBody();

	bool OffScreen();
	bool EatenTail();

	Vector2f GetHeadPosition();
	vector<Vector2f> GetBodyPosition();
};