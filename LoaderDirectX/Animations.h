#pragma once

void MakeButtonAnimation(D2D1_ROUNDED_RECT& rect, IDWriteTextFormat*& pTextFormatE)
{
    rect.rect.left += 20;
    rect.rect.right -= 20;
    rect.rect.top += 10;
    rect.rect.bottom -= 10;
    pTextFormatE = WriteFormats.pTextFormatSmaller;
}

void HandleLogInAnimations()
{
    if (bPushTimer && LastButtonPushed == Buttons.SignUp)
    {
        MakeButtonAnimation(RoundedRects.RoundNewUser, WriteFormats.pTextFormatNewUser);
        LastButtonPushed = 0;
    }

    if (bPushTimer && LastButtonPushed == Buttons.SignIn)
    {
        MakeButtonAnimation(RoundedRects.RoundSignIn, WriteFormats.pTextFormatSignIn);
        LastButtonPushed = 0;
    }
}

void AnimationManager()
{
    while (1)
    {
        if (LastButtonPushed == Buttons.SignUp || LastButtonPushed == Buttons.SignIn)
        {
            bPushTimer = true;
            Sleep(50);
            bPushTimer = false;

        }
        Sleep(2);
    }
}



