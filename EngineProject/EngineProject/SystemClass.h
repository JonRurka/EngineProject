////////////////////////////////////////////////////////////////////////////////
// Filename: systemclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_

///////////////////////////////
// PRE-PROCESSING DIRECTIVES //
///////////////////////////////
#define WIN32_LEAN_AND_MEAN

//////////////
// INCLUDES //
//////////////
#include <windows.h>

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "OpenglClass.h"
#include "InputClass.h"
#include "GraphicsClass.h"
#include "Logging.h"

////////////////////////////////////////////////////////////////////////////////
// Class name: SystemClass
////////////////////////////////////////////////////////////////////////////////
class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MassageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	bool InitializeWindows(OpenGLClass*, int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR	m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	OpenGLClass* m_OpenGL;
	InputClass* m_Input;
	GraphicsClass* m_Graphics;
	Logging* m_Logging;
};

/////////////////////////
// FUNCTION PROTOTYPES //
/////////////////////////
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

/////////////
// GLOBALS //
/////////////
static SystemClass* ApplicationHandle = 0;

#endif