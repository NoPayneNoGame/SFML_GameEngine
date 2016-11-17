#include "scenemanager.h"
#include <iostream>

SceneManager* SceneManager::m_instance = 0;

SceneManager::SceneManager() : 
    m_activeScene(NULL),
    m_scenes()
{
    std::cout << "Scene Manager constructor" << std::endl;
}

SceneManager::~SceneManager()
{
    std::cout << "Scene Manager deconstructor" << std::endl;
}

SceneManager* SceneManager::instance()
{
    std::cout << "Scene Manager Instance: " <<  m_instance << std::endl;
    if(m_instance == 0)
    {
        m_instance = new SceneManager();
    }
    return m_instance;
}

void SceneManager::release()
{
    std::cout << "Scene Manager release" << std::endl;
    if(m_instance)
        delete m_instance;
    m_instance = 0;
}

void SceneManager::addScene(Scene* scene)
{
    std::cout << "Adding scene..." << std::endl;
    //See if scene already exists in scenes map
    std::cout << m_scenes.size() << std::endl;
    std::map<std::string, Scene*>::const_iterator it = this->m_scenes.find(scene->getId());

    std::cout << "After map search" << std::endl;

    if(it != this->m_scenes.end())
    {
        //If it exists, return
        return;
    }

    //Otherwise add the scene to the map
    this->m_scenes[scene->getId()] = scene;

    //And init it
    scene->init();
    std::cout << "Added and Inited scene" << std::endl;
}

Scene* SceneManager::getActiveScene()
{
    return this->m_activeScene;
}


void SceneManager::changeScene(std::string sceneId)
{

    //See if scene exists in scenes map
    std::map<std::string, Scene*>::const_iterator it = this->m_scenes.find(sceneId);

    if(it == this->m_scenes.end())
    {
        //If the scene doesn't exist, return
        return;
    }


    if(this->m_activeScene != NULL)
    {
        this->m_activeScene->deactivate();
        this->m_scenes[this->m_activeScene->getId()] = this->m_activeScene;
    }

    this->m_activeScene = this->m_scenes[sceneId];
    this->m_scenes.erase(sceneId);
    this->m_activeScene->activate();
}

void SceneManager::removeAllScenes()
{
    //Deactivate the active scene
    //And put it in the scene map
    if(this->m_activeScene != NULL)
    {
        this->m_activeScene->deactivate();
        this->m_scenes[this->m_activeScene->getId()] = this->m_activeScene;
    }

    //Iterate through the scene map
    //cleanup and delete everything
    std::map<std::string, Scene*>::iterator it = this->m_scenes.begin();
    while(it != this->m_scenes.end())
    {
        it->second->cleanup();
        delete it->second;
        this->m_scenes.erase(it++);
    }
}

void SceneManager::drawScene()
{
    this->m_activeScene->draw();
}

void SceneManager::updateScene()
{
    this->m_activeScene->update();
}
