
#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

class Smath
{
public:
    static double mag(sf::Vector2f);
    static double dot(sf::Vector2f, sf::Vector2f);
    static double getCos(sf::Vector2f, sf::Vector2f);
    static double findAngle(sf::Vector2f, sf::Vector2f, bool);
    static double radToDeg(double);
    static double cross(sf::Vector2f, sf::Vector2f);
    static double slopeOfLine(sf::Vector2f, sf::Vector2f);
    static double atan2Angle(sf::Vector2f, sf::Vector2f);
};
