#include "basic_scene.h"

BasicScene::BasicScene() { }

void BasicScene::Init()
{
	m_circle = CircleShape(100.0f);
	m_circle.setFillColor(sf::Color::Green);
	m_circle.setPosition((m_width / 2) - 100.0f, (m_height / 2) - 100.0f);
}

void BasicScene::Update()
{

}

void BasicScene::Render(sf::RenderWindow& window)
{
	window.draw(m_circle);
}