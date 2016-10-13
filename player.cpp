#include "player.h"

Player::Player(const std::string& texture, int moveSpeed)
{
    if(!m_texture.loadFromFile(texture))
        std::cerr << "Player Texture not found." << std::endl;

    m_sprite.setTexture(m_texture, true);

    m_moveSpeed = moveSpeed;

    m_sprite.setOrigin(m_sprite.getLocalBounds().width/2, m_sprite.getLocalBounds().height/2);
    m_sprite.setRotation(47);
}

Player::~Player(){
}

void Player::update()
{
    handleMovement();
    handleRotation();

    m_laser.setStart(getOrigin());
    m_laser.setEnd(getPosition() * 10.0f);
    m_laser.setColor(sf::Color::Red);

    ray1.setStart(getOrigin());
    ray1.setEnd(getPosition() * 10.0f);
    ray1.setRotation(45);

    
    ray2.setStart(getOrigin());
    ray2.setEnd(getPosition() * 10.0f);
    ray2.setRotation(-45);
}

void Player::handleMovement()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        move(-m_moveSpeed, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        move(m_moveSpeed, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        move(0, -m_moveSpeed);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        move(0, m_moveSpeed);
}

void Player::handleRotation()
{
    sf::Vector2f mousePos(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

    sf::Vector2f targetDir = mousePos - getPosition();
    
    double rotToMouse = Smath::findAngle(getPosition(), targetDir, true);
    if(Smath::cross(getPosition(), targetDir) >= 0)
	setRotation(rotToMouse);
    else
	setRotation(-rotToMouse);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_laser, states);
    target.draw(m_sprite, states);
    target.draw(ray1, states);
    target.draw(ray2, states);
}
