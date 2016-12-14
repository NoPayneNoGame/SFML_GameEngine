#ifndef GAME_H
#define GAME_H

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "scenemanager.h"

class Game : sf::NonCopyable
{
    static Game* m_instance;

public:
    
    static const unsigned int DEF_WIN_WIDTH = 800;
    static const unsigned int DEF_WIN_HEIGHT = 600;
    static const unsigned int DEF_WIN_BPP = 32;
    
    static Game* instance();

    static void release();

    sf::RenderWindow& getWindow();

    bool isRunning() const;

    void quit(sf::Int16);

    void setFirstScene(Scene*);

    sf::Int16 run();

private:
    sf::RenderWindow m_window;
    
    bool m_running;
    
    sf::Int16 m_exitCode;
    
    Scene* m_startScene;
    SceneManager* m_sceneMan;

    Game();
    ~Game();
    
    void createWindow();

    void init();

    void gameLoop();

    void cleanup();
};

#endif //GAME_H
