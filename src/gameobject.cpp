
#include "gameobject.h"

GameObject::GameObject() :
    m_window(Game::instance()->getWindow())
{
    setName("object");
    setTag("none");
}

GameObject::~GameObject() 
{

}

//Setters
void GameObject::setTexture(const std::string& filename) 
{
    if(!m_texture.loadFromFile(filename))
    {
        std::cerr << filename << " not found." << std::endl;
        return;
    }

    m_textureLoc = filename;
    m_sprite.setTexture(m_texture, true);
    m_sprite.setOrigin(m_sprite.getLocalBounds().width/2, m_sprite.getLocalBounds().height/2);
    
}

void GameObject::setMoveSpeed(float moveSpeed)
{
    m_moveSpeed = moveSpeed;
}

void GameObject::setName(const std::string& name)
{
    addToNameMap(name);
    m_objectName = name;
}

void GameObject::setTag(const std::string& tag)
{
    addToTagMap(tag);
    m_objectTag = tag;
}

//Set bools
void GameObject::setIsMoveable(bool moveable) 
{
    m_moveable = moveable;
}

void GameObject::setIsCollideable(bool collideable ) 
{
    m_collideable = collideable;
}

void GameObject::setIsPlayerControlled(bool playerControlled ) 
{
    m_playerControlled = playerControlled;
}


//Getters
std::string GameObject::getTextureLocation() 
{
    return m_textureLoc;
}

sf::Texture GameObject::getTexture()
{
    return m_texture;
}

sf::Sprite GameObject::getSprite() 
{
    return m_sprite;
}


//Get bools
bool GameObject::isMoveable() 
{
    return m_moveable;
}

bool GameObject::isCollideable() 
{
    return m_collideable;
}

bool GameObject::isPlayerControlled() 
{
    return m_playerControlled;
}

void GameObject::addToNameMap(const std::string& name)
{
    //Search for the old name so we don't have duplicates
    std::vector<GameObject*> vec = findGameObjectsWithName(m_objectName);
    
    std::vector<GameObject*>::iterator it = std::find(std::begin(vec), std::end(vec), this);

    if(it != std::end(vec))
    {
        //swap the last element and the found to reduce overhead
        //Order doesn't matter at all
        std::swap(*it, vec.back());
        vec.pop_back();
        m_nameMap[m_objectName] = vec;
    }

    //Finally add the new name to the list
    
}


void GameObject::addToTagMap(const std::string& tag)
{

    std::vector<GameObject*> vec = findGameObjectsWithTag(m_objectTag);
    
    std::vector<GameObject*>::iterator it = std::find(std::begin(vec), std::end(vec), this);

    if(it != std::end(vec))
    {
        //swap the last element and the found to reduce overhead
        //Order doesn't matter at all
        std::swap(*it, vec.back());
        vec.pop_back();
    }

    m_tagMap[&tag].push_back(this);
}



std::vector<GameObject*> GameObject::findGameObjectsWithName(const std::string& name)
{
   std::map<std::string, std::vector<GameObject*>>::const_iterator it = m_nameMap.find(name);
   if(it != m_nameMap.end())
   {
        return m_nameMap[name];
   }
   return {};
}

GameObject* GameObject::findGameObjectWithName(const std::string& name)
{
    std::vector<GameObject*> vec = findGameObjectsWithName(name);
    if(vec.size() != 0)
        return vec[0];
    return 0;
}

std::vector<GameObject*> GameObject::findGameObjectsWithTag(const std::string& tag)
{
   std::map<std::string, std::vector<GameObject*>>::const_iterator it = m_tagMap.find(tag);
   if(it != m_tagMap.end())
   {
        return m_tagMap[tag];
   }
   return {};
}

GameObject* GameObject::findGameObjectWithTag(const std::string& tag)
{
    std::vector<GameObject*> vec = findGameObjectsWithTag(tag);
    if(vec.size() != 0)
        return vec[0];
    return 0;
}
