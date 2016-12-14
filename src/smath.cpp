#include "smath.h"

#define PI 3.14159265

///Returns the magnitude (length) of vector v
double Smath::mag(sf::Vector2f v)
{
    return sqrt((v.x*v.x) + (v.y*v.y));
}

///Returns the dot product of two vectors
double Smath::dot(sf::Vector2f u, sf::Vector2f v)
{
    return (u.x*v.x) + (u.y*v.y);
}

///Return the cos of the angle between two vectors
double Smath::getCos(sf::Vector2f u, sf::Vector2f v)
{
    return dot(u, v)/(mag(u) * mag(v));
}

///Return the angle between two vectors in radians or degrees
/** You probably don't want to use this, try [atan2Angle](@ref Smath::atan2Angle) instead */
double Smath::findAngle(sf::Vector2f u, sf::Vector2f v, bool degrees)
{
    if(degrees)
        return radToDeg(acos(getCos(u, v)));
    else
        return acos(getCos(u, v));
}

///Convert radians to degrees
double Smath::radToDeg(double n)
{
    return n * 180.0 / PI;

}

///Return the 2D cross of two vectors
/** I'm not sure if that's the actual name, 
 * but I was trying things to get to atan2Angle */
double Smath::cross(sf::Vector2f u, sf::Vector2f v)
{
    return (u.x * v.y) - (u.y * v.x);
}

///Return the slope of the line between two vectors.
/** Only returns within 180 degrees, use [atan2Angle](@ref Smath::atan2Angle) if you want positional info.*/
double Smath::slopeOfLine(sf::Vector2f u, sf::Vector2f v)
{
    return (u.y - v.y) / (u.x - v.x);
}

///Return the atan2 angle between two vectors.
/** This is probably what you want to use. */
double Smath::atan2Angle(sf::Vector2f u, sf::Vector2f v)
{
    float theta = atan2(u.y - v.y, u.x - v.x);
    if(theta < 0)
	theta += (PI * 2);
    return radToDeg(theta);
}
