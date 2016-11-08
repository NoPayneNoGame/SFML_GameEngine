#include "game.h"

Game* Game::singleton = 0;

Game::Game() :
    m_window(),
    m_exitCode(0),
    m_running(false)
{

    //probably do some logging stuff later
}

Game::~Game()
{
}

//Public
Game* Game::instance()
{
    if(singleton == 0)
    {
        singleton = new Game();
    }
    return singleton;
}

void Game::release()
{
    if(singleton)
    {
        delete singleton;
    }
    singleton = 0;
}

sf::RenderWindow& Game::getWindow()
{
    return this->m_window;
}

bool Game::isRunning() const
{
    return this->m_running;
}

void Game::quit(sf::Int16 exitCode)
{
    this->m_exitCode = exitCode;
    this->m_running = false;
}

sf::Int16 Game::run()
{
    this->m_running = true;

    this->createWindow();

    this->init();

    this->gameLoop();

    this->cleanup();

    return this->m_exitCode;
}   


//Private

void Game::createWindow()
{
    //Default Window Options
    sf::VideoMode videoMode(this->DEF_WIN_WIDTH, this->DEF_WIN_HEIGHT, this->DEF_WIN_BPP);

    sf::Int32 style = sf::Style::Default;

    bool fullscreen = false;

    bool resize = true;

    bool vsync = true;

    //Create window
    this->m_window.create(videoMode, "SFML", style);

    this->m_window.setVerticalSyncEnabled(vsync);
}

void Game::init()
{
    //Nothing actually happens here yet
}

void Game::gameLoop()
{
    while(this->isRunning() && this->m_window.isOpen())
    {
        sf::Event event;
        while(this->m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                quit(0);
        }

        this->m_window.clear(sf::Color::Blue);
        
        this->m_window.display();
    }
}

void Game::cleanup()
{
    //Will clean up things from init
}
