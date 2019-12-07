#include "util_window.h"

int screen_width = 1600;
int screen_height = 900;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND                hwnd;
	MSG                 Msg;

	hwnd = create_window(hInstance);
	ShowWindow(hwnd, nCmdShow);

	//=============================================================================================================================
   // Add the code to edit the window

	for (int i = 0; i < screen_width; i++)
		for (int j = 0; j < screen_height; j++)
			set_pixel(i, j, 0xff00ff);				// Set the color of the pixel at x = i, y = j with the color = 0xRRGGBB


	Update();							//This line updates the screen

	 //=============================================================================================================================

	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

// Event-Handling Function
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}
