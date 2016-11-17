#include "ray.h"

Ray::Ray() : 
m_points(sf::Lines, 2)
{
}

Ray::Ray(sf::Vector2f startPoint, sf::Vector2f endPoint) :
m_points(sf::Lines, 2)
{
    sf::Vertex start(startPoint);
    sf::Vertex end(endPoint);

    //m_points.setPrimitiveType(sf::Lines);
    //m_points.resize(2);
    m_points.append(start);
    m_points.append(end);

    
}

Ray::~Ray()
{
}

void Ray::setStart(sf::Vector2f vec)
{
    sf::Vertex v(vec);
    m_points[0] = v;
}

void Ray::setStart(float x, float y)
{
    sf::Vector2f vec(x, y);
    setStart(vec);
}

void Ray::setEnd(sf::Vector2f vec)
{
    sf::Vertex v(vec);
    m_points[1] = v;    
}

void Ray::setEnd(float x, float y)
{
    sf::Vector2f vec(x, y);
    setEnd(vec);
}

void Ray::setColor(sf::Color color)
{
    for(unsigned int i = 0; i < m_points.getVertexCount(); i++)
    {
        m_points[i].color = color;
    }
}

sf::Vector2f Ray::getStart()
{
    sf::Vector2f v;
    v.x = m_points[0].position.x;
    v.y = m_points[0].position.y;
    return v;
}

sf::Vector2f Ray::getEnd()
{
    sf::Vector2f v;
    v.x = m_points[1].position.x;
    v.y = m_points[1].position.y;
    return v;
}

sf::Color Ray::getColor()
{
    return m_points[0].color;
}

void Ray::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = NULL;
    target.draw(m_points, states);
}
