/*
时间：2017年7月1日星期六
14点21分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <windows.h>	
#include <stdio.h>
#include "math.h"
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HMODULE hModule;
int (*p1)(int,int);
int (*p2)(int,int);
int (*p3)(int,int);
int (*p4)(int,int);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	HWND hWnd;
	MSG msg;
WNDCLASS wndclass;
hModule = LoadLibrary("math.dll");
if(hModule == NULL)
{
MessageBox(NULL,"核心组建加载失败","Message",48);
return 0;
}
p1 = (int (*)(int,int))GetProcAddress(hModule,"plus");
p2 = (int (*)(int,int))GetProcAddress(hModule,"minus");
p3 = (int (*)(int,int))GetProcAddress(hModule,"multiply");
p4 = (int (*)(int,int))GetProcAddress(hModule,"divide");
if(p1 == NULL || p2 == NULL || p3 == NULL || p4 == NULL)
{
MessageBox(NULL,"未找到函数地址","Message",48);
FreeLibrary(hModule);
return 0;
}
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
hWnd = CreateWindow("My Window","hello,windows",WS_OVERLAPPEDWINDOW,50,50,380,250,NULL,NULL,hInstance,NULL);
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
char buffer [7];
static int i = 0;
switch(message)
{
case WM_CHAR:
if(wparam == 13)
{
	i = !(i == 0 || i == 4) ? i+1 : 1;
switch(i)
{
case 1:
sprintf(buffer,"6+2=%d",p1(6,2));
break;
case 2:
sprintf(buffer,"6-2=%d",p2(6,2));
break;
case 3:
sprintf(buffer,"6*2=%d",p3(6,2));
break;
case 4:
sprintf(buffer,"6/2=%d",p4(6,2));
break;
default :
break;
}
MessageBox(hWnd,buffer,"Message",64);
}
break;
case WM_CREATE:
MessageBox(hWnd,"hello,win","Message",64);
break;
case WM_CLOSE:
DestroyWindow(hWnd);
	break;
case WM_DESTROY:
FreeLibrary(hModule);
	PostQuitMessage(0);
break;
default:
return DefWindowProc(hWnd,message,wparam,lparam);
	break;
}
return 0;
}