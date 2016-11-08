#ifndef GAME_H
#define GAME_H

#pragma once

#include <SFML/Graphics.hpp>

class Game : sf::NonCopyable
{
    static Game* singleton;

public:
    
    static const unsigned int DEF_WIN_WIDTH = 800;
    static const unsigned int DEF_WIN_HEIGHT = 600;
    static const unsigned int DEF_WIN_BPP = 32;
    
    static Game* instance();

    static void release();

    sf::RenderWindow& getWindow();

    bool isRunning() const;

    void quit(sf::Int16 exitCode);

    sf::Int16 run();

private:
    sf::RenderWindow m_window;
    
    bool m_running;
    
    sf::Int16 m_exitCode;

    Game();
    ~Game();
    
    void createWindow();

    void init();

    void gameLoop();

    void cleanup();
};

#endif //GAME_H
