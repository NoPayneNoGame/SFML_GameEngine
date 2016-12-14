#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include "smath.h"
#include "ray.h"

#include "gameobject.h"

class Player : public GameObject
{
public:
    Player();
    virtual ~Player();
    
    void init();
    void update();
    void draw();


private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    void handleMovement();
    void handleRotation();
};

/*
class Player : public sf::Drawable, public sf::Transformable
{
public:
    Player();
    Player(sf::RenderWindow&, const std::string&, int, Bullet*);
    virtual ~Player();

    void setTexture(const std::string&);
    void setSpeed(float);

    void updateShadow();
    void handleMovement();
    void handleRotation();
    void update();
    void shootBullet();

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    
    int m_moveSpeed;
    int m_fovAngle;

    sf::Texture m_texture;
    sf::Sprite m_sprite;

    Ray m_laser;
    Ray ray1;
    Ray ray2;

    Bullet* m_bullet;
    sf::RenderWindow& m_window;
    sf::ConvexShape m_shadow;
};*/

#endif //PLAYER_H
