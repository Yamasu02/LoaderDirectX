#pragma once


struct Rsrces
{
	HRESULT hr = NULL;
	RECT rc = { 0 };
	ID2D1Factory* pDirect2dFactory = NULL;
	ID2D1HwndRenderTarget* pRenderTarget = NULL;
	IDWriteFactory* pDWriteFactory;
	IWICImagingFactory* pIWICFactory = NULL;
}Rsrces;



struct Brushes
{
	ID2D1SolidColorBrush* pWhiteBrush = NULL;
	ID2D1SolidColorBrush* pBlackBrush = NULL;
	ID2D1SolidColorBrush* pGrayBrush = NULL;
	ID2D1SolidColorBrush* pSemiOpaqueBrush = NULL;
	ID2D1LinearGradientBrush* pLinearGradientBrush = NULL;
	ID2D1LinearGradientBrush* pLinearGradientBrush2 = NULL;
	ID2D1LinearGradientBrush* pLinearGradientBrush3 = NULL;
}Brushes;



struct GradientStops
{
	ID2D1GradientStopCollection* pGradientStops = NULL;
	D2D1_GRADIENT_STOP gradientStops[2];

	ID2D1GradientStopCollection* pGradientStops2 = NULL;
	D2D1_GRADIENT_STOP gradientStops2[2];

	ID2D1GradientStopCollection* pGradientStops3 = NULL;
	D2D1_GRADIENT_STOP gradientStops3[2];
}GS;



struct Bitmaps
{
	ID2D1Bitmap* pBitmapEmail = NULL;
	ID2D1Bitmap* pBitmapKey = NULL;
	ID2D1Bitmap* pBitmapLock = NULL;
	ID2D1Bitmap* pBitmapBgr = NULL;
	ID2D1Bitmap* pBitmapHs = NULL;
	ID2D1Bitmap* pBitmapVisual = NULL;
	ID2D1Bitmap* pBitmapAA = NULL;
	ID2D1Bitmap* pBitmapSkinChanger = NULL;
	ID2D1Bitmap* pBitmapSettings = NULL;
	ID2D1Bitmap* pBitmapAccount = NULL;
}Bitmaps;



struct BitmapRects
{
	D2D1_RECT_F KeyBmp;
	D2D1_RECT_F EmailBmp;
	D2D1_RECT_F LockBmp;
	D2D1_RECT_F BitmapHs;
	D2D1_RECT_F BitmapVisual;
	D2D1_RECT_F BitmapAA;
	D2D1_RECT_F BitmapSkinChanger;
	D2D1_RECT_F BitmapSettings;
	D2D1_RECT_F BitmapAccount;
	D2D1_RECT_F BmpBF;
}BitmapRects;



struct TextRects
{
	D2D1_RECT_F Title;
	D2D1_RECT_F NewUser;
	D2D1_RECT_F Or;
	D2D1_RECT_F Email;
	D2D1_RECT_F Password;
	D2D1_RECT_F SignIn;
	D2D1_RECT_F Fpassword;
}TextRects;


struct CheckBoxRectsESP
{
	D2D1_RECT_F r1;
	D2D1_RECT_F r2;
	D2D1_RECT_F r3;
	D2D1_RECT_F r4;
	D2D1_RECT_F r5;
	D2D1_RECT_F r6;

}CheckBoxRectsESP;

struct TextBoxRectsESP
{
	D2D1_RECT_F RectESP;
	D2D1_RECT_F RectSL;
	D2D1_RECT_F Rect2DBox;
	D2D1_RECT_F Rect3DBox;
	D2D1_RECT_F RectGlow;
	D2D1_RECT_F RectSkeleton;
}TextBoxRectsESP;


struct RoundedRects
{
	D2D1_ROUNDED_RECT RoundEmail;
	D2D1_ROUNDED_RECT RoundPassword;
	D2D1_ROUNDED_RECT RoundNewUser;
	D2D1_ROUNDED_RECT RoundSignIn;
}RoundedRects;



struct WriteFormats
{
	IDWriteTextFormat* pTextFormatNormal;
	IDWriteTextFormat* pTextFormatSmaller;
	IDWriteTextFormat* pTextFormatHugeItalic;
	IDWriteTextFormat* pTextFormatHugeOblique;
	IDWriteTextFormat* pTextFormatBigItalic;
	IDWriteTextFormat* pTextFormatNewUser = NULL;
	IDWriteTextFormat* pTextFormatSignIn = NULL;
}WriteFormats;




struct Strings
{
	wstring EmailStr;
	wstring PasswordStr;
}Strings;



struct Cursors
{
	HCURSOR hCursorHand;
	HCURSOR hCursorArrow;
}Cursors;



struct Points
{
	POINT point;
	D2D1_POINT_2F pPointLineFp1;
	D2D1_POINT_2F pPointLineFp2;
}Points;


struct Buttons
{
	const int Email = 1;
	const int Password = 2;
	const int SignIn = 3;
	const int SignUp = 4;
}Buttons;

struct MenuButtons
{
	const int Aimbot = 1;
	const int Visuals = 2;
	const int AntiAim = 3;
	const int SkinChanger = 4;
	const int Settings = 5;
	const int Account = 6;
}MenuButtons;

struct bools
{
	bool xl = false;
	bool xl2 = false;
	bool xl3 = false;
	bool xl4 = false;
	bool xl5 = false;
	bool xl6 = false;
	bool xl7 = false;
}bools;

FLOAT width;
FLOAT heigth;

FLOAT x = 100;
FLOAT y = 100;

void k()
{
	for (FLOAT j = 0; j <= 30; j++)
	{
		y += j;
		Sleep(100);
		if (y == 130)
		{
			y = 100;
		}
	}
}
float GradientStop1 = 0.1;
float GradientStop2 = 0.2;


D2D1_RECT_F Rect2;
int count2;

bool bTimebool = false;
bool bPushTimer = false;
int LastButtonPushed = NULL;
int LastMenuButtonPushed = NULL;


int GlobalCount = 0;
POINT currentPoint;
float InitialX = Rect2.left;


