#include "scene.h"

Scene::Scene(const std::string& sceneId)
{
    m_sceneId = sceneId;
}

Scene::~Scene()
{
}

std::string Scene::getId()
{
    return m_sceneId;
}

void Scene::setBackgroundColour(sf::Color colour)
{
    m_backgroundColour = colour;
}

sf::Color& Scene::getBackgroundColour()
{
    return m_backgroundColour;
}
