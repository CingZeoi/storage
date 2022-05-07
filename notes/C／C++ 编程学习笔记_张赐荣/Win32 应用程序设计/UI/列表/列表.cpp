/*
时间：2017年12月23日星期六
15点15分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <windows.h>
#include <stdio.h>
struct s
{
int a,b;
};
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE hinstance;
HWND hLb;
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
if(msg.message == WM_KEYDOWN && msg.hwnd == hLb && msg.wParam == 46)
SendMessage(hLb,LB_DELETESTRING,(WPARAM)SendMessage(hLb,LB_GETCURSEL,NULL,NULL),NULL);
	TranslateMessage(&msg);
DispatchMessage(&msg);
}
return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wparam,LPARAM lparam)
{
	struct s *p = NULL,*q = NULL;
	char buf [100],a[10];
	int i = 0;
	switch(message)
{
case WM_CREATE:
hLb = CreateWindow("listbox",NULL,WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_BORDER,20,20,100,100,hWnd,(HMENU)0,hinstance,NULL);
SendMessage(hLb,WM_SETREDRAW,FALSE,NULL);
for(i=0;i<100;i++)
{
	sprintf(a,"项目%d",i+1);
SendMessage(hLb,LB_ADDSTRING,NULL,(LPARAM)a);
}
SendMessage(hLb,LB_INSERTSTRING,20,(LPARAM)"hello,world");
SendMessage(hLb,WM_SETREDRAW,TRUE,NULL);
memset(buf,0,100);
memset(a,0,10);
SendMessage(hLb,LB_GETTEXT,SendMessage(hLb,LB_GETCOUNT,NULL,NULL)-1,(LPARAM)a);
sprintf(buf,"列表中共有%d个项目，最后一向是",SendMessage(hLb,LB_GETCOUNT,NULL,NULL));
p = (struct s *)a;
q = (struct s *)&buf[strlen(buf)];
*q = *p;

SetWindowText(hWnd,buf);
CreateWindow("button","清空",WS_CHILD | WS_VISIBLE,200,30,100,30,hWnd,(HMENU)1,hinstance,NULL);
break;
case WM_COMMAND:
	if(LOWORD(wparam) == 1)
SendMessage(hLb,LB_RESETCONTENT,NULL,NULL);
	break;
case WM_SETFOCUS:
	SetFocus(hLb);
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