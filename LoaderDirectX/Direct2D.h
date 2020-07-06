#pragma once

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

#include <Windows.h>
#include <iostream>
#include <chrono>
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <iostream>
#include <wincodec.h>
#include <vector>
#include "resource.h"

#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"dwrite.lib")
#pragma comment(lib,"windowscodecs.lib")

#ifndef WINDOWS_LEAN_AND_MEAN
#define WINDOWS_LEAN_AND_MEAN
#endif 



using namespace std;
using namespace D2D1;



    ID2D1SolidColorBrush* pWhiteBrush = NULL;
    ID2D1SolidColorBrush* pBlackBrush = NULL;
    ID2D1SolidColorBrush* pSemiOpaqueBrush = NULL;
    ID2D1LinearGradientBrush* pLinearGradientBrush = NULL;

    ID2D1GradientStopCollection* pGradientStops = NULL;
    D2D1_GRADIENT_STOP gradientStops[2];


    HRESULT hr = NULL;
    RECT rc = { 0 };
    ID2D1Factory* pDirect2dFactory = NULL;
    ID2D1HwndRenderTarget* pRenderTarget = NULL;
    IWICImagingFactory* pIWICFactory = NULL;


    ID2D1Bitmap* pBitmapEmail = NULL;
    ID2D1Bitmap* pBitmapKey = NULL;
    ID2D1Bitmap* pBitmapLock = NULL;
    ID2D1Bitmap* pBitmapBgr = NULL;


    FLOAT f1;
    FLOAT f2;

    IDWriteFactory* pDWriteFactory;
    IDWriteTextFormat* pTextFormat;


    POINT point;

    wstring EmailStr;
    wstring PasswordStr;

    bool bTimebool = false;
    bool bEmail = false;
    bool bPassword = false;




    D2D1_RECT_F KeyBmp;
    D2D1_RECT_F EmailBmp;
    D2D1_RECT_F LockBmp;
    D2D1_RECT_F CheatBmp;
    D2D1_RECT_F GameBmp;

    D2D1_RECT_F NewUser ;
    D2D1_RECT_F SignIn;
    D2D1_RECT_F Password;
    D2D1_RECT_F Email; 
    D2D1_RECT_F Or;
    D2D1_RECT_F Fpassword;

    D2D1_ROUNDED_RECT RoundEmail ;
    D2D1_ROUNDED_RECT RoundPassword ;
    D2D1_ROUNDED_RECT RoundNewUser;
    D2D1_ROUNDED_RECT RoundSignIn ;

    HCURSOR hCursorHand;
    HCURSOR hCursorArrow;
  
    HRESULT LoadBitmapFromResource(int id, LPCWSTR type,ID2D1Bitmap** ppBitmap)
    {
        IWICBitmapDecoder* pDecoder = NULL;
        IWICBitmapFrameDecode* pSource = NULL;
        IWICStream* pStream = NULL;
        IWICFormatConverter* pConverter = NULL;
        IWICBitmapScaler* pScaler = NULL;

        HRSRC imageResHandle = NULL;
        HGLOBAL imageResDataHandle = NULL;
        void* pImageFile = NULL;
        DWORD imageFileSize = 0;

       
        imageResHandle = FindResource(NULL, MAKEINTRESOURCE(id), type);
        HRESULT hr = imageResHandle ? S_OK : E_FAIL;

        if (SUCCEEDED(hr))
        {
            imageResDataHandle = LoadResource(NULL, imageResHandle);
            hr = imageResDataHandle ? S_OK : E_FAIL;
        }

        if (SUCCEEDED(hr))
        {
            pImageFile = LockResource(imageResDataHandle);
            hr = pImageFile ? S_OK : E_FAIL;
        }

        if (SUCCEEDED(hr))
        {
            imageFileSize = SizeofResource(NULL, imageResHandle);
            hr = imageFileSize ? S_OK : E_FAIL;
        }

        if (SUCCEEDED(hr))
        {
            hr = pIWICFactory->CreateStream(&pStream);
        }

        if (SUCCEEDED(hr))
        {
            hr = pStream->InitializeFromMemory( (BYTE*)(pImageFile),imageFileSize);
        }

        if (SUCCEEDED(hr))
        {
            hr = pIWICFactory->CreateDecoderFromStream(pStream,NULL, WICDecodeMetadataCacheOnLoad,&pDecoder);
        }

        if (SUCCEEDED(hr))
        {
            hr = pDecoder->GetFrame(0, &pSource);
        }

        if (SUCCEEDED(hr))
        {
            hr = pIWICFactory->CreateFormatConverter(&pConverter);
        }

        if (SUCCEEDED(hr))
        {
            hr = pConverter->Initialize(pSource,GUID_WICPixelFormat32bppPBGRA,WICBitmapDitherTypeNone, NULL,0.f,WICBitmapPaletteTypeMedianCut);


            if (SUCCEEDED(hr))
            {
                hr = pRenderTarget->CreateBitmapFromWicBitmap(pConverter,NULL,ppBitmap );
            }

            return hr;
        }
    }


    HRESULT LoadBitmapFromFile(LPCWSTR path, ID2D1Bitmap** ppBitmap)
    {
        IWICBitmapDecoder* pDecoder = NULL;
        IWICBitmapFrameDecode* pSource = NULL;
        IWICStream* pStream = NULL;
        IWICFormatConverter* pConverter = NULL;
        IWICBitmapScaler* pScaler = NULL;

        HRESULT hr = pIWICFactory->CreateDecoderFromFilename(path, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &pDecoder);


        if (SUCCEEDED(hr))
        {
            hr = pDecoder->GetFrame(0, &pSource);
        }

        if (SUCCEEDED(hr))
        {
            hr = pIWICFactory->CreateFormatConverter(&pConverter);
        }

        if (SUCCEEDED(hr))
        {
            hr = pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeMedianCut);

            if (SUCCEEDED(hr))
            {
                hr = pRenderTarget->CreateBitmapFromWicBitmap(pConverter, NULL, ppBitmap);
            }

        }
        return hr;
    }
    

    HRESULT CreateBrushes()
    {
        hr = pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White, 1.0f), &pWhiteBrush);
        hr = pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black, 1.0f), &pBlackBrush);
        hr = pRenderTarget->CreateSolidColorBrush(D2D1::ColorF({ 1,1,1,0.1 }), &pSemiOpaqueBrush);

        gradientStops[0].color = ColorF(ColorF::Black, 1);
        gradientStops[0].position = 0.1f;
        gradientStops[1].color = ColorF(ColorF::DarkSlateGray, 1);
        gradientStops[1].position = 0.9;
        hr = pRenderTarget->CreateGradientStopCollection(gradientStops, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &pGradientStops);
        hr = pRenderTarget->CreateLinearGradientBrush(LinearGradientBrushProperties(Point2F(0, 0), D2D1::Point2F(550, 1100)), pGradientStops, &pLinearGradientBrush);
        return hr;
    }


    HRESULT CreateFormats()
    {
        hr = pDWriteFactory->CreateTextFormat(L"Comic Sans", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 16.0f, L"en-us", &pTextFormat);
        return hr;
    }


    HRESULT InitializeResources(HWND hwnd)
    {
        GetClientRect(hwnd, &rc);
        D2D1_SIZE_U size = SizeU(rc.right - rc.left, rc.bottom - rc.top);

        CoInitialize(NULL);
        hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&pIWICFactory);
        hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &(pDirect2dFactory));
        hr = pDirect2dFactory->CreateHwndRenderTarget(RenderTargetProperties(), HwndRenderTargetProperties(hwnd, size), &(pRenderTarget));

        hr = LoadBitmapFromResource(IDB_PNG1, L"PNG", &pBitmapEmail);
        hr = LoadBitmapFromResource(IDB_PNG2, L"PNG", &pBitmapKey);
        hr = LoadBitmapFromResource(IDB_PNG3, L"PNG", &pBitmapBgr);
        hr = LoadBitmapFromResource(IDB_PNG4, L"PNG", &pBitmapLock);  

        hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&pDWriteFactory));
        
        hCursorHand = LoadCursor(0, MAKEINTRESOURCE(IDC_HAND));
        hCursorArrow = LoadCursor(0, MAKEINTRESOURCE(IDC_ARROW));
        return hr;
    }


    D2D1_RECT_F RectToD2DRect(RECT rect)
    {
        return { (FLOAT)rect.left , (FLOAT)rect.top , (FLOAT)rect.right , (FLOAT)rect.bottom };
    }




    void Timer()
    {
        while (1)
        {
            bTimebool = !bTimebool;
            Sleep(500);
        }
    }

    void Update(HWND hwnd)
    {
        GetClientRect(hwnd, &rc);
        D2D1_SIZE_U size = SizeU(rc.right - rc.left, rc.bottom - rc.top);
        pRenderTarget->Resize(size);

        f1 = rc.right - rc.left;
        f2 = rc.bottom - rc.top;

        NewUser = { f1 / 2 - 180 ,f2 * 6 / 19,f1 / 2 + 180,f2 * 8 / 19 };
        SignIn = { f1 / 2 - 180,f2 * 15 / 19 - 20,f1 / 2 + 180,f2 * 16 / 19 };
        Password = { f1 / 2 - 200, f2 * 12 / 19, f1 / 2 + 200 ,f2 * 13 / 19 + 20 };
        Email = { f1 / 2 - 200, f2 * 10 / 19 ,f1 / 2 + 200,  f2 * 11 / 19 + 20 };
        Or = { f1 / 2 - 180,f2 * 8 / 19 ,  f1 / 2 + 180,  f2 * 10 / 19 };
        Fpassword = { f1 / 2 - 90,f2 * 17 / 19   ,f1 / 2 + 90,f2 * 17 / 19 + 20 };

        KeyBmp = { f1 / 2 - 290, f2 * 11 / 19 + 40, f1 / 2 - 230 ,f2 * 12 / 19 + 60 };
        EmailBmp = { f1 / 2 - 290, f2 * 10 / 19, f1 / 2 - 230 , f2 * 11 / 19 + 20 };
        LockBmp = { f1 / 2 - 135, f2 * 17 / 19 - 10, f1 / 2 - 115, f2 * 18 / 19 - 4 };
        CheatBmp = { f1 / 7 - 135, f2 * 17 / 19 - 10, f1 / 2 - 115, f2 * 18 / 19 - 4 };
        GameBmp = { f1 / 3 , f2 * 1 / 7 - 10, f1 * 2 / 3, f2 * 2 / 7 };

        RoundEmail = { Email,5,5 };
        RoundPassword = { Password,5,5 };
        RoundNewUser = { NewUser,5,5 };
        RoundSignIn = { SignIn ,5,5 };
    }

    void DrawCursor(D2D1_POINT_2F p0, D2D1_POINT_2F p1)
    {
        pRenderTarget->DrawLine(p0, p1, pWhiteBrush, 1, NULL);
    }

    bool PointBelongsToRect(HWND hwnd, LPPOINT lp, D2D1_RECT_F rect)
    {
        if (ScreenToClient(hwnd, lp))
        {
            if (lp->x >= rect.left && lp->x <= rect.right && lp->y >= rect.top && lp->y <= rect.bottom)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    bool CursorBelongsToRect(HWND hwnd, D2D1_RECT_F rect)
    {
        LPPOINT lp = new POINT;
        GetCursorPos(lp);
        if (ScreenToClient(hwnd, lp))
        {
            if (lp->x >= rect.left && lp->x <= rect.right && lp->y >= rect.top && lp->y <= rect.bottom)
            {
                return true;
                delete lp;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
            delete lp;
        }
    }

    void CursorHandler(HWND hwnd)
    {
        if (CursorBelongsToRect(hwnd, SignIn) || CursorBelongsToRect(hwnd, NewUser) || CursorBelongsToRect(hwnd, Fpassword))
        {
            SetCursor(hCursorHand);
        }
        else
        {
            SetCursor(hCursorArrow);
        }
    }

    void DrawTextInBox(D2D1_RECT_F rect, wstring str)
    {
        hr = pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);  
        rect.left +=10;
        pRenderTarget->DrawTextW((WCHAR *)str.c_str(),str.length(), pTextFormat, rect, pWhiteBrush);
    }

    void CursorTimer()
    {
        if (bEmail && !bPassword && bTimebool && EmailStr.length() <= 1) 
        {
            DrawCursor({ Email.left + 10 ,Email.top + 3 }, { Email.left + 10 ,Email.bottom - 3 });
        }
        else if (bPassword && !bEmail && bTimebool && PasswordStr.length() <= 1)
        {
            DrawCursor({ Password.left + 10,Password.top + 3 }, { Password.left + 10,Password.bottom - 3 });
        }


    }





    void MakeCheckBox(D2D1_RECT_F rect, ID2D1Brush* brush)
    {
        pRenderTarget->DrawRectangle(rect, brush);
    }

    void FillCheckBox(D2D1_RECT_F rect, ID2D1Brush* brush)
    {
        rect.left += (rect.right-rect.left)/7;
        rect.right -= (rect.right - rect.left) / 7;
        rect.top += (rect.bottom - rect.top) / 7;
        rect.bottom -= (rect.bottom - rect.top) / 7;
        pRenderTarget->FillRectangle(rect, brush);
    }
    
    void MakeButtonAnimation(D2D1_RECT_F& rect)
    {
        for (int x = 0; x <= 3; x++)
        {
          
        }
    }

    void MakeSlider(D2D1_RECT_F rect, ID2D1Brush* pBrush)
    {
        D2D1_ROUNDED_RECT rounded = { rect,15,15 };
        pRenderTarget->DrawRoundedRectangle(rounded, pBrush);
        D2D1_ELLIPSE ellipse = { {rect.left + (rect.right - rect.left) / 4,rect.top + (rect.bottom - rect.top) / 2}, 15,15 };
        if (GetAsyncKeyState(VK_TAB))
        {
            ellipse.point = { rect.left + (rect.right - rect.left) * 3 / 4,rect.top + (rect.bottom - rect.top) / 2 };
            SetCursor(hCursorHand);
        }
        pRenderTarget->FillEllipse(ellipse,pBrush);
        SetCursor(hCursorArrow);
    }


   


    void draw(HWND hwnd)
    {

        Update(hwnd);
        CursorHandler(hwnd);


        if (GetAsyncKeyState(VK_TAB))
        {
        NewUser.left += 25;
        NewUser.right -= 25;
        NewUser.top += 15;
        NewUser.bottom -= 15;
        ///Sleep(3000);
        }
        pRenderTarget->BeginDraw();

        pRenderTarget->FillRectangle(&RectToD2DRect(rc), pLinearGradientBrush);



        //MakeSlider({ 100,100,175,125 }, pWhiteBrush); 
    
        



        pRenderTarget->DrawBitmap(pBitmapBgr, RectToD2DRect(rc), 0.15);
        pRenderTarget->DrawBitmap(pBitmapKey, KeyBmp, 1);
        pRenderTarget->DrawBitmap(pBitmapEmail, EmailBmp, 1);
        pRenderTarget->DrawBitmap(pBitmapLock, LockBmp, 0.65);


        D2D1_POINT_2F p01 = { Or.left, Or.bottom * 0.9 };
        D2D1_POINT_2F p02 = { f1 / 2 - 20, Or.bottom * 0.9 };
        D2D1_POINT_2F p11 = { f1 / 2 + 20 ,Or.bottom * 0.9 };
        D2D1_POINT_2F p12 = { Or.right, Or.bottom * 0.9 };


        



        pRenderTarget->DrawRoundedRectangle(RoundEmail, pWhiteBrush, 1.1, 0);
        pRenderTarget->FillRoundedRectangle(RoundNewUser, pBlackBrush);
        pRenderTarget->DrawLine(p01, p02, pWhiteBrush, 0.3, NULL);
        pRenderTarget->DrawLine(p11, p12, pWhiteBrush, 0.3, NULL);
        pRenderTarget->DrawRoundedRectangle(RoundPassword, pWhiteBrush, 1.1, 0);
        pRenderTarget->FillRoundedRectangle(RoundSignIn, pBlackBrush);


        hr = pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
        hr = pTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
        pRenderTarget->DrawTextW(L"Sign up as a new user", lstrlenW(L"Sign up as a new user"), pTextFormat, NewUser, pWhiteBrush);
        pRenderTarget->DrawTextW(L"Sign in", lstrlenW(L"Sign in"), pTextFormat, SignIn, pWhiteBrush);
        pRenderTarget->DrawTextW(L"or", lstrlenW(L"or"), pTextFormat, Or, pWhiteBrush);
        pRenderTarget->DrawTextW(L"Forgot your password?", lstrlenW(L"Forgot your password?"), pTextFormat, Fpassword, pWhiteBrush); 
        pRenderTarget->DrawLine({ f1 / 2 - 90,f2 * 17 / 19 + 25 }, { f1 / 2 + 90, f2 * 17 / 19 + 25 }, pWhiteBrush, 1.4, NULL);



        hr = pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);


        if (!bEmail)
        {
            pRenderTarget->DrawTextW(L" - Email", lstrlenW(L" - Email"), pTextFormat, Email, pSemiOpaqueBrush);
        }
        if (!bPassword)
        {
            pRenderTarget->DrawTextW(L" - Password", lstrlenW(L" - Password"), pTextFormat, Password, pSemiOpaqueBrush);
        }



        CursorTimer();
       



        if (!EmailStr.empty())
        {
            DrawTextInBox(Email, EmailStr);
        }

        if (!PasswordStr.empty())
        {
             DrawTextInBox(Password, PasswordStr);
        }     
        




        


         pRenderTarget->EndDraw();
     }

    

    void construct(HWND hwnd)
    {      
        InitializeResources(hwnd);
        CreateBrushes();
        CreateFormats();
    }

    void Destruct()
    {
        pDirect2dFactory->Release();
        pRenderTarget->Release();
        CoUninitialize();
    }









