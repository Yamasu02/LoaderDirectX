
#include "resource.h"
#include "Direct2D.h"
#include "Networking.h"






const wstring ClassName = L"LoaderClass";





LRESULT CALLBACK WinProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{

	case  WM_LBUTTONDOWN:

		if (CursorBelongsToRect(hWnd, Email))
		{
			bPassword = false;
			bEmail = true;
		}

		else if (CursorBelongsToRect(hWnd, Password))
		{
			bEmail = false;
			bPassword = true;
		}

		else if (CursorBelongsToRect(hWnd, NewUser))
		{
			pPushedSignIn = false;
			pPushedNewUser = true;
			Sleep(2); //sync with AnimationManager thread for lower cpu usage
		}

		else if (CursorBelongsToRect(hWnd, SignIn))
		{
			pPushedNewUser = false;
			pPushedSignIn = true;
			Sleep(2);  //sync with AnimationManager thread for lower cpu usage
		}

		else
		{
			bEmail = false;
			bPassword = false;
		}

	case WM_CHAR:

		if (bEmail && !bPassword && isgraph(wParam) && EmailStr.size() <= 40)
		{
			EmailStr.push_back(wParam);
			break;
		}
		else if (bPassword && !bEmail && isgraph(wParam) && PasswordStr.size() <= 40)
		{
			PasswordStr.push_back(wParam);
			break;
		}
			

	case WM_KEYDOWN:

		switch (wParam)
		{	

			case VK_RETURN:


				break;

			case VK_BACK:

				if (bEmail && !EmailStr.empty())
				{
					EmailStr.pop_back();
					if (EmailStr.size() > 0)
					{
						EmailStr.resize(EmailStr.size() - 1);
					}
					break;
				}
				else if (bPassword && !PasswordStr.empty())
				{
					PasswordStr.pop_back();
					if (PasswordStr.size() > 0)
					{
						PasswordStr.resize(PasswordStr.size() - 1);
					}
					break;
				}
				break;
		}

	case WM_PAINT:

		draw(hWnd);
		break;

	case WM_MOUSEMOVE:

		point = { GET_X_LPARAM(lParam) ,GET_Y_LPARAM(lParam) };
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

	construct(hWnd);
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd); 
	SetForegroundWindow(hWnd); 
	SetFocus(hWnd); 

	
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)*Timer, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)*AnimationManager, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)*Networking, 0, 0, 0);


	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	Destruct();
	UnregisterClass(ClassName.c_str(),hInstance);
	return 0;
}


