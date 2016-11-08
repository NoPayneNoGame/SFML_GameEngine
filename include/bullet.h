#ifndef BULLET_H
#define BULLET_H

#pragma once

#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable, public sf::Transformable
{
public:
    Bullet(const std::string&, float);
    virtual ~Bullet();

    sf::Sprite getSprite();
private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    float m_speed;
};

#endif // BULLET_H
