#include "scene.h"

Scene::Scene(const std::string& sceneId)
{
    this->m_sceneId = sceneId;
}

Scene::~Scene()
{
}

std::string Scene::getId()
{
    return this->m_sceneId;
}

void Scene::setBackgroundColour(sf::Color colour)
{
    this->m_backgroundColour = colour;
}

sf::Color& Scene::getBackgroundColour()
{
    return this->m_backgroundColour;
}
