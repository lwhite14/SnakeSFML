#include "game_ui.h"



GameUI::GameUI()
{
	m_score = 0;
	m_gameOver = false;

	if (!m_font.loadFromFile("media/arcadeclassic.ttf"))
	{
		cout << "ERROR LOADING FONT FILE" << endl;
	}
	m_scoreText.setFont(m_font);
	m_gameOverText.setFont(m_font);


	m_scoreText.setString("Score 0");
	m_scoreText.setCharacterSize(24);
	m_scoreText.setFillColor(Color(255, 255, 255));
	m_scoreText.setPosition(150, 0);

	m_gameOverText.setString("Game Over");
	m_gameOverText.setCharacterSize(24);
	m_gameOverText.setFillColor(Color(255, 0, 0));
	m_gameOverText.setPosition(130, 190);
}

void GameUI::Update()
{

}

void GameUI::Render(RenderWindow& window)
{
	window.draw(m_scoreText);
	if (m_gameOver)
		window.draw(m_gameOverText);
}

void GameUI::IncreaseScore() 
{ 
	m_score += 1; 
	string tempString = "Score " + to_string(m_score);
	m_scoreText.setString(tempString);
}

void GameUI::SetGameOver(bool gameOver) 
{
	m_gameOver = gameOver;
}
