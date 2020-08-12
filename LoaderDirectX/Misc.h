#pragma once


HRESULT LoadBitmapFromResource(IWICImagingFactory* pIWICFactory, ID2D1HwndRenderTarget* pRenderTarget, int id, LPCWSTR type, ID2D1Bitmap** ppBitmap)
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
        hr = pStream->InitializeFromMemory((BYTE*)(pImageFile), imageFileSize);
    }

    if (SUCCEEDED(hr))
    {
        hr = pIWICFactory->CreateDecoderFromStream(pStream, NULL, WICDecodeMetadataCacheOnLoad, &pDecoder);
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
        hr = pConverter->Initialize(pSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeMedianCut);


        if (SUCCEEDED(hr))
        {
            hr = pRenderTarget->CreateBitmapFromWicBitmap(pConverter, NULL, ppBitmap);
        }

        return hr;
    }
}

HRESULT LoadBitmapFromFile(IWICImagingFactory* pIWICFactory, ID2D1HwndRenderTarget* pRenderTarget, LPCWSTR path, ID2D1Bitmap** ppBitmap)
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

D2D1_RECT_F RectToD2DRect(RECT rect)
{
    return { (FLOAT)rect.left , (FLOAT)rect.top , (FLOAT)rect.right , (FLOAT)rect.bottom };
}

D2D1_POINT_2F RectToPoint(D2D1_RECT_F rect, int count)
{
    return { rect.left + count, rect.bottom - ((rect.bottom - rect.top) / 2) };
}

D2D1_RECT_F PointToRect(D2D1_POINT_2F point, int r)
{
    return { point.x - r,point.y - r,point.x + r, point.x + r };
}

BOOL PointBelongsToRect(HWND hwnd, LPPOINT lp, D2D1_RECT_F rect)
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

BOOL CursorBelongsToRect(HWND hwnd, D2D1_RECT_F rect)
{

    if (Points.point.x >= rect.left && Points.point.x <= rect.right && Points.point.y >= rect.top && Points.point.y <= rect.bottom)
    {
        return true;
    }
    else
    {
        return false;
    }
}

D2D_RECT_F BmpRectToSelectRect(D2D_RECT_F rect)
{
    return { rect.left - 10,rect.top - 10,rect.right + 10,rect.bottom + 10 };
}

void CursorHandler(HWND hwnd)
{
    if (CursorBelongsToRect(hwnd, TextRects.SignIn) || CursorBelongsToRect(hwnd, TextRects.NewUser) || CursorBelongsToRect(hwnd, TextRects.Fpassword))
    {
        SetCursor(Cursors.hCursorHand);
    }
    else
    {
        SetCursor(Cursors.hCursorArrow);
    }
}

void Timer()
{
    while (1)
    {
        bTimebool = !bTimebool;
        Sleep(450);
    }
}
