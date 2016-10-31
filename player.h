#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "smath.h"
#include "ray.h"
#include "bullet.h"

class Player : public sf::Drawable, public sf::Transformable
{
public:
    Player(sf::RenderWindow*, const std::string&, int, Bullet*);
    virtual ~Player();
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
    sf::RenderWindow* m_window;
    sf::ConvexShape m_shadow;
};
