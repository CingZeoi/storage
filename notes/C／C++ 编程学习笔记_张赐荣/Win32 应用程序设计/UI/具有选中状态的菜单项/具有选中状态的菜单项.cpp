/*
时间：2017年7月8日星期六
18点40分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <windows.h>
#include <stdio.h>
#define ID_1 1001
#define ID_2 1002
#define ID_3 1003
#define ID_4 1004
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
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
AppendMenu(hMenuPpp,MF_STRING,ID_1,"华为");
AppendMenu(hMenuPpp,MF_STRING,ID_2,"三星");
AppendMenu(hMenuPpp,MF_STRING,ID_3,"小米系列");
AppendMenu(hMenuPpp,MF_STRING,ID_4,"Iphone");
AppendMenu(hMenu,MF_POPUP,(unsigned int)hMenuPpp,"手机(&M)");
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
switch(message)
{
case WM_COMMAND:
if(LOWORD(wparam) == ID_1)
CheckMenuRadioItem(GetSubMenu(GetMenu(hWnd),0),ID_1,ID_4,ID_1,MF_BYCOMMAND);
else
if(LOWORD(wparam) == ID_2)
CheckMenuRadioItem(GetSubMenu(GetMenu(hWnd),0),ID_1,ID_4,ID_2,MF_BYCOMMAND);
else
if(LOWORD(wparam) == ID_3)
CheckMenuRadioItem(GetSubMenu(GetMenu(hWnd),0),ID_1,ID_4,ID_3,MF_BYCOMMAND);
else
if(LOWORD(wparam) == ID_4)
CheckMenuRadioItem(GetSubMenu(GetMenu(hWnd),0),ID_1,ID_4,ID_4,MF_BYCOMMAND);
break;
case WM_CLOSE:
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
/*
CheckMenuRadioItem函数可以设置一个菜单的选中状态，第一个参数 是菜单项所在菜单句柄，第二个和第三个参数指定一个范围，
这个范围中，只能有一个菜单项被选中，当选中其中某项时，先前选中的项将自动取消，所以设计ID要有序；
第四个参数是要选中的菜单项的ID，第五个参数写MF_BYCOMMAND就行，具体啥意思我也不知道；
GetMenu可以获取窗口菜单栏句柄，参数是窗口句柄，返回菜单栏句柄；
GetSubMenu获取可弹出菜单中含有的可弹出菜单的句柄，第一个参数是所在菜单句柄，第二个参数是可弹出菜单的序号，表示第几个可弹出菜单，从0开始；
*/