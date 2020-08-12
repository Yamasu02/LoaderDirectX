#pragma once
#include <Windows.h>


HANDLE hMapFile;
void* pBuf;
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");


void MapSharedMemory()
{
    hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4, szName);
    pBuf = MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(int));
}