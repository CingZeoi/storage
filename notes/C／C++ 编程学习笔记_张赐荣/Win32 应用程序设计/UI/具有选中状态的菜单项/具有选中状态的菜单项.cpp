/*
ʱ�䣺2017��7��8��������
18��40��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
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
AppendMenu(hMenuPpp,MF_STRING,ID_1,"��Ϊ");
AppendMenu(hMenuPpp,MF_STRING,ID_2,"����");
AppendMenu(hMenuPpp,MF_STRING,ID_3,"С��ϵ��");
AppendMenu(hMenuPpp,MF_STRING,ID_4,"Iphone");
AppendMenu(hMenu,MF_POPUP,(unsigned int)hMenuPpp,"�ֻ�(&M)");
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
CheckMenuRadioItem������������һ���˵���ѡ��״̬����һ������ �ǲ˵������ڲ˵�������ڶ����͵���������ָ��һ����Χ��
�����Χ�У�ֻ����һ���˵��ѡ�У���ѡ������ĳ��ʱ����ǰѡ�е���Զ�ȡ�����������IDҪ����
���ĸ�������Ҫѡ�еĲ˵����ID�����������дMF_BYCOMMAND���У�����ɶ��˼��Ҳ��֪����
GetMenu���Ի�ȡ���ڲ˵�������������Ǵ��ھ�������ز˵��������
GetSubMenu��ȡ�ɵ����˵��к��еĿɵ����˵��ľ������һ�����������ڲ˵�������ڶ��������ǿɵ����˵�����ţ���ʾ�ڼ����ɵ����˵�����0��ʼ��
*/