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

void Ray::setEnd(sf::Vector2f vec)
{
    sf::Vertex v(vec);
    m_points[1] = v;    
}

void Ray::setColor(sf::Color color)
{
    for(int i = 0; i < m_points.getVertexCount(); i++)
    {
        m_points[i].color = color;
    }
}

void Ray::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = NULL;
    target.draw(m_points, states);
}
