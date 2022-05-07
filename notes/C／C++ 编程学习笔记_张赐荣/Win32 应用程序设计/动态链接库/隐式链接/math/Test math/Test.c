/*
时间：2017年6月29日星期四
21点38分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <windows.h>	
#include <stdio.h>
#include "math.h"
#pragma comment(lib, "math.lib")
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
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
sprintf(buffer,"6+2=%d",plus(6,2));
break;
case 2:
sprintf(buffer,"6-2=%d",minus(6,2));
break;
case 3:
sprintf(buffer,"6*2=%d",multiply(6,2));
break;
case 4:
sprintf(buffer,"6/2=%d",divide(6,2));
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
PostQuitMessage(0);
break;
default:
return DefWindowProc(hWnd,message,wparam,lparam);
	break;
}
return 0;
}