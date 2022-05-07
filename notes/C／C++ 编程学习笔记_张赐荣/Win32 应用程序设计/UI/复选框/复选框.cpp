/*
时间：2017年7月7日星期五
11点1分
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
HINSTANCE hinstance;
HWND handel [LENGTH];
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	HWND hWnd;
	MSG msg;
WNDCLASS wndclass;
hinstance = hInstance;
int i;
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
SetFocus(handel [0]);
while(GetMessage(&msg,NULL,NULL,NULL))
{
for(i=0;i<=LENGTH-1;i++)
{
	if(msg.hwnd == handel [i] && msg.message == WM_KEYDOWN && msg.wParam == 9)
	{
		i == LENGTH -1 ? i = 0 : i++;
SetFocus(handel [i]);
break;
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
if(LOWORD(wparam) == ID_1)
CheckDlgButton(hWnd,ID_1,!IsDlgButtonChecked(hWnd,ID_1));
else
if(LOWORD(wparam) == ID_2)
CheckDlgButton(hWnd,ID_2,!IsDlgButtonChecked(hWnd,ID_2));
break;
case WM_CREATE:	
handel [0] = CreateWindow("button","复选框1",WS_CHILD | WS_VISIBLE | BS_CHECKBOX,20,20,80,30,hWnd,(HMENU)ID_1,hinstance,NULL);
handel [1] = CreateWindow("button","复选框2",WS_CHILD | WS_VISIBLE | BS_CHECKBOX,80,20,80,30,hWnd,(HMENU)ID_2,hinstance,NULL);
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
复选框也是通过button窗口类来创建，按钮样式使用BS_CHECKBOX，或者使用BS_AUTOCHECK样式；
复选框默认是位选中状态，如果是BS_CHECK样式，单机它不会有反应,这个改变状态需要手动实现，如果是BS_AUTOCHECK样式，单机它时会自动改变选中状态，所以无需手动处理WM_COMMAND消息；
还有另外的两种复选框的样式，BS_3STATE和BS_AUTO3STATE样式，这两种样式都表示一个具有第三态的复选框，带auto字样的是自动处理WM_COMMAND消息的复选框。
IsDlgButtonChecked函数，返回复选框的状态，BST_CHECKED表示选中，它的值为1，BST_UNCHECKED表示位选中，它的值为0，BST_INDETERMINATE表是第三态，它的值为2；
CheckDlgButton，设置复选框选中状态，要设置的值和IsDlgButtonChecked的返回值一样。
*/