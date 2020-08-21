#pragma once

#define WIN32_LEAN_AND_MEAN 

#include "wtypes.h"
#include "propidl.h"
#include "ocidl.h"
#include "dxgiformat.h"
#include "dxgitype.h"
#include <Windows.h>
#include <Windowsx.h>
#include <shellapi.h>
#include <iostream>


typedef struct DXGI_JPEG_AC_HUFFMAN_TABLE
{
    BYTE CodeCounts[16];
    BYTE CodeValues[162];
} DXGI_JPEG_AC_HUFFMAN_TABLE;

typedef struct DXGI_JPEG_DC_HUFFMAN_TABLE
{
    BYTE CodeCounts[12];
    BYTE CodeValues[12];
} DXGI_JPEG_DC_HUFFMAN_TABLE;

typedef struct DXGI_JPEG_QUANTIZATION_TABLE
{
    BYTE Elements[64];
} DXGI_JPEG_QUANTIZATION_TABLE;


#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <ws2tcpip.h>

#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"dwrite.lib")
#pragma comment(lib,"windowscodecs.lib")


using namespace std;
using namespace D2D1;

#include "resource.h"
#include "ResourcesD2D.h"
#include "SharedMemory.h"
#include "Misc.h"
#include "Drawing.h"
#include "HandleInput.h"
#include "Animations.h"
#include "CreateResources.h"



void Update(HWND hwnd)
{
    GetClientRect(hwnd, &Rsrces.rc);
    D2D1_SIZE_U size = SizeU(Rsrces.rc.right - Rsrces.rc.left, Rsrces.rc.bottom - Rsrces.rc.top);
    Rsrces.pRenderTarget->Resize(size);

    width = Rsrces.rc.right - Rsrces.rc.left;
    heigth = Rsrces.rc.bottom - Rsrces.rc.top;

    TextRects.NewUser   = { width * 1/3,    heigth * 6/19,        width * 2/3,         heigth * 8/19 };
    TextRects.SignIn    = { width * 1/3,    heigth * 13/17,       width * 2/3,         heigth * 16/19 };
    TextRects.Password  = { width * 3/10,   heigth * 12/19,       width * 7/10 ,       heigth * 13/18 };
    TextRects.Email     = { width * 3/10,   heigth * 21/40,       width * 7/10,        heigth * 11/18 };
    TextRects.Or        = { width * 3/10,   heigth * 8/19,        width * 7/10,        heigth * 10/19 };
    TextRects.Title     = { width * 3/10,   heigth * 2/19,        width * 7/10,        heigth * 3/19 };


    BitmapRects.KeyBmp  = { width * 4/18,    heigth * 12/19,       width * 3/10 ,        heigth * 13 / 18 };
    BitmapRects.EmailBmp= { width * 2/9,     heigth * 10/20 + 8,   width * 3/11 + 8 ,    heigth * 12 / 19 };

    CheckBoxRectsESP.r1 = { width / 4,     heigth * 6/30 ,       width *  4/15,      heigth * 7/30 };
    CheckBoxRectsESP.r2 = { width / 4,     heigth * 8/30,        width * 4 / 15 ,     heigth * 9/30 };
    CheckBoxRectsESP.r3 = { width / 4,     heigth * 10/30,       width * 4 / 15 ,     heigth * 11/30 };
    CheckBoxRectsESP.r4 = { width / 4,     heigth * 12/30,       width * 4 / 15 ,     heigth * 13/30};
    CheckBoxRectsESP.r5 = { width / 4,     heigth * 14/30,       width * 4 / 15,      heigth * 15/30 };
    CheckBoxRectsESP.r6 = { width / 4,     heigth * 16 / 30,     width * 4 / 15,      heigth * 17 / 30 };
    
    TextBoxRectsESP.RectESP      = { width / 4,        heigth * 1/11,    width /2,       heigth * 3/12};
    TextBoxRectsESP.RectSL       = { width * 2/7,      heigth * 2/21,    width /2 ,      heigth * 4/12 };
    TextBoxRectsESP.Rect2DBox    = { width * 2/7,      heigth * 3/21,    width /2 ,      heigth * 5/12 };
    TextBoxRectsESP.Rect3DBox    = { width * 2/7,      heigth * 4/21,    width /2 ,      heigth * 6/12 };
    TextBoxRectsESP.RectGlow     = { width * 2/7,      heigth * 5/21,    width /2 ,      heigth * 7/12 };
    TextBoxRectsESP.RectSkeleton = { width * 2/7,      heigth * 6/21,    width /2 ,      heigth * 8/12 };


    Points.pPointLineFp1 = { width / 2 - 90,heigth * 17 / 19 + 25 };
    Points.pPointLineFp2 = { width / 2 + 90, heigth * 17 / 19 + 25 };

    RoundedRects.RoundEmail    = { TextRects.Email,5,5 };
    RoundedRects.RoundPassword = { TextRects.Password,5,5 };
    RoundedRects.RoundNewUser  = { TextRects.NewUser,5,5 };
    RoundedRects.RoundSignIn   = { TextRects.SignIn ,5,5 };


    Rect2 = { 600,600,700,610 };

    BitmapRects.BmpBF = {30 ,10, width / 7 + 30,heigth - 10};
    BitmapRects.BitmapHs = { BitmapRects.BmpBF.left + 20 ,BitmapRects.BmpBF.top ,BitmapRects.BmpBF.right - 20, BitmapRects.BmpBF.bottom / 6 };
    BitmapRects.BitmapVisual = { BitmapRects.BmpBF.left + 30 , BitmapRects.BmpBF.bottom / 6 + 20 ,BitmapRects.BmpBF.right - 30, BitmapRects.BmpBF.bottom * 2/6 - 20};
    BitmapRects.BitmapAA = { BitmapRects.BmpBF.left + 30 , BitmapRects.BmpBF.bottom * 2/6  ,BitmapRects.BmpBF.right - 30, BitmapRects.BmpBF.bottom * 3/6 };
    BitmapRects.BitmapSkinChanger = { BitmapRects.BmpBF.left + 30 , BitmapRects.BmpBF.bottom * 3/6  ,BitmapRects.BmpBF.right - 30, BitmapRects.BmpBF.bottom * 4/6};
    BitmapRects.BitmapSettings = { BitmapRects.BmpBF.left + 35 , BitmapRects.BmpBF.bottom * 4/6 + 10  ,BitmapRects.BmpBF.right - 35, BitmapRects.BmpBF.bottom * 5/6 - 10 };
    BitmapRects.BitmapAccount = { BitmapRects.BmpBF.left + 30 , BitmapRects.BmpBF.bottom * 5/6  ,BitmapRects.BmpBF.right - 30, BitmapRects.BmpBF.bottom * 6/6  - 20};
}




void CursorTimer()
{
    if (LastButtonPushed == Buttons.Email && bTimebool && Strings.EmailStr.length() <= 0) 
    {
        DrawCursor(TextRects.Email, Brushes.pWhiteBrush);
        
    }
    else if (LastButtonPushed == Buttons.Password && bTimebool && Strings.PasswordStr.length() <= 0)
    {
        DrawCursor(TextRects.Password, Brushes.pWhiteBrush);
    }
}

void DrawText()
{
    Rsrces.hr = WriteFormats.pTextFormatNormal->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
    Rsrces.hr = WriteFormats.pTextFormatNormal->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

    Rsrces.hr = WriteFormats.pTextFormatSmaller->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
    Rsrces.hr = WriteFormats.pTextFormatSmaller->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
    Rsrces.hr = WriteFormats.pTextFormatHugeItalic->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);


    Rsrces.pRenderTarget->DrawTextW(L"Sign up as a new user", lstrlenW(L"Sign up as a new user"), WriteFormats.pTextFormatNewUser, TextRects.NewUser, Brushes.pWhiteBrush);
    Rsrces.pRenderTarget->DrawTextW(L"Sign in", lstrlenW(L"Sign in"), WriteFormats.pTextFormatSignIn, TextRects.SignIn, Brushes.pWhiteBrush);
    Rsrces.pRenderTarget->DrawTextW(L"or", lstrlenW(L"or"), WriteFormats.pTextFormatNormal, TextRects.Or, Brushes.pWhiteBrush);


    Rsrces.hr = WriteFormats.pTextFormatNormal->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);

    Rsrces.pRenderTarget->DrawTextW(L"Yamasu Cheats", lstrlenW(L"Yamasu Cheats"), WriteFormats.pTextFormatHugeItalic, TextRects.Title, Brushes.pLinearGradientBrush2);


    if (!(LastButtonPushed == Buttons.Email)) 
    {
        Rsrces.pRenderTarget->DrawTextW(L" - Email", lstrlenW(L" - Email"), WriteFormats.pTextFormatNormal, TextRects.Email, Brushes.pSemiOpaqueBrush);
    }
    if (!(LastButtonPushed == Buttons.Password))
    {
        Rsrces.pRenderTarget->DrawTextW(L" - Password", lstrlenW(L" - Password"), WriteFormats.pTextFormatNormal, TextRects.Password, Brushes.pSemiOpaqueBrush);
    }


    if (!Strings.EmailStr.empty())
    {
        DrawTextInBox(TextRects.Email, WriteFormats.pTextFormatNormal, Strings.EmailStr);
    }

    if (!Strings.PasswordStr.empty())
    {
        DrawTextInBox(TextRects.Password, WriteFormats.pTextFormatNormal, Strings.PasswordStr);
    }
}



void IncreaseGradientPosition(float& GradientPos1, float& GradientPos2)
{
    if (GradientPos1 <= 0.29)
    {
        GradientPos1 += 0.005;
        GradientPos2 += 0.005;
        GS.gradientStops2[0].color = ColorF(ColorF::White, 1);
        GS.gradientStops2[0].position = GradientPos1;
        GS.gradientStops2[1].color = ColorF(ColorF::Black, 1);
        GS.gradientStops2[1].position = GradientPos2;

        Rsrces.hr = Rsrces.pRenderTarget->CreateGradientStopCollection(GS.gradientStops2, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &GS.pGradientStops2);
        Rsrces.hr = Rsrces.pRenderTarget->CreateLinearGradientBrush(LinearGradientBrushProperties(Point2F(0, 0), D2D1::Point2F(550, 1100)), GS.pGradientStops2, &Brushes.pLinearGradientBrush2);
    }
}


void MakeSlideBar(HWND hwnd,D2D1_ROUNDED_RECT BarRect,ID2D1Brush* BarBrush, ID2D1Brush* CircleBrush, int& GlobalCount)
{
    Rsrces.pRenderTarget->FillRoundedRectangle(BarRect, BarBrush);
    D2D1_ELLIPSE ellipse = { RectToPoint(BarRect.rect,GlobalCount), (BarRect.rect.bottom - BarRect.rect.top) * 3 / 2, (BarRect.rect.bottom - BarRect.rect.top) * 3 / 2};
    Rsrces.pRenderTarget->FillEllipse(ellipse, CircleBrush);

    if ((GetKeyState(VK_LBUTTON)))
    {
        if (ellipse.point.x >= BarRect.rect.left && ellipse.point.x <= BarRect.rect.right)
        {
            Rsrces.pRenderTarget->FillEllipse(ellipse, CircleBrush);
            if (CursorBelongsToRect(hwnd, PointToRect(RectToPoint(Rect2, GlobalCount), (int)(Rect2.bottom - Rect2.top) * 3 / 2)))
            {
                GlobalCount = Points.point.x - Rect2.left;
            }
        }
        else
        {
            if (ellipse.point.x < BarRect.rect.left)
            {
                ellipse.point.x = BarRect.rect.left;
                Rsrces.pRenderTarget->FillEllipse(ellipse, CircleBrush);
                GlobalCount = 0;
            }
            else if (ellipse.point.x > BarRect.rect.right)
            {
                ellipse.point.x = BarRect.rect.right;
                Rsrces.pRenderTarget->FillEllipse(ellipse, CircleBrush);
                GlobalCount = BarRect.rect.right - BarRect.rect.left;
            }

        }
    } 
}



void DrawLogIn(HWND hwnd)
{
    IncreaseGradientPosition(GradientStop1, GradientStop2);


    CursorHandler(hwnd);

    Rsrces.pRenderTarget->BeginDraw();
    Rsrces.pRenderTarget->FillRectangle(&RectToD2DRect(Rsrces.rc), Brushes.pLinearGradientBrush);

    Rsrces.pRenderTarget->DrawBitmap(Bitmaps.pBitmapBgr, RectToD2DRect(Rsrces.rc), 0.15);
    Rsrces.pRenderTarget->DrawBitmap(Bitmaps.pBitmapKey, BitmapRects.KeyBmp, 1);
    Rsrces.pRenderTarget->DrawBitmap(Bitmaps.pBitmapEmail, BitmapRects.EmailBmp, 1);

    WriteFormats.pTextFormatNewUser = WriteFormats.pTextFormatNormal;
    WriteFormats.pTextFormatSignIn = WriteFormats.pTextFormatNormal;

    HandleLogInAnimations();

    Rsrces.pRenderTarget->DrawRoundedRectangle(RoundedRects.RoundEmail, Brushes.pWhiteBrush, 1.1, 0);
    Rsrces.pRenderTarget->FillRoundedRectangle(RoundedRects.RoundNewUser, Brushes.pBlackBrush);
    Rsrces.pRenderTarget->DrawRoundedRectangle(RoundedRects.RoundPassword, Brushes.pWhiteBrush, 1.1, 0);
    Rsrces.pRenderTarget->FillRoundedRectangle(RoundedRects.RoundSignIn, Brushes.pBlackBrush);


    CursorTimer();
    DrawText();


    if (GradientStop1 < 0.29)
    {
        Brushes.pLinearGradientBrush2->Release();
    }

    Sleep(30);
    Rsrces.pRenderTarget->EndDraw();
}

void SelectBox(int& button)
{
    if (button == MenuButtons.Aimbot)
    {
        Rsrces.pRenderTarget->DrawRectangle({ BitmapRects.BmpBF.left,BitmapRects.BmpBF.top,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 1 / 6 }, Brushes.pWhiteBrush, 4.f);
        return; 
    }
    else if (button == MenuButtons.Visuals)
    {
        Rsrces.pRenderTarget->DrawRectangle({ BitmapRects.BmpBF.left,BitmapRects.BmpBF.bottom * 1 / 6,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 2 / 6 }, Brushes.pWhiteBrush, 4.f);
        return;
    }
    else if (button == MenuButtons.AntiAim)
    {
        Rsrces.pRenderTarget->DrawRectangle({ BitmapRects.BmpBF.left,BitmapRects.BmpBF.bottom * 2 / 6,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 3 / 6 }, Brushes.pWhiteBrush, 4.f);
        return;
    }
    else if (button == MenuButtons.SkinChanger)
    {
        Rsrces.pRenderTarget->DrawRectangle({ BitmapRects.BmpBF.left,BitmapRects.BmpBF.bottom * 3 / 6,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 4 / 6 }, Brushes.pWhiteBrush, 4.f);
        return;
    }
    else if (button == MenuButtons.Settings)
    {
        Rsrces.pRenderTarget->DrawRectangle({ BitmapRects.BmpBF.left,BitmapRects.BmpBF.bottom * 4 / 6,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 5 / 6 }, Brushes.pWhiteBrush, 4.f);
        return;
    }
    else if(button == MenuButtons.Account)
    {
        Rsrces.pRenderTarget->DrawRectangle({ BitmapRects.BmpBF.left,BitmapRects.BmpBF.bottom * 5 / 6,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 6 / 6 }, Brushes.pWhiteBrush, 4.f);
        return;
    }
}

void SectionSelector(HWND hwnd,int& LastMenuButtonPushed)
{
    if (CursorBelongsToRect(hwnd, { BitmapRects.BmpBF.left,BitmapRects.BmpBF.top,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 1 / 6 }))
    {
        LastMenuButtonPushed = MenuButtons.Aimbot;
        return;
    }
    else if (CursorBelongsToRect(hwnd, { BitmapRects.BmpBF.left,BitmapRects.BmpBF.bottom * 1 / 6,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 2 / 6 }))
    {
        LastMenuButtonPushed = MenuButtons.Visuals;
        return;
    }
    else if (CursorBelongsToRect(hwnd, { BitmapRects.BmpBF.left,BitmapRects.BmpBF.bottom * 2 / 6,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 3 / 6 }))
    {
        LastMenuButtonPushed = MenuButtons.AntiAim;
        return;
    }
    else if (CursorBelongsToRect(hwnd, { BitmapRects.BmpBF.left,BitmapRects.BmpBF.bottom * 3 / 6,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 4 / 6 }))
    {
        LastMenuButtonPushed = MenuButtons.SkinChanger;
        return;
    }
    else if (CursorBelongsToRect(hwnd, { BitmapRects.BmpBF.left,BitmapRects.BmpBF.bottom * 4 / 6,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 5 / 6 }))
    {
        LastMenuButtonPushed = MenuButtons.Settings;
        return;
    }
    else if (CursorBelongsToRect(hwnd, { BitmapRects.BmpBF.left,BitmapRects.BmpBF.bottom * 5 / 6,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 6 / 6 }))
    {
        LastMenuButtonPushed = MenuButtons.Account;
        return;
    }
}


void DrawMenu(HWND hwnd)
{

    Rsrces.pRenderTarget->BeginDraw();
    Rsrces.pRenderTarget->FillRectangle(&RectToD2DRect(Rsrces.rc), Brushes.pLinearGradientBrush3);
    //Rsrces.pRenderTarget->FillRectangle({ BitmapRects.BmpBF.left,BitmapRects.BmpBF.top,BitmapRects.BmpBF.right,BitmapRects.BmpBF.bottom * 1 / 6 }, Brushes.pBlackBrush);
    Rsrces.pRenderTarget->DrawBitmap(Bitmaps.pBitmapHs, BitmapRects.BitmapHs, 0.7);
    Rsrces.pRenderTarget->DrawBitmap(Bitmaps.pBitmapVisual, BitmapRects.BitmapVisual, 0.8);
    Rsrces.pRenderTarget->DrawBitmap(Bitmaps.pBitmapAA, BitmapRects.BitmapAA, 0.7);
    Rsrces.pRenderTarget->DrawBitmap(Bitmaps.pBitmapSkinChanger, BitmapRects.BitmapSkinChanger, 0.8);
    Rsrces.pRenderTarget->DrawBitmap(Bitmaps.pBitmapSettings, BitmapRects.BitmapSettings, 0.8);
    Rsrces.pRenderTarget->DrawBitmap(Bitmaps.pBitmapAccount, BitmapRects.BitmapAccount, 0.8);
    Rsrces.pRenderTarget->DrawRectangle({ width / 5, 15, width - 25, heigth - 15 }, Brushes.pWhiteBrush);


    SelectBox(LastMenuButtonPushed);
    MakeSlideBar(hwnd, RectToRoundedRect(Rect2, 15, 15), Brushes.pWhiteBrush, Brushes.pBlackBrush, GlobalCount);



    Rsrces.pRenderTarget->DrawText(L"Player ESP", lstrlenW(L"Player Esp"), WriteFormats.pTextFormatBigItalic, TextBoxRectsESP.RectESP, Brushes.pWhiteBrush);
    Rsrces.pRenderTarget->DrawText(L"Snaplines", lstrlenW(L"Snaplines"), WriteFormats.pTextFormatNormal, TextBoxRectsESP.RectSL, Brushes.pWhiteBrush);
    Rsrces.pRenderTarget->DrawText(L"2DBoxESP", lstrlenW(L"2DBoxESP"), WriteFormats.pTextFormatNormal, TextBoxRectsESP.Rect2DBox, Brushes.pWhiteBrush);
    Rsrces.pRenderTarget->DrawText(L"3DBoxESP", lstrlenW(L"3DBoxESP"), WriteFormats.pTextFormatNormal, TextBoxRectsESP.Rect3DBox, Brushes.pWhiteBrush);
    Rsrces.pRenderTarget->DrawText(L"GlowESP", lstrlenW(L"GlowESP"), WriteFormats.pTextFormatNormal, TextBoxRectsESP.RectGlow, Brushes.pWhiteBrush);
    Rsrces.pRenderTarget->DrawText(L"SkeletonESP", lstrlenW(L"SkeletonESP"), WriteFormats.pTextFormatNormal, TextBoxRectsESP.RectSkeleton, Brushes.pWhiteBrush);


    DrawCheckBox(CheckBoxRectsESP.r1, Brushes.pWhiteBrush, bools.xl);
    DrawCheckBox(CheckBoxRectsESP.r2, Brushes.pWhiteBrush, bools.xl2);
    DrawCheckBox(CheckBoxRectsESP.r3, Brushes.pWhiteBrush, bools.xl3);
    DrawCheckBox(CheckBoxRectsESP.r4, Brushes.pWhiteBrush, bools.xl4);
    DrawCheckBox(CheckBoxRectsESP.r5, Brushes.pWhiteBrush, bools.xl5);
    DrawCheckBox(CheckBoxRectsESP.r6, Brushes.pWhiteBrush, bools.xl6);



    Rsrces.pRenderTarget->FillEllipse({ { x,y }, 5, 5 }, Brushes.pWhiteBrush);
    Rsrces.pRenderTarget->EndDraw();
}


void Destruct()
{
    Rsrces.pDirect2dFactory->Release();
    Rsrces.pRenderTarget->Release();
    CoUninitialize();
}












