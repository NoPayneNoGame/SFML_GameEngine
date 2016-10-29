#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet : public sf::Drawable, public sf::Transformable
{
public:
    Bullet();
    Bullet(const std::string&, float);
    virtual ~Bullet();

    void setTexture(const std::string&);
    void setSpeed(float);
    void shoot();
private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    float m_speed;
};
