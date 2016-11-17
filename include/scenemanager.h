#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#pragma once

#include <SFML/System.hpp>

#include "scene.h"

#include <map>

class SceneManager : sf::NonCopyable
{
    static SceneManager* m_instance;

public:
    static SceneManager* instance();
    static void release();

    void addScene(Scene*);

    Scene* getActiveScene();

    SceneManager(SceneManager const&) = delete;
    void operator=(SceneManager const&) = delete;

private:

    friend class Game;

    Scene* m_activeScene;
    
    std::map<std::string, Scene*> m_scenes;

    SceneManager();
    ~SceneManager();

    void changeScene(std::string);

    void removeAllScenes();

    void drawScene();

    void updateScene();

};


#endif //SCENE_MANAGER_H
