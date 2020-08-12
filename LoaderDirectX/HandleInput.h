#pragma once

void PushChar(WPARAM wParam)
{
	if (LastButtonPushed == Buttons.Email && isgraph(wParam) && Strings.EmailStr.size() <= 40)
	{
		Strings.EmailStr.push_back(wParam);
	}

	else if (LastButtonPushed == Buttons.Password && isgraph(wParam) && Strings.PasswordStr.size() <= 40)
	{
		Strings.PasswordStr.push_back(wParam);
	}
}

void RemoveChar(wstring& str)
{
    str.pop_back();
    if (str.size() > 0)
    {
        str.resize(str.size() - 1);
    }

}



void CheckLogInClicks(HWND hWnd)
{
    if (CursorBelongsToRect(hWnd, TextRects.Email))
    {
        LastButtonPushed = Buttons.Email;
    }

    else if (CursorBelongsToRect(hWnd, TextRects.Password))
    {
        LastButtonPushed = Buttons.Password;
    }

    else if (CursorBelongsToRect(hWnd, TextRects.NewUser))
    {
        LastButtonPushed = Buttons.SignUp;
        Sleep(2); //sync with AnimationManager thread 
        HINSTANCE result = ShellExecuteA(0, NULL, "http://www.yamasu.co/register", NULL, NULL, SW_SHOWNORMAL);
    }

    else if (CursorBelongsToRect(hWnd, TextRects.SignIn))
    {
        LastButtonPushed = Buttons.SignIn;
        Sleep(2);  //sync with AnimationManager thread 
    }

    else
    {
        LastButtonPushed = 0;
    }
}

void CheckCheckBoxClick(HWND hWnd)
{

    if (CursorBelongsToRect(hWnd, CheckBoxRectsESP.r1))
    {
        bools.xl = !bools.xl;
        memcpy((PVOID)pBuf, (PVOID)&bools, sizeof(bools));
    }

    else if (CursorBelongsToRect(hWnd, CheckBoxRectsESP.r2))
    {
        bools.xl2 = !bools.xl2;
        memcpy((PVOID)pBuf, (PVOID)&bools, sizeof(bools));
    }

    else if (CursorBelongsToRect(hWnd, CheckBoxRectsESP.r3))
    {
        bools.xl3 = !bools.xl3;
        memcpy((PVOID)pBuf, (PVOID)&bools, sizeof(bools));
    }

    else if (CursorBelongsToRect(hWnd, CheckBoxRectsESP.r4))
    {
        bools.xl4 = !bools.xl4;
        memcpy((PVOID)pBuf, (PVOID)&bools, sizeof(bools));
    }

    else if (CursorBelongsToRect(hWnd, CheckBoxRectsESP.r5))
    {
        bools.xl5 = !bools.xl5;
        memcpy((PVOID)pBuf, (PVOID)&bools, sizeof(bools));
    }

    else if (CursorBelongsToRect(hWnd, CheckBoxRectsESP.r6))
    {
        bools.xl6 = !bools.xl6;
        memcpy((PVOID)pBuf, (PVOID)&bools, sizeof(bools));
    }
}


