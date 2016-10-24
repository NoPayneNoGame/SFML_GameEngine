#include "player.h"

Player::Player(const std::string& texture, int moveSpeed)// :
//m_shadow(6)
{
    if(!m_texture.loadFromFile(texture))
        std::cerr << "Player Texture not found." << std::endl;

    m_sprite.setTexture(m_texture, true);

    m_moveSpeed = moveSpeed;
    m_fovAngle = 90;

    m_sprite.setOrigin(m_sprite.getLocalBounds().width/2, m_sprite.getLocalBounds().height/2);
    //m_sprite.setRotation(47);

    m_shadow.setPointCount(3);
    m_shadow.setFillColor(sf::Color::Green);

    sf::Vector2f pos = getOrigin();

    Ray r;
    r.setStart(0, 0);
    r.setEnd(300, 0);


    m_shadow.setPoint(0, sf::Vector2f(0, 0));
    m_shadow.setPoint(1, sf::Vector2f(0, -300));
    m_shadow.setPoint(2, sf::Vector2f(0, 300));

//    r.setRotation(m_fovAngle/2);
//    m_shadow.setPoint(1, r.getEnd());

//    r.setRotation(m_fovAngle);
//    m_shadow.setPoint(2, r.getEnd());

//    r.setRotation(m_fovAngle*1.5);
//    m_shadow.setPoint(3, r.getEnd());

//    r.setRotation(m_fovAngle*2);
//    m_shadow.setPoint(4, r.getEnd());
    
//    m_shadow.setPoint(1, sf::Vector2f(0, 200));
//    m_shadow.setPoint(2, sf::Vector2f(0, 200));
//    m_shadow.setPoint(3, sf::Vector2f(200, 200));
//    m_shadow.setPoint(4, sf::Vector2f(200, 0));
//    m_shadow.setPoint(5, pos);
    
    
    m_shadow.setPosition(pos);
}

Player::~Player(){
}

void Player::update()
{
    handleMovement();
    handleRotation();

    m_laser.setStart(getOrigin());
    m_laser.setEnd(300, 0);//getPosition());
    m_laser.setColor(sf::Color::Red);

//    ray1.setStart(getOrigin());
//    ray1.setEnd(getPosition() * 2.0f);
//    ray1.setRotation(m_fovAngle/2);
    
//    ray2.setStart(getOrigin());
//    ray2.setEnd(getPosition() * 2.0f);
//    ray2.setRotation(-m_fovAngle/2);

 //   updateShadow();
}

void Player::updateShadow()
{
    m_shadow.setPoint(0, getOrigin());
    m_shadow.setPoint(1, ray1.getEnd());
    
    ray1.setRotation(m_fovAngle);
    m_shadow.setPoint(2, ray1.getEnd());

    ray1.setRotation(m_fovAngle * 1.5);
    m_shadow.setPoint(3, ray1.getEnd());

    ray1.setRotation(m_fovAngle * 2);
    m_shadow.setPoint(4, ray1.getEnd());

    ray1.setRotation(m_fovAngle/2);
//    m_shadow.setPoint(5, getOrigin());

    m_shadow.setPosition(getOrigin());

//    std::cout <<  << std::endl;
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


//    std::cout << "Player: " << getPosition().x << ", " << getPosition().y << std::endl;
//    std::cout << "Mouse: " << sf::Mouse::getPosition().x << ", " << sf::Mouse::getPosition().y << std::endl;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
//	std::cout << ray1.getStart().x << ", " << ray1.getStart().y << std::endl;
	m_fovAngle++;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
//	std::cout << ray1.getEnd().x << ", " << ray1.getEnd().y << std::endl;
	m_fovAngle--;

    m_laser.setRotation(m_fovAngle);
    std::cout << m_laser.getEnd().x << ", " << m_laser.getEnd().y << std::endl;
}

void Player::handleRotation()
{
    sf::Vector2f mousePos(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

    float angle = Smath::atan2Angle(mousePos,  getPosition());

    setRotation(angle);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_laser, states);
    target.draw(m_sprite, states);
    target.draw(m_shadow, states);
    //target.draw(ray1, states);
    //target.draw(ray2, states);
}
