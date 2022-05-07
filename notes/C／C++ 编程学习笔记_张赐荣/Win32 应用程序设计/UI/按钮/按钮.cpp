/*
时间：2017年7月6日星期四
14点46分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <windows.h>
#include <stdio.h>
#define ID_1 1001
#define ID_2 1002
#define LENGTH 2
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HWND hBt [LENGTH];
HINSTANCE hinstance;
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
hWnd = CreateWindow("My Window","hello,Windows",WS_OVERLAPPEDWINDOW,50,50,380,250,NULL,NULL,hInstance,NULL);
ShowWindow(hWnd,SW_NORMAL);
UpdateWindow(hWnd);
int i = 0;
while(GetMessage(&msg,NULL,NULL,NULL))
{
if(msg.message == WM_KEYDOWN && msg.wParam == 9)
{
i = 0;
while(i<=1)
{
if(hBt [i] == msg.hwnd)
break;
i++;
}
i == 1 ? i = 0 : i++;
SetFocus(hBt [i]);
}
TranslateMessage(&msg);
DispatchMessage(&msg);
}
return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wparam,LPARAM lparam)
{
char buf [50];
switch(message)
{
case WM_COMMAND:
if(LOWORD(wparam) == ID_1)
{
GetWindowText(hBt [0],buf,50);
MessageBox(hWnd,buf,"Message",64);
}
else
if(LOWORD(wparam) == ID_2)
{
GetWindowText(hBt [1],buf,50);
MessageBox(hWnd,buf,"Message",0);
}
break;
case WM_CREATE:
hBt [0] = CreateWindow("button","button1",WS_CHILD | WS_VISIBLE,50,50,80,50,hWnd,(HMENU)ID_1,hinstance,NULL);
SetFocus(hBt [0]);
hBt [1] = CreateWindow("button","button2",WS_CHILD | WS_VISIBLE,160,50,80,50,hWnd,(HMENU)ID_2,hinstance,NULL);
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
/*
通过CreateWindow创建一个按钮，返回的当然是按钮的句柄，窗口类名写button，这个是windows预定义的窗口类名，第二个参数是按钮标题，
WS_CHILD表示要创建的是子窗口，WS_VISIBLE表示可以显示出来，父窗口句柄就写主窗口的句柄，然后是子窗口ID，这个ID自己随便写；
副窗口绑定一个子窗口后，当按钮被单机时，父窗口会收到一条WM_COMMAND消息，如果wparam中是按钮的ID，就是自定义的ID，就表明用户单机了按钮；
这时父窗口可以通过ID判断是哪个控件的消息，并做出响应；
本例中还掩饰了按tab在控件之间切换。
*/