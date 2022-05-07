/*
 时间：2017年7月8日星期六
13点44分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <windows.h>
#include <stdio.h>
#define ID_1 1001
#define ID_2 1002
HMENU hMenu;
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
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
char buffer [5];
switch(message)
{
case WM_CHAR:
sprintf(buffer,"%d",wparam);
MessageBox(hWnd,buffer,"Message",64);
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
MessageBox(hWnd,"hello,win","Message",64);
break;
case WM_CLOSE:
DestroyWindow(hWnd);
break;
case WM_DESTROY:
DestroyMenu(hMenu);
	PostQuitMessage(0);
break;
default:
return DefWindowProc(hWnd,message,wparam,lparam);
break;
}
return 0;
}
/*
CreateMenu创建可弹出菜单，返回菜单句柄，类型是HMENU；
还有个CreatePopupMenu，也是创建子菜单，他们的区别是，前者创建的菜单都是顶级菜单，比如常见的文件，编辑，这些都由CreateMenu创建；
CreatePopupMenu创建二级及比二级低级的菜单，就是向右展开的菜单；
其实这两个混着用也没问题，windows会进行纠正，为了规范，最好别混着用；
AppentMenu向可弹出菜单中添加项目，函数原型如下：
BOOL AppendMenu(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);
hMenu：可弹出菜单句柄；
uFlags：标志，可以为以下值之一：
MF_STRING：要添加的是非弹出菜单；
MF_POPUP：要添加的是弹出菜单；
uIDNewItem：要添加的菜单的ID，当要添加的是弹出菜单时，要将可弹出菜单句柄进行类型转换填入；
lpNewItem：菜单标题；
窗口销毁时要销毁菜单，使用DestroyMenu，参数是在创建窗口时传入的总菜单句柄；
当菜单被点击时，窗口也会收到一条WM_COMMAND消息，处理方式与控件类似；
*/