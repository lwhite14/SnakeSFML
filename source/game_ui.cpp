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
	FloatRect textRect = m_scoreText.getLocalBounds();
	m_scoreText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_scoreText.setPosition(Vector2f(400 / 2.0f, (textRect.height / 2) + 4));

	m_gameOverText.setString("Game Over     Press   R   to Restart");
	m_gameOverText.setCharacterSize(18);
	m_gameOverText.setFillColor(Color(255, 0, 0));
	textRect = m_gameOverText.getLocalBounds();
	m_gameOverText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_gameOverText.setPosition(Vector2f(400 / 2.0f, 400 / 2.0));
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

void GameUI::Input(Event& event, Scene* scene)
{
	if (event.key.code == Keyboard::R)
	{
		if (m_gameOver) 
		{
			scene->RestartScene();
		}
	}
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
