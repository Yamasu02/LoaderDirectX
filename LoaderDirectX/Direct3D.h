#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")


class Direct3D9
{
public:
    IDirect3D9Ex* d3dObject = NULL;
    IDirect3DDevice9Ex* d3dDevice = NULL;
    D3DPRESENT_PARAMETERS d3dparams;
    ID3DXFont* d3dFont = 0;
    RECT rect = { 0 };


    LPDIRECT3DTEXTURE9 imagetex; 
    LPD3DXSPRITE sprite; 
    D3DXVECTOR3 imagepos; 

    HRESULT InitializeTextureNsprite(LPCWSTR path)
    {
        D3DXCreateTextureFromFileW(d3dDevice, path, &imagetex);
        D3DXCreateSprite(d3dDevice, &sprite);
        imagepos.x = 0.0f; 
        imagepos.y = 0.0f; 
        imagepos.z = 0.0f; 
        return S_OK;
    }

    HRESULT RenderImage()
    {
        if (SUCCEEDED(d3dDevice->BeginScene()))
        {
            sprite->Begin(D3DXSPRITE_ALPHABLEND);
            sprite->Draw(imagetex, NULL, NULL, &imagepos, 0xFFFFFFFF);
            sprite->End();
            d3dDevice->EndScene();
            return S_OK;
        }
        return E_FAIL; 
    }


    Direct3D9(HWND hwnd)
    {
        GetWindowRect(hwnd, &rect);
        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;
        if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &d3dObject)))
        {
            exit(1);
        }

        RtlSecureZeroMemory(&d3dparams, sizeof(d3dparams));

        d3dparams.BackBufferWidth = width;
        d3dparams.BackBufferHeight = height;
        d3dparams.Windowed = TRUE;
        d3dparams.SwapEffect = D3DSWAPEFFECT_DISCARD;
        d3dparams.hDeviceWindow = hwnd;
        d3dparams.MultiSampleQuality = D3DMULTISAMPLE_NONE;
        d3dparams.BackBufferFormat = D3DFMT_A8R8G8B8;
        d3dparams.EnableAutoDepthStencil = TRUE;
        d3dparams.AutoDepthStencilFormat = D3DFMT_D16;

        HRESULT res = d3dObject->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dparams, 0, &d3dDevice);

        D3DXCreateFont(d3dDevice, 50, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEVICE_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH,L"Comic Sans", &d3dFont);

    }

    void drawText(char* String, int x, int y, int a, int r, int g, int b)
    {
        RECT FontPos;
        FontPos.left = x;
        FontPos.top = y;
        d3dFont->DrawTextA(0, String, strlen(String), &FontPos, DT_NOCLIP, D3DCOLOR_ARGB(a, r, g, b));
    }

    int render(HWND hWnd)
    {
        RECT rect;
        GetWindowRect(hWnd, &rect);
        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;
        if (d3dDevice == nullptr)
            return 1;
        d3dDevice->Clear(0, 0, D3DCLEAR_TARGET, 111, 1.0f, 0);
        d3dDevice->BeginScene();

        drawText((char*)"reeeeeeeeee", width / 10, height / 10, 255, 171, 0, 182);


        d3dDevice->EndScene();
        d3dDevice->PresentEx(0, 0, 0, 0, 0);

        return 0;
    }

    ~Direct3D9()
    {
        d3dObject->Release();
        d3dDevice->Release();
        d3dFont->Release();
        if (sprite)
            sprite->Release();
        if (imagetex)
            imagetex->Release();
    }
};

