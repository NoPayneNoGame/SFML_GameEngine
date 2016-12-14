#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#pragma once

#include <SFML/System.hpp>

#include "scene.h"

#include <map>

///A class that handles changing and init of [Scenes](@ref Scene)
/**  
 *  Used within [Game](@ref Game)
 */
class SceneManager : sf::NonCopyable
{
    static SceneManager* m_instance;

public:
    static SceneManager* instance();
    static void release();

    void addScene(Scene*);

    Scene* getActiveScene();

    ///SceneManager is a singleton and thus shouldn't be copied.
    SceneManager(SceneManager const&) = delete;
    ///SceneManager is a singleton and thus shouldn't be copied.
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
