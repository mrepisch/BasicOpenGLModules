#include <iostream>
#include <glew\GL\glew.h>
#include "Display.h"
#include "util\Vector3D.h"
#include "render\RenderSystem.h"
#include "render\RenderComponent.h"
#include "component\TranslationComponent.h"
#include "util\PLYParser.h"
#include "game\InputSystem.h"
#include "game\CameraSystem.h"
#include "BasicKeyInput.h"
#include "game\CameraComponent.h"

using namespace render;
using namespace component;
using namespace util;
using namespace game;

int main(int argc, char **argv)
{
	Display l_mainWindow(800, 600, "OpenGL Window");
	l_mainWindow.setFPS( 30 );
	
	InputSystem* l_inputSystem = new InputSystem(&l_mainWindow);
	l_mainWindow.addSystem( l_inputSystem );

	BasicKeyInput* l_keyInput = new BasicKeyInput();
	l_inputSystem->addKeyEvent( l_keyInput );

	Entity* l_camera = new Entity( "camera" );
	CameraComponent* a_cameraComp = new CameraComponent( 800, 600, 1000.0f );
	l_camera->addComponent( a_cameraComp );
	l_mainWindow.addEntity( l_camera );

	RenderSystem* l_renderSystem = new RenderSystem();
	

		
	CameraSystem* l_cameraSystem = new CameraSystem(l_renderSystem->getShaderProgramID());
	
	
	l_mainWindow.addSystem( l_cameraSystem );
	l_mainWindow.addSystem( l_renderSystem );
	

	PLYParser a_parser;
	Entity* l_entity = new Entity("testobject");

	Mesh* a_mesh = a_parser.readMeshFromFile( "C:\\Users\\episch\\Documents\\test.ply" );
	//a_mesh->setTexture( new Texture( "C:\\Users\\episch\\Documents\\OpenGLProject\\test.bmp" ) );
	a_mesh->generateBuffer();
	RenderComponent* a_renderComponent = new RenderComponent(a_mesh);
	TranslationComponent* a_translation = new TranslationComponent();

	a_translation->m_position.set( 0.0f, 0.0f,-3.0f );
	
	a_translation->m_rotation.set( 0.0f, 0.0f, 0.0f );
	
	a_translation->m_scale.set( 0.5f, 0.5f, 0.5f );
	
	l_entity->addComponent( a_translation );
	l_entity->addComponent( a_renderComponent );
	l_mainWindow.addEntity( l_entity );

	l_mainWindow.update();
	return 0;
}