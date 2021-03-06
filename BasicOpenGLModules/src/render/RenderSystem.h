#pragma once

// Internal includes
#include "../component/System.h"
#include "../core/ShaderManager.h"


namespace render
{
	class RenderSystem : public component::System
	{
	public:
		/**
		 * Constructor
		 * @author sascha blank
		 */
		RenderSystem( component::EntityCollection* p_collection, core::ShaderManager* p_shaderManager );

		/**
		 * virtual destructor
		 */
		virtual ~RenderSystem();

		/**
		 * Update function which is called in the mainloop
		 * @author sascha blank
		 */
		void update();

		/**
		 * Function to receive and process Events form the event system
		 * @author sascha blank
		 */
		void receiveEvent( component::Event* p_event );

	private:


		component::Entity* m_camera;
		core::ShaderManager* m_shaderManager;
	};
}