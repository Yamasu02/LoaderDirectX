#pragma once

void DrawCursor(D2D1_RECT_F rect, ID2D1Brush* pBrush)
{
    Rsrces.pRenderTarget->DrawLine({ rect.left + 10, rect.top + 3 }, {rect.left + 10,rect.bottom - 3}, pBrush, 1, NULL);
}


void DrawTextInBox(D2D1_RECT_F rect, IDWriteTextFormat* pTextFormat,wstring str)
{
    pTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
    rect.left += 10;
    Rsrces.pRenderTarget->DrawTextW((WCHAR*)str.c_str(), str.length(), pTextFormat, rect, Brushes.pWhiteBrush);
}


void DrawCheckBox(D2D1_RECT_F rect, ID2D1Brush* brush, bool b,int mode)
{
    Rsrces.pRenderTarget->DrawRectangle(rect, brush);
    if (b)
    {
        rect.left += (rect.right - rect.left) / 7;
        rect.right -= (rect.right - rect.left) / 7;
        rect.top += (rect.bottom - rect.top) / 7;
        rect.bottom -= (rect.bottom - rect.top) / 7;
        if (mode == 1)
        {
            Rsrces.pRenderTarget->FillRectangle(rect, brush);
        }

        else if (mode == 2)
        {
            Rsrces.pRenderTarget->DrawLine({ rect.left,rect.top + ((rect.bottom - rect.top) / 2) }, { rect.left + ((rect.right - rect.left) / 2),rect.bottom }, Brushes.pWhiteBrush, 2);
            Rsrces.pRenderTarget->DrawLine({ rect.left + ((rect.right - rect.left) / 2),rect.bottom }, { rect.right,rect.top }, Brushes.pWhiteBrush, 2);
        }
    }
}


D2D1_ROUNDED_RECT RectToRoundedRect(D2D1_RECT_F rect,float x,float y)
{
    return {rect, x, y};
}

void DrawSlider(D2D1_RECT_F rect, ID2D1Brush* pBrush, bool b)
{
    D2D1_ROUNDED_RECT rounded = { rect,15,15 };
    Rsrces.pRenderTarget->DrawRoundedRectangle(rounded, pBrush);
    D2D1_ELLIPSE ellipse = { {rect.left + (rect.right - rect.left) / 4,rect.top + (rect.bottom - rect.top) / 2}, 15,15 };
    if (b)
    {
        ellipse.point = { rect.left + (rect.right - rect.left) * 3 / 4,rect.top + (rect.bottom - rect.top) / 2 };
    }
    Rsrces.pRenderTarget->FillEllipse(ellipse, pBrush);
}