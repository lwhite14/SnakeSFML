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

	void GameOver();
public:
	BasicScene();
	void Init(RenderWindow* window);
	void Update(const Time& deltaTime);
	void Render();
	void Input();
};