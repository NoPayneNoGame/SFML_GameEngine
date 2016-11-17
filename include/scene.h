#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>

class Scene : sf::NonCopyable
{

public:
    virtual ~Scene();

    std::string getId();

    void setBackgroundColour(sf::Color);

    sf::Color& getBackgroundColour();

    virtual void init() = 0;

    virtual void activate() = 0;

    virtual void deactivate() = 0;

    virtual void update() = 0;

    virtual void draw() = 0;

    virtual void cleanup() = 0;

protected:

    Scene(const std::string&);

private:
    std::string m_sceneId;
    sf::Color m_backgroundColour;
};


#endif //SCENE_H
