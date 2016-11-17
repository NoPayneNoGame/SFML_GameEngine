#include "testscene.h"

TestScene::TestScene(const std::string& sceneId) :
    Scene(sceneId),
    m_window(Game::instance()->getWindow()),
    m_sceneMan(SceneManager::instance())
{
    this->setBackgroundColour(sf::Color::Red);
}

TestScene::~TestScene()
{
}

void TestScene::init()
{
    //this->m_player.setWindow(this->m_window);
    this->m_player.setTexture("assets/player.png");
    this->m_player.setSpeed(1);
    this->m_player.setPosition(this->m_window.getSize().x/2, this->m_window.getSize().y/2);
}

void TestScene::activate()
{
}

void TestScene::deactivate()
{
}


void TestScene::update()
{
    this->m_player.update();
}

void TestScene::draw()
{
    m_window.draw(m_player);
}

void TestScene::cleanup()
{
}
