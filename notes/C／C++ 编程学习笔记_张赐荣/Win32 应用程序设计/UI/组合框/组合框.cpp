/*
时间：2017年12月16日星期六
19点41分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <windows.h>
#include <stdio.h>
HWND hCb;
HINSTANCE hinstance;
struct s
{
	int a,b;
};
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
while(GetMessage(&msg,NULL,NULL,NULL))
{
if(msg.message == WM_KEYDOWN && msg.hwnd == hCb && msg.wParam == 46)
SendMessage(hCb,CB_DELETESTRING,(WPARAM)SendMessage(hCb,CB_GETCURSEL,NULL,NULL),NULL);
	TranslateMessage(&msg);
DispatchMessage(&msg);
}
return CB_GETCURSEL;
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wparam,LPARAM lparam)
{
static int i = 0;
char buf [100],a [8],b [100];
struct s *p,*q;
switch(message)
{
case WM_CREATE:
	hCb = CreateWindow("combobox",NULL,WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,20,20,300,180,hWnd,(HMENU)0,hinstance,NULL);
	while(i<100)
	{
	sprintf(buf,"项目%d",i+1);
		SendMessage(hCb,CB_ADDSTRING,NULL,(LPARAM)buf);
	i++;
	}
	SendMessage(hCb,CB_INSERTSTRING,20,(LPARAM)"hello,world");
 memset(buf,0,sizeof(char)*100);
memset(a,0,sizeof(char)*8);
SendMessage(hCb,CB_GETLBTEXT,(WPARAM)SendMessage(hCb,CB_GETCOUNT,NULL,NULL)-1,(LPARAM)a);
 sprintf(buf,"组合框里共有%d个项目，最后一向是",SendMessage(hCb,CB_GETCOUNT,NULL,NULL));
p = (struct s *)&buf[strlen(buf)];
q = (struct s *)&a[0];
*p = *q;
SendMessage(hCb,CB_SETCURSEL,(WPARAM)0,NULL);	
 SetWindowText(hWnd,buf);
	CreateWindow("button","清空",WS_CHILD | WS_VISIBLE,300,20,60,30,hWnd,(HMENU)1,hinstance,NULL);
	break;
case WM_COMMAND:
	if(LOWORD(wparam) == 1)
SendMessage(hCb,CB_RESETCONTENT	,NULL,NULL);
	break;
case WM_SETFOCUS:
	SetFocus(hCb);
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