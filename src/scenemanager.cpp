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
    std::cout << "Adding scene: " << scene->getId() << std::endl;
    //See if scene already exists in scenes map
    std::map<std::string, Scene*>::const_iterator it = m_scenes.find(scene->getId());

    if(it != m_scenes.end())
    {
        //If it exists, return
        std::cerr << "Scene " << scene->getId() << "  already exists in scene list." << std::endl;
        return;
    }

    //Otherwise add the scene to the map
    m_scenes[scene->getId()] = scene;

    //And init it
    scene->init();
    std::cout << "Added and inited scene: " << scene->getId() << std::endl;
}

Scene* SceneManager::getActiveScene()
{
    return m_activeScene;
}


void SceneManager::changeScene(std::string sceneId)
{

    //See if scene exists in scenes map
    std::map<std::string, Scene*>::const_iterator it = m_scenes.find(sceneId);

    if(it == m_scenes.end())
    {
        //If the scene doesn't exist, return
        return;
    }


    if(m_activeScene != NULL)
    {
        m_activeScene->deactivate();
        m_scenes[m_activeScene->getId()] = m_activeScene;
    }

    m_activeScene = m_scenes[sceneId];
    m_scenes.erase(sceneId);
    m_activeScene->activate();
}

void SceneManager::removeAllScenes()
{
    //Deactivate the active scene
    //And put it in the scene map
    if(m_activeScene != NULL)
    {
        m_activeScene->deactivate();
        m_scenes[m_activeScene->getId()] = m_activeScene;
    }

    //Iterate through the scene map
    //cleanup and delete everything
    std::map<std::string, Scene*>::iterator it = m_scenes.begin();
    while(it != m_scenes.end())
    {
        it->second->cleanup();
        delete it->second;
        m_scenes.erase(it++);
    }
}

void SceneManager::drawScene()
{
    m_activeScene->draw();
}

void SceneManager::updateScene()
{
    m_activeScene->update();
}
