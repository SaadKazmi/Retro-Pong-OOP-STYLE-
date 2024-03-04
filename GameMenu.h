//#ifndef _GAMEMENU_H
//#define _GAMEMENU_H
//#include "raylib.h"
//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"
//
//class GameMenu
//{
// bool QUIT;
// bool PVP;
// bool PVC;
// bool Menu;
//
//public:
//	GameMenu() 
//	{
//		Menu = true;
//		PVC = false;
//		PVP = false;
//		QUIT = false;
//
//	}
//	~GameMenu() {}
//	void drawMain() 
//	{
//		BeginDrawing();
//		ClearBackground(RAYWHITE);
//		EndDrawing();
//		GuiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
//
//		if (GuiButton(Rectangle{ 350, 220, 135, 50 }, "PLAY GAME")) 
//		{
//			Menu = false;
//			PVC = false;
//			PVP = true;
//			QUIT = false;
//		}		
//		if (GuiButton(Rectangle{ 350, 280, 135, 50 }, "PRACTICE")) 
//		{
//			Menu = false;
//			PVP = false;
//			PVC = true;
//			QUIT = false;
//		}
//		if (GuiButton(Rectangle{ 350, 340, 135, 50 }, "Quit")) {
//			QUIT = true;
//		}
//
//	}
//	bool GetPVP()
//	{
//		return PVP;
//	}
//	bool GetPVC()
//	{
//		return PVC;
//	}
//	void SetPVP(bool pvp)
//	{
//		PVP = pvp;
//	}
//	void SetPVC(bool pvc)
//	{
//		PVC = pvc;
//	}
//	void SetQuit(bool quit)
//	{
//		QUIT = quit;
//	}
//	bool GetQuit()
//	{
//		return QUIT;
//	}
//
//	void SetMenu(bool menu)
//	{
//		PVC = false;
//		PVP = false;
//		Menu = menu;
//	}
//	bool GetMenu()
//	{
//		return Menu;
//	}
//
//};
//#endif