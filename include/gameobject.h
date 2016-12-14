#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include "game.h"

class GameObject : public sf::Drawable, public sf::Transformable
{
public:
    GameObject();
    virtual ~GameObject();

    void setTexture(const std::string&);
    void setMoveSpeed(float);
    void setName(const std::string&);
    void setTag(const std::string&);

    void setIsMoveable(bool);
    void setIsCollideable(bool);
    void setIsPlayerControlled(bool);

    sf::Texture getTexture();
    std::string getTextureLocation();
    sf::Sprite getSprite();

    bool isMoveable();
    bool isCollideable();
    bool isPlayerControlled();

    static GameObject* findGameObjectWithName(const std::string&);
    static std::vector<GameObject*> findGameObjectsWithName(const std::string&);
    static GameObject* findGameObjectWithTag(const std::string&);
    static std::vector<GameObject*> findGameObjectsWithTag(const std::string&);

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

protected:

    sf::RenderWindow& m_window;
    
    sf::Texture m_texture;
    std::string m_textureLoc;
    sf::Sprite m_sprite;

    bool m_moveable;
    bool m_collideable;
    bool m_playerControlled;
    
    float m_moveSpeed;

    std::string m_objectName;
    std::string m_objectTag;

private:
    void addToNameMap(const std::string&);
    void addToTagMap(const std::string&);

    static std::map<std::string, std::vector<GameObject*>> m_nameMap();
    static std::map<std::string, std::vector<GameObject*>> m_tagMap();
};

#endif //GAMEOBJECT_H
