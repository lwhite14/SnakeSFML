#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Scene 
{
protected:
	int m_width, m_height;

public:
	virtual void Init() = 0;
	virtual void Update(const sf::Time& deltaTime) = 0;
	virtual void Render(sf::RenderWindow& window) = 0;
	virtual void Input(sf::RenderWindow& window) = 0;
	void SetDimensions(int width, int height) 
	{
		m_width = width;
		m_height = height;
	}
};