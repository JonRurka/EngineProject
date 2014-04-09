////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "OpenglClass.h"
#include "Logging.h"

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = false;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(OpenGLClass*, Logging*, HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render();

private:
	OpenGLClass* m_OpenGL;
	Logging* m_Logging;

	float R, G, B;
	bool increasingR, increasingG, increasingB;
};

#endif
