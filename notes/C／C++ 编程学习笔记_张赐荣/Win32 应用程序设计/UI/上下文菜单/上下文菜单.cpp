/*
时间：2017年7月9日星期日
8点0分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#define ID_1 1001
#define ID_2 1002
#define ID_3 1003
#define ID_4 1004
#define ID_5 1005
#define ID_6 1006
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HMENU CreateContextMenu(void);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
HMENU hMenu;
HMENU hMenuPpp;
	HWND hWnd;
MSG msg;
WNDCLASS wndclass;
 wndclass.style = CS_HREDRAW | CS_VREDRAW;
wndclass.lpfnWndProc = &WndProc;
wndclass.cbClsExtra = 0;
wndclass.cbWndExtra = 0;
wndclass.hInstance = hInstance;
wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
wndclass.lpszMenuName = NULL;
wndclass.lpszClassName = "My window";
RegisterClass(&wndclass);
hMenu = CreateMenu();
hMenuPpp = CreateMenu();
AppendMenu(hMenuPpp,MF_STRING,ID_1,"隐藏(&H)");
AppendMenu(hMenuPpp,MF_STRING,ID_2,"退出(&E)");
AppendMenu(hMenu,MF_POPUP,(unsigned int)hMenuPpp,"操作(&C)");
hWnd = CreateWindow("My Window","hello,windows",WS_OVERLAPPEDWINDOW,50,50,380,250,NULL,hMenu,hInstance,NULL);
ShowWindow(hWnd,SW_NORMAL);
UpdateWindow(hWnd);
while(GetMessage(&msg,NULL,NULL,NULL))
{
TranslateMessage(&msg);
DispatchMessage(&msg);
}
return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wparam,LPARAM lparam)
{
static HMENU hMenu;
	switch(message)
{
case WM_CONTEXTMENU:
TrackPopupMenu(hMenu,TPM_CENTERALIGN | TPM_VCENTERALIGN | TPM_LEFTBUTTON,GET_X_LPARAM(lparam),GET_Y_LPARAM(lparam),NULL,hWnd,NULL);
break;
case WM_COMMAND:
if(LOWORD(wparam) == ID_1)
{
	ShowWindow(hWnd,SW_HIDE);
Sleep(3000);
ShowWindow(hWnd,SW_SHOW);
}
else
if(LOWORD(wparam) == ID_2)
SendMessage(hWnd,WM_CLOSE,NULL,NULL);
break;
case WM_CREATE:
	hMenu = CreateContextMenu();
break;
case WM_CLOSE:
DestroyMenu(hMenu);
	DestroyWindow(hWnd);
break;
case WM_DESTROY:
DestroyMenu(GetMenu(hWnd));
	PostQuitMessage(0);
break;
default:
return DefWindowProc(hWnd,message,wparam,lparam);
break;
}
return 0;
}
HMENU CreateContextMenu(void)
{
HMENU hMenu = CreateMenu();
AppendMenu(hMenu,MF_STRING,ID_3,"羿射九日");
AppendMenu(hMenu,MF_STRING,ID_4,"安放地雷");
AppendMenu(hMenu,MF_STRING,ID_5,"烈焰漩涡");
AppendMenu(hMenu,MF_STRING,ID_6,"龙战四野");
return hMenu;
}