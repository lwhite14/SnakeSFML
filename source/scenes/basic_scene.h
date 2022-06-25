#pragma once

#include <SFML/Graphics.hpp>
#include "scene.h"

using namespace sf;

class BasicScene : public Scene
{
private:
	CircleShape m_circle;

public:
	BasicScene();
	void Init();
	void Update();
	void Render(sf::RenderWindow& window);
};