/*
 ʱ�䣺2017��7��8��������
13��44��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
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
AppendMenu(hMenuPpp,MF_STRING,ID_1,"����(&H)");
AppendMenu(hMenuPpp,MF_STRING,ID_2,"�˳�(&E)");
AppendMenu(hMenu,MF_POPUP,(unsigned int)hMenuPpp,"����(&C)");
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
CreateMenu�����ɵ����˵������ز˵������������HMENU��
���и�CreatePopupMenu��Ҳ�Ǵ����Ӳ˵������ǵ������ǣ�ǰ�ߴ����Ĳ˵����Ƕ����˵������糣�����ļ����༭����Щ����CreateMenu������
CreatePopupMenu�����������ȶ����ͼ��Ĳ˵�����������չ���Ĳ˵���
��ʵ������������Ҳû���⣬windows����о�����Ϊ�˹淶����ñ�����ã�
AppentMenu��ɵ����˵��������Ŀ������ԭ�����£�
BOOL AppendMenu(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);
hMenu���ɵ����˵������
uFlags����־������Ϊ����ֵ֮һ��
MF_STRING��Ҫ��ӵ��Ƿǵ����˵���
MF_POPUP��Ҫ��ӵ��ǵ����˵���
uIDNewItem��Ҫ��ӵĲ˵���ID����Ҫ��ӵ��ǵ����˵�ʱ��Ҫ���ɵ����˵������������ת�����룻
lpNewItem���˵����⣻
��������ʱҪ���ٲ˵���ʹ��DestroyMenu���������ڴ�������ʱ������ܲ˵������
���˵������ʱ������Ҳ���յ�һ��WM_COMMAND��Ϣ������ʽ��ؼ����ƣ�
*/