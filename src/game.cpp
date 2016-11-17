#include "game.h"

Game* Game::m_instance = 0;

Game::Game() :
    m_window(),
    m_running(false),
    m_exitCode(0)
{
    std::cout << "Game constructor" << std::endl;
}

Game::~Game()
{
}

//Public
Game* Game::instance()
{
    std::cout << "Game instance: " << m_instance  << std::endl;
    if(m_instance == 0)
    {
        m_instance = new Game();
    }
    return m_instance;
}

void Game::release()
{
    if(m_instance)
    {
        delete m_instance;
    }
    m_instance = 0;
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

void Game::setFirstScene(Scene* scene)
{
    if(this->m_startScene == NULL)
    {
        m_startScene = scene;
        std::cout << m_startScene->getId() << std::endl;
    }
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
    std::cout << "Create Window" << std::endl;
    
    //Default Window Options
    sf::VideoMode videoMode(this->DEF_WIN_WIDTH, this->DEF_WIN_HEIGHT, this->DEF_WIN_BPP);

    sf::Int32 style = sf::Style::Default;

    bool vsync = true;

    //Create window
    this->m_window.create(videoMode, "SFML", style);

    this->m_window.setVerticalSyncEnabled(vsync);
}

void Game::init()
{
    m_sceneMan = SceneManager::instance();
    std::cout << "In game init: " << m_sceneMan << std::endl;
    if(m_startScene != 0)
    {
        this->m_sceneMan->addScene(this->m_startScene);
        this->m_sceneMan->changeScene(this->m_startScene->getId());
    }
    else
    {
        quit(-1);
    }
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
            if(event.type == sf::Event::KeyPressed)
                if(event.key.code == sf::Keyboard::Escape)
                    quit(0);
        }

        this->m_sceneMan->updateScene();
       
        this->m_window.clear(sf::Color::Blue);
        
        this->m_sceneMan->drawScene();

        this->m_window.display();
    }
}

void Game::cleanup()
{
    m_sceneMan->removeAllScenes();
    m_sceneMan->release();
    m_sceneMan = NULL;
}
