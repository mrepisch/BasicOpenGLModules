#pragma once

// External includes
#include <list>
#include <vector>

// Internal includes
#include "Entity.h"

namespace component
{
	/**
	 * This class represents a list of Entitys. 
	 * It is a singelton since an List of Entitys just exists once.
	 * The class provides some filter functions to collect entitys in the System implementations.
	 */
	class EntityCollection
	{
	public:
		// Private Constructor SINGELTON PATTERN
		EntityCollection();

		/**
		 * Virtual destructor
		 */
		virtual ~EntityCollection();

		/**
		 * This function returns a vector with all Entitys which contains the given Component
		 * @author sascha blank
		 * @param EnComponents, type of the Component
		 * @return std::vector<Entity*>
		 */
		std::vector<Entity*>getEntityWithComponents(EnComponents p_component);

		/**
		 * Returns a Entity pointer which holds the given Entity ID
		 * @author sascha blank
		 * @param long, the ID to lock up
		 * @return Entity* 
		 */
		Entity* getEntityByID(long p_id);

		/**
		 * Function to add a Entity to the EntityCollection
		 * @author sascha blank
		 * @param Entity*, the Entity to add
		 */
		void addEntity(Entity* p_entity);

		/**
		 * Function to return all Entitys as std::list<Entity*>
		 * @author sascha blank
		 * @return std::list<Entity*> with all Entitys
		 */
		const std::list<Entity*>& getAllEntitys();

	private:

		// List of all Entitys
		std::list<Entity*>m_entitys;

		// Private copy constructor
		EntityCollection(const EntityCollection& t_other) {}
	};
}