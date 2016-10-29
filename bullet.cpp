#include "bullet.h"

Bullet::Bullet()
{
    m_speed = 0;
}

Bullet::Bullet(const std::string& texture, float speed)
{
    if(!m_texture.loadFromFile(texture))
	std::cerr << "Bullet texture not found." << std::endl;

    m_sprite.setTexture(m_texture, true);

    m_sprite.setOrigin(m_sprite.getLocalBounds().width/2, m_sprite.getLocalBounds().height/2);

    m_speed = speed;
}

Bullet::~Bullet()
{
}

void Bullet::setTexture(const std::string& texture)
{
    if(!m_texture.loadFromFile(texture))
	std::cerr << "Bullet texture not found" << std::endl;

    m_sprite.setTexture(m_texture, true);
    m_sprite.setOrigin(m_sprite.getLocalBounds().width/2, m_sprite.getLocalBounds().height/2);
}

void Bullet::setSpeed(float speed)
{
    m_speed = speed;
}

void Bullet::shoot()
{
    setPosition(getPosition().x + m_speed, getPosition().y);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_sprite, states);
}

