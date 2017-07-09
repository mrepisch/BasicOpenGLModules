
// Internal includes
#include "Entity.h"


using namespace component;

long Entity::S_ENTITYCOUNTER = 0;


Entity::Entity(const char* p_objectName)
{
	m_name = p_objectName;
	++S_ENTITYCOUNTER;
	m_entityID = S_ENTITYCOUNTER;
}

Entity::Entity(const Entity& t_other)
{
	*this = t_other;
}

Entity& Entity::operator=(const Entity& t_other)
{
	if(this != &t_other)
	{
		m_components = t_other.m_components;
		m_name = t_other.m_name;
	}
	return *this;
}


const std::string& Entity::getName(void) const
{
	return m_name;
}


bool Entity::getHasComponent(EnComponents p_component)
{
	bool r_hasComponent = false;
	for (auto l_iter = m_components.begin(); l_iter != m_components.end(); l_iter++)
	{
		if ((*l_iter)->getComponentType() == p_component)
		{
			r_hasComponent = true;
			break;
		}
	}
	return r_hasComponent;
}

void Entity::update( void )
{

}

void Entity::render(void)
{

}


long Entity::getEntityID()
{
	return m_entityID;
}