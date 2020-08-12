#pragma once
/*
#include <d3d9.h>
#include <d3dx9.h>


#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")



    IDirect3D9Ex* d3dObject = NULL;
    IDirect3DDevice9Ex* d3dDevice = NULL;
    D3DPRESENT_PARAMETERS d3dpp;
    ID3DXFont* d3dFont = 0;
    RECT rect = { 0 };
    const D3DXVECTOR3 v1 = { 0,0,0 };
    D3DXVECTOR3 v2 = {};

    LPDIRECT3DTEXTURE9 imagetex; 
    LPD3DXSPRITE sprite; 
    D3DXVECTOR3 imagepos; 
    D3DXMATRIX m = { 1.2f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f };

    HRESULT InitializeTextureNsprite(LPCWSTR path)
    {
        Rsrces.hr = D3DXCreateTextureFromFile(d3dDevice, L"C:\\Users\\Supreme1337\\source\\repos\\Yamasu02\\LoaderDirectX\\Debug\\test.png", &imagetex);
        Rsrces.hr = D3DXCreateSprite(d3dDevice, &sprite);
        sprite->SetTransform(&m);
        imagepos.x = 0.0f; //coord x of our sprite
        imagepos.y = 0.0f; //coord y of out sprite
        imagepos.z = 0.0f;
        return S_OK;
    }

    HRESULT RenderImage()
    {
        
        d3dDevice->BeginScene();
        sprite->Begin(D3DXSPRITE_ALPHABLEND );//D3DXSPRITE_ALPHABLEND
        Rsrces.hr = sprite->Draw(imagetex, NULL, &v1, &imagepos, 0xFFFFFFFF);
        sprite->End();
        d3dDevice->EndScene();
        return S_OK;
    }

    

    void Construct2(HWND hwnd)
    {
        GetWindowRect(hwnd, &rect);
        int width = rect.right - rect.left;
        int height = rect.bottom - rect.top;
        if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &d3dObject)))
        {
            exit(1);
        }

    
        ZeroMemory(&d3dpp, sizeof(d3dpp)); //to be sure d3dpp is empty
        d3dpp.Windowed = true; //use our global windowed variable to tell if the program is windowed or not
        d3dpp.hDeviceWindow = hwnd; //give the window handle of the window we created above
        d3dpp.BackBufferCount = 1; //set it to only use 1 backbuffer
        d3dpp.BackBufferWidth = 1100; //set the buffer to our window width
        d3dpp.BackBufferHeight = 700; //set the buffer to out window height
        d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8; //the backbuffer format
        d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; //SwapEffect

        HRESULT res = d3dObject->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, 0, &d3dDevice);

        D3DXCreateFont(d3dDevice, 50, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEVICE_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH,L"Comic Sans", &d3dFont);
        InitializeTextureNsprite(L"test.png");
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
        //d3dDevice->Clear(0, 0, D3DCLEAR_TARGET, 111, 1.0f, 0);
        d3dDevice->BeginScene();
        RenderImage();
        //drawText((char*)"reeeeeeeeee", width / 10, height / 10, 255, 171, 0, 182);


        d3dDevice->EndScene();
        d3dDevice->PresentEx(0, 0, 0, 0, 0);

        return 0;
    }

    void Destruct2()
    {
        d3dObject->Release();
        d3dDevice->Release();
        d3dFont->Release();
        if (sprite)
            sprite->Release();
        if (imagetex)
            imagetex->Release();
    }
    */
