#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include <SFML/Graphics.hpp>
#include "game.h"

class TestScene : public Scene
{
public:
    
    TestScene(const std::string&);

    ~TestScene();

    void init();

    void activate();

    void deactivate();

    void update();

    void draw();

    void cleanup();

private:
    sf::RenderWindow& m_window;
    SceneManager* m_sceneMan;

    Player m_player;    
};

#endif //TEST_SCENE_H

