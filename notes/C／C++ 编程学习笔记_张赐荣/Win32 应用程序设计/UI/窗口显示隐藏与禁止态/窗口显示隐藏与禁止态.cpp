/*
时间：2017年12月15日星期五
16点9分
编译器：Microsoft Visual Studio 2008
*/
#include <windows.h>
#include <stdio.h>
HINSTANCE hinstance;
struct bt
{
	HWND h;
BOOL v;
}handle [4];
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
HWND hWnd;
MSG msg;
WNDCLASS wndclass;
hinstance = hInstance;
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
//memset(&handle,NULL,sizeof(bt)*4);
int i = 0,j = 0,u = 0;
while(GetMessage(&msg,NULL,NULL,NULL))
{
if(msg.message == WM_KEYDOWN && msg.wParam == 9)
{
j = 0;
	while(j<=3)
{
	if(msg.hwnd == handle [j].h)
	{
		u = TRUE;
		break;
	}
j++;
}
if(u)
{
if(j == i)
j= i+1;
if(j > 3)
j = 0;
while(j!=i)
{
if(!handle [j].v)
break;
j >= 3 ? j=0 : j++;
if(j == i)
j++;
}
SetFocus(handle [j].h);
i = j;
j = 0;
u = FALSE;
}	
}
TranslateMessage(&msg);
DispatchMessage(&msg);
}
return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wparam,LPARAM lparam)
{
	switch(message)
{
	case WM_COMMAND:
				if(LOWORD(wparam) == 0)
				{
			IsWindowVisible(handle[1].h ) ? ShowWindow(handle[1].h,SW_HIDE) : ShowWindow(handle[1].h,SW_SHOW);
handle[1].v = !IsWindowVisible(handle [1].h);
				}
		else
			if(LOWORD(wparam) == 2)
			{
							EnableWindow(handle [3].h,!IsWindowEnabled(handle[3].h));
handle[3].v = !IsWindowEnabled(handle [3].h);
			}
break;
	case WM_CREATE:
		handle [0].h = CreateWindow("button","button1",WS_CHILD | WS_VISIBLE,20,20,50,50,hWnd,(HMENU)0,hinstance,NULL);
		SetFocus(handle [0].h);
		handle [1].h = CreateWindow("button","button2",WS_CHILD | WS_VISIBLE,90,20,50,50,hWnd,(HMENU)1,hinstance,NULL);
	handle [2].h = CreateWindow("button","button3",WS_CHILD | WS_VISIBLE,160,20,50,50,hWnd,(HMENU)2,hinstance,NULL);
		handle [3].h = CreateWindow("button","button4",WS_CHILD | WS_VISIBLE,230,20,50,50,hWnd,(HMENU)3,hinstance,NULL);
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