#include "resource.h"
#include "Direct2D.h"
#include "Networking.h"
#include "Direct3D.h"

const wstring ClassName = L"LoaderClass";

RECT CurrentSize;




LRESULT CALLBACK WinProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{

	case  WM_LBUTTONDOWN:

		CheckLogInClicks(hWnd);
		break;

	case WM_CHAR:

		PushChar(wParam);
		break;
			
	case WM_KEYDOWN:

		switch (wParam)
		{	
			case VK_RETURN:

				LastButtonPushed = Buttons.SignIn;
				break;

			case VK_BACK:

				if (LastButtonPushed == Buttons.Email && !Strings.EmailStr.empty())
				{
					RemoveChar(Strings.EmailStr);
					break;
				}
				else if (LastButtonPushed == Buttons.Password && !Strings.PasswordStr.empty())
				{
					RemoveChar(Strings.PasswordStr);
					break;
				}
				break;
					
		}

	case WM_PAINT:

		DrawLogIn(hWnd); 
		break;

	case WM_MOUSEMOVE:

		Points.point = { GET_X_LPARAM(lParam) ,GET_Y_LPARAM(lParam) };
		break;

	case WM_DESTROY:

		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
}

LRESULT CALLBACK WinProcMenu(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_MOUSEMOVE:

		Points.point = { GET_X_LPARAM(lParam) ,GET_Y_LPARAM(lParam) };
		break;

		
	case WM_LBUTTONDOWN :

		SectionSelector(hWnd,LastMenuButtonPushed);
		CheckCheckBoxClick(hWnd);
		
		break;

	case WM_LBUTTONUP:


		break;

	case WM_PAINT:

		DrawMenu(hWnd);
		break;

	case WM_DESTROY:

		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
}


int CALLBACK  WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdSHow)
{
	auto xd = 0x2424c9d7e3a;
	auto ree = xd ^ 0x5a;
	cout << ree;
	WNDCLASSEX wc = { 0 };
	WNDCLASSEX wc2 = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance; 
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor = NULL;
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = (LPCWSTR)&ClassName;
	wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClassEx(&wc);


	HWND hWnd = CreateWindowEx(0, (LPCWSTR)&ClassName, L"Yamasu Loader v1.0", WS_OVERLAPPEDWINDOW, 600, 300, 1100, 700, nullptr, nullptr, hInstance, nullptr);

	InitializeResources(hWnd);
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd); 
	SetForegroundWindow(hWnd); 
	SetFocus(hWnd); 

	
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)*Timer, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)*AnimationManager, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)*Networking, 0, 0, 0);

	MapSharedMemory();

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		if (GetAsyncKeyState(VK_TAB))
		{
			SetWindowLongPtrA(hWnd, GWLP_WNDPROC, (LONG_PTR)WinProcMenu);
		}
		if (GetAsyncKeyState(VK_BACK))
		{
			SetWindowLongPtrA(hWnd, GWLP_WNDPROC, (LONG_PTR)WinProc);
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	Destruct();
	UnregisterClass(ClassName.c_str(),hInstance);
	return 0;
}


