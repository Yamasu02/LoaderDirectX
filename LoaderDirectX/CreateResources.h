#pragma once

HRESULT CreateBrushes()
{
    Rsrces.hr = Rsrces.pRenderTarget->CreateSolidColorBrush(ColorF(ColorF::White, 1.0f), &Brushes.pWhiteBrush);
    Rsrces.hr = Rsrces.pRenderTarget->CreateSolidColorBrush(ColorF(ColorF::Black, 1.0f), &Brushes.pBlackBrush);

    Rsrces.hr = Rsrces.pRenderTarget->CreateSolidColorBrush(ColorF(0x1e1c21, 1.0f), &Brushes.pGrayBrush);
    Rsrces.hr = Rsrces.pRenderTarget->CreateSolidColorBrush(ColorF({ 1,1,1,0.1 }), &Brushes.pSemiOpaqueBrush);

    GS.gradientStops[0].color = ColorF(ColorF::Black, 1);
    GS.gradientStops[0].position = 0.1f;
    GS.gradientStops[1].color = ColorF(ColorF::DarkSlateGray, 1);
    GS.gradientStops[1].position = 0.9;

    GS.gradientStops2[0].color = ColorF(ColorF::White, 1);
    GS.gradientStops2[0].position = 0.1f;
    GS.gradientStops2[1].color = ColorF(ColorF::Black, 1);
    GS.gradientStops2[1].position = 0.25;

    GS.gradientStops3[0].color = ColorF(ColorF::DarkSlateGray, 1);
    GS.gradientStops3[0].position = 0.1f;
    GS.gradientStops3[1].color = ColorF(ColorF::Black, 1);
    GS.gradientStops3[1].position = 0.9;

    Rsrces.hr = Rsrces.pRenderTarget->CreateGradientStopCollection(GS.gradientStops, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &GS.pGradientStops);
    Rsrces.hr = Rsrces.pRenderTarget->CreateLinearGradientBrush(LinearGradientBrushProperties(Point2F(0, 0), D2D1::Point2F(550, 1100)), GS.pGradientStops, &Brushes.pLinearGradientBrush);

    Rsrces.hr = Rsrces.pRenderTarget->CreateGradientStopCollection(GS.gradientStops2, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &GS.pGradientStops2);
    Rsrces.hr = Rsrces.pRenderTarget->CreateLinearGradientBrush(LinearGradientBrushProperties(Point2F(0, 0), D2D1::Point2F(550, 1100)), GS.pGradientStops2, &Brushes.pLinearGradientBrush2);

    Rsrces.hr = Rsrces.pRenderTarget->CreateGradientStopCollection(GS.gradientStops3, 2, D2D1_GAMMA_2_2, D2D1_EXTEND_MODE_CLAMP, &GS.pGradientStops3);
    Rsrces.hr = Rsrces.pRenderTarget->CreateLinearGradientBrush(LinearGradientBrushProperties(Point2F(0, 0), D2D1::Point2F(550, 1100)), GS.pGradientStops3, &Brushes.pLinearGradientBrush3);

    return Rsrces.hr;
}

HRESULT CreateFormats()
{
    Rsrces.hr = Rsrces.pDWriteFactory->CreateTextFormat(L"Italic", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 16.0f, L"en-us", &WriteFormats.pTextFormatNormal);
    Rsrces.hr = Rsrces.pDWriteFactory->CreateTextFormat(L"Comic Sans", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 14.5f, L"en-us", &WriteFormats.pTextFormatSmaller);
    Rsrces.hr = Rsrces.pDWriteFactory->CreateTextFormat(L"Comic Sans", NULL, DWRITE_FONT_WEIGHT_THIN, DWRITE_FONT_STYLE_ITALIC, DWRITE_FONT_STRETCH_ULTRA_EXPANDED, 50.f, L"en-us", &WriteFormats.pTextFormatHugeItalic);
    Rsrces.hr = Rsrces.pDWriteFactory->CreateTextFormat(L"Comic Sans", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_OBLIQUE, DWRITE_FONT_STRETCH_NORMAL, 50.5f, L"en-us", &WriteFormats.pTextFormatHugeOblique);
    Rsrces.hr = Rsrces.pDWriteFactory->CreateTextFormat(L"Comic Sans", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_ITALIC, DWRITE_FONT_STRETCH_NORMAL, 26.f, L"en-us", &WriteFormats.pTextFormatBigItalic);
    return Rsrces.hr;
}

HRESULT LoadBitmaps()
{
    Rsrces.hr = LoadBitmapFromResource(Rsrces.pIWICFactory, Rsrces.pRenderTarget, IDB_PNG1, L"PNG", &Bitmaps.pBitmapEmail);
    Rsrces.hr = LoadBitmapFromResource(Rsrces.pIWICFactory, Rsrces.pRenderTarget, IDB_PNG2, L"PNG", &Bitmaps.pBitmapKey);
    Rsrces.hr = LoadBitmapFromResource(Rsrces.pIWICFactory, Rsrces.pRenderTarget, IDB_PNG3, L"PNG", &Bitmaps.pBitmapBgr);
    Rsrces.hr = LoadBitmapFromResource(Rsrces.pIWICFactory, Rsrces.pRenderTarget, IDB_PNG4, L"PNG", &Bitmaps.pBitmapLock);
    Rsrces.hr = LoadBitmapFromResource(Rsrces.pIWICFactory, Rsrces.pRenderTarget, IDB_PNG7, L"PNG", &Bitmaps.pBitmapHs);
    Rsrces.hr = LoadBitmapFromResource(Rsrces.pIWICFactory, Rsrces.pRenderTarget, IDB_PNG6, L"PNG", &Bitmaps.pBitmapVisual);
    Rsrces.hr = LoadBitmapFromResource(Rsrces.pIWICFactory, Rsrces.pRenderTarget, IDB_PNG5, L"PNG", &Bitmaps.pBitmapAA);
    Rsrces.hr = LoadBitmapFromResource(Rsrces.pIWICFactory, Rsrces.pRenderTarget, IDB_PNG8, L"PNG", &Bitmaps.pBitmapAccount);
    Rsrces.hr = LoadBitmapFromResource(Rsrces.pIWICFactory, Rsrces.pRenderTarget, IDB_PNG9, L"PNG", &Bitmaps.pBitmapSettings);
    Rsrces.hr = LoadBitmapFromResource(Rsrces.pIWICFactory, Rsrces.pRenderTarget, IDB_PNG10, L"PNG", &Bitmaps.pBitmapSkinChanger);
    return Rsrces.hr;
}

HRESULT InitializeResources(HWND hwnd)
{
    GetClientRect(hwnd, &Rsrces.rc);
    D2D1_SIZE_U size = SizeU(Rsrces.rc.right - Rsrces.rc.left, Rsrces.rc.bottom - Rsrces.rc.top);

    CoInitialize(NULL);
    Rsrces.hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&Rsrces.pIWICFactory);
    Rsrces.hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &(Rsrces.pDirect2dFactory));
    Rsrces.hr = Rsrces.pDirect2dFactory->CreateHwndRenderTarget(RenderTargetProperties(), HwndRenderTargetProperties(hwnd, size), &(Rsrces.pRenderTarget));

    Rsrces.hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&Rsrces.pDWriteFactory));
    LoadBitmaps();
    CreateBrushes();
    CreateFormats();

    Cursors.hCursorHand = LoadCursor(0, MAKEINTRESOURCE(IDC_HAND));
    Cursors.hCursorArrow = LoadCursor(0, MAKEINTRESOURCE(IDC_ARROW));
    return Rsrces.hr;
}