#include "smath.h"

#define PI 3.14159265

double Smath::mag(sf::Vector2f v)
{
    return sqrt((v.x*v.x) + (v.y*v.y));
}

double Smath::dot(sf::Vector2f u, sf::Vector2f v)
{
    return (u.x*v.x) + (u.y*v.y);
}

double Smath::getCos(sf::Vector2f u, sf::Vector2f v)
{
    return dot(u, v)/(mag(u) * mag(v));
}

double Smath::findAngle(sf::Vector2f u, sf::Vector2f v, bool degrees)
{
    if(degrees)
        return radToDeg(acos(getCos(u, v)));
    else
        return acos(getCos(u, v));
}

double Smath::radToDeg(double n)
{
    return n * 180.0 / PI;

}

double Smath::cross(sf::Vector2f u, sf::Vector2f v)
{
    return (u.x * v.y) - (u.y * v.x);
}
