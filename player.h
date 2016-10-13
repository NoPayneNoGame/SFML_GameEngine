#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "smath.h"
#include "ray.h"

class Player : public sf::Drawable, public sf::Transformable
{
public:
    Player(const std::string&, int);
    virtual ~Player();
    void handleMovement();
    void handleRotation();
private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    
    int m_moveSpeed;
    
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    Ray m_laser;
};
