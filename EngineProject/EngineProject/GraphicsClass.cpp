////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	m_OpenGL = 0;
	m_Logging = 0;
	R = 0;
	G = 0;
	B = 0;

	increasingR = true;
	increasingG = true;
	increasingB = true;
}

GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}

GraphicsClass::~GraphicsClass()
{
}

bool GraphicsClass::Initialize(OpenGLClass* OpenGL, Logging* logging, HWND hwnd)
{
	// Stor a pointer to the OpenGL class and logging objects.
	m_OpenGL = OpenGL;
	m_Logging = logging;
	return true;
}

void GraphicsClass::Shutdown()
{
	// Release the pointer to the OpenGL class object.
	m_OpenGL = 0;
	return;
}

bool GraphicsClass::Frame()
{
	bool result;

	// Render the graphics scene.
	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}

bool GraphicsClass::Render()
{
	if (increasingR)
	{
		R+=0.0001f;
		if (R>=1)
		{
			increasingR = false;
		}
	}
	else
	{
		R-=0.0002f;
		if (R<=0)
		{
			increasingR = true;
		}
	}

	if (increasingG)
	{
		G+=0.0003f;
		if (G>=1)
		{
			increasingG = false;
		}
	}
	else
	{
		G-=0.0004f;
		if (G<=0)
		{
			increasingG = true;
		}
	}

	if (increasingB)
	{
		B+=0.0005f;
		if (B>=1)
		{
			increasingB = false;
		}
	}
	else
	{
		B-=0.0006f;
		if (B<=0)
		{
			increasingB = true;
		}
	}

	// Clear the buffers to begin the scene.
	m_OpenGL->BeginScene(R, G, B, 1.0f);

	// Present the rendered scene to the screen.
	m_OpenGL->EndScene();

	return true;
}