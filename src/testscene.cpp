#include "testscene.h"

TestScene::TestScene(const std::string& sceneId) :
    Scene(sceneId),
    m_window(Game::instance()->getWindow()),
    m_sceneMan(SceneManager::instance()),
    m_player()
{
    setBackgroundColour(sf::Color::Blue);
}

TestScene::~TestScene()
{
}

void TestScene::init()
{
    m_player.setTexture("assets/player.png");
    m_player.setMoveSpeed(1.0f);
    m_player.setPosition(m_window.getSize().x/2, m_window.getSize().y/2);
}

void TestScene::activate()
{
}

void TestScene::deactivate()
{
}


void TestScene::update()
{
    m_player.update();
}

void TestScene::draw()
{
    m_window.draw(m_player);
}

void TestScene::cleanup()
{
}
