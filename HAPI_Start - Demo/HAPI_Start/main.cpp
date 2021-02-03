/*
	HAPI Start
	----------
	This solution contains an already set up HAPI project and this main file
	
	The directory structure and main files are:

	HAPI_Start - contains the Visual Studio solution file (.sln)
		HAPI_Start - contains the Visual Studio HAPI_APP project file (.vcxproj) and source code
			HAPI - the directory with all the HAPI library files
			Data - a place to put your data files with a few sample ones provided

	Additionally in the top directory there is a batch file for creating a redistributable Demo folder

	For help using HAPI please see the Reference folder in the HAPI sub-directory
*/

// Include the HAPI header to get access to all of HAPIs interfaces
#include <HAPI_lib.h>
#include "Graphics.h"
#include "World.h"

// HAPI itself is wrapped in the HAPISPACE namespace
using namespace HAPISPACE;


// Every HAPI program has a HAPI_Main as an entry point
// When this function exits the program will close down
void HAPI_Main()
{
	HAPI.SetShowFPS(true);
	World worldsystem;
	worldsystem.LoadLevel();
	worldsystem.Update();



	//int width{ 800 };
	//int height{ 600 };

	////create new instance of the graphics
	//Graphics* graphic = new Graphics();
	//
	////initialise the program and load the textures
	//if (graphic->Initialise(width,height))
	//{
	//	return;
	//}

	//if (!graphic->LoadSprite("Data\\Background.tga", "Background"))
	//{
	//	HAPI.UserMessage("Could not load texture", "Error");
	//	return;
	//}
	//
	//if (!graphic->LoadSprite("Data\\AlphaThing.tga", "Player"))
	//{
	//	HAPI.UserMessage("Could not load texture", "Error");
	//	return;
	//}

	//BYTE* screen = HAPI.GetScreenPointer();

	//HAPI_TColour color;

	//const HAPI_TKeyboardData& keyData{ HAPI.GetKeyboardData() };

	//int x{ -50 };
	//int y{ 500 };

	//while (HAPI.Update())
	//{
	//	graphic->ClearToColor(screen,HAPI_TColour::BLACK);
	//	graphic->DrawSprite("Background", 0, 0);
	//	graphic->DrawSprite("Player", x, y);

	//	if (keyData.scanCode['W'])
	//		y--;
	//	if (keyData.scanCode['S'])
	//		y++;
	//	if (keyData.scanCode['D'])
	//		x++;
	//	if (keyData.scanCode['A'])
	//		x--;
	//}
}
