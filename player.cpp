#include "player.h"

Player::Player(sf::RenderWindow* window, const std::string& texture, int moveSpeed, Bullet* bullet)
{
    if(!m_texture.loadFromFile(texture))
        std::cerr << "Player Texture not found." << std::endl;

    m_sprite.setTexture(m_texture, true);

    m_moveSpeed = moveSpeed;
    m_fovAngle = 90;

    m_sprite.setOrigin(m_sprite.getLocalBounds().width/2, m_sprite.getLocalBounds().height/2);

    m_bullet = bullet;
    m_window = window;
}

Player::~Player(){
}

void Player::update()
{
    handleMovement();
    handleRotation();

    m_bullet->setPosition(getOrigin());

    m_laser.setStart(getOrigin());
    m_laser.setEnd(300, 0);
    m_laser.setColor(sf::Color::Red);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
	shootBullet();
    }
}

void Player::updateShadow()
{
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


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	m_fovAngle++;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	m_fovAngle--;
}

void Player::handleRotation()
{
    sf::Vector2f mousePos(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

    float angle = Smath::atan2Angle(mousePos,  getPosition());

    setRotation(angle);
}

void Player::shootBullet()
{
    std::cout << "Bang!" << std::endl;
    Bullet* b = new Bullet("assets/bullet.png", 2.0f);
    b->getSprite().setPosition(getOrigin());
    m_window->draw(b->getSprite());
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_laser, states);
    target.draw(m_sprite, states);
    target.draw(*m_bullet, states);

    //for(int i = 0; i < m_bullets.size(); i++)
    //{
	//target.draw(*m_bullets[i], states);
    //}
}
