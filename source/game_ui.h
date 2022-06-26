#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

class GameUI 
{
private:
	Font m_font;
	Text m_scoreText;
	Text m_gameOverText;
	int m_score;
	bool m_gameOver;

public:
	GameUI();
	void Update();
	void Render(RenderWindow& window);
	void IncreaseScore();
	void SetGameOver(bool gameOver);
};