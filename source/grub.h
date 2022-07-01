#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Grub 
{
private:
	Color m_color;
	Vector2f m_position;
	Texture m_texture;
	Sprite m_sprite;

public:
	Grub();
	Grub(Vector2f position, Color color, const char* textureFile);
	void Update(const Time& deltaTime);
	void Render(RenderWindow& window);
	void SetPosition(Vector2f newPosition);
	Vector2f GetPosition();
	void NewPosition(std::vector<Vector2f>& notAllowed);
};