#ifndef RAY_H
#define RAY_H

#pragma once

#include <SFML/Graphics.hpp>

class Ray : public sf::Drawable, public sf::Transformable
{
public:
    Ray();
    Ray(sf::Vector2f, sf::Vector2f);
    ~Ray();

    void setStart(sf::Vector2f);
    void setStart(float, float);
    void setEnd(sf::Vector2f);
    void setEnd(float, float);
    void setColor(sf::Color);

    sf::Vector2f getStart();
    sf::Vector2f getEnd();
    sf::Color getColor();

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    
    int m_length;
    sf::Vector2f m_startPoint;
    sf::VertexArray m_points;
};

#endif //RAY_H
