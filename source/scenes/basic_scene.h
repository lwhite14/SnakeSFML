#pragma once

#include <SFML/Graphics.hpp>
#include "scene.h"
#include "../snake/snake.h"
#include "../grub.h"

using namespace sf;

class BasicScene : public Scene
{
private:
	Snake* snake;
	Grub* grub;

public:
	BasicScene();
	void Init();
	void Update(const Time& deltaTime);
	void Render(sf::RenderWindow& window);
	void Input(RenderWindow& window);
};