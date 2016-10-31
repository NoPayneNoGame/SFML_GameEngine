#include "bullet.h"

Bullet::Bullet(const std::string& texture, float speed)
{
    m_texture.loadFromFile(texture);

    m_sprite.setTexture(m_texture, true);

    m_speed = speed;

    m_sprite.setOrigin(m_sprite.getLocalBounds().width/2, m_sprite.getLocalBounds().height/2);
}

Bullet::~Bullet()
{
}

sf::Sprite Bullet::getSprite()
{
    return m_sprite;
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_sprite, states);
}

