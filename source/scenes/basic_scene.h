#pragma once

#include <SFML/Graphics.hpp>
#include "scene.h"
#include "../snake/snake.h"

using namespace sf;

class BasicScene : public Scene
{
private:
	Snake* snake;

public:
	BasicScene();
	void Init();
	void Update(const Time& deltaTime);
	void Render(sf::RenderWindow& window);
	void Input(RenderWindow& window);
};