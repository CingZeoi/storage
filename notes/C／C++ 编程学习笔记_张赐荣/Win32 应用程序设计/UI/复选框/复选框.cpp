/*
ʱ�䣺2017��7��7��������
11��1��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
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
handel [0] = CreateWindow("button","��ѡ��1",WS_CHILD | WS_VISIBLE | BS_CHECKBOX,20,20,80,30,hWnd,(HMENU)ID_1,hinstance,NULL);
handel [1] = CreateWindow("button","��ѡ��2",WS_CHILD | WS_VISIBLE | BS_CHECKBOX,80,20,80,30,hWnd,(HMENU)ID_2,hinstance,NULL);
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
��ѡ��Ҳ��ͨ��button����������������ť��ʽʹ��BS_CHECKBOX������ʹ��BS_AUTOCHECK��ʽ��
��ѡ��Ĭ����λѡ��״̬�������BS_CHECK��ʽ�������������з�Ӧ,����ı�״̬��Ҫ�ֶ�ʵ�֣������BS_AUTOCHECK��ʽ��������ʱ���Զ��ı�ѡ��״̬�����������ֶ�����WM_COMMAND��Ϣ��
������������ָ�ѡ�����ʽ��BS_3STATE��BS_AUTO3STATE��ʽ����������ʽ����ʾһ�����е���̬�ĸ�ѡ�򣬴�auto���������Զ�����WM_COMMAND��Ϣ�ĸ�ѡ��
IsDlgButtonChecked���������ظ�ѡ���״̬��BST_CHECKED��ʾѡ�У�����ֵΪ1��BST_UNCHECKED��ʾλѡ�У�����ֵΪ0��BST_INDETERMINATE���ǵ���̬������ֵΪ2��
CheckDlgButton�����ø�ѡ��ѡ��״̬��Ҫ���õ�ֵ��IsDlgButtonChecked�ķ���ֵһ����
*/