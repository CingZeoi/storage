/*
ʱ�䣺2017��7��6��������
14��46��
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
ͨ��CreateWindow����һ����ť�����صĵ�Ȼ�ǰ�ť�ľ������������дbutton�������windowsԤ����Ĵ����������ڶ��������ǰ�ť���⣬
WS_CHILD��ʾҪ���������Ӵ��ڣ�WS_VISIBLE��ʾ������ʾ�����������ھ����д�����ڵľ����Ȼ�����Ӵ���ID�����ID�Լ����д��
�����ڰ�һ���Ӵ��ں󣬵���ť������ʱ�������ڻ��յ�һ��WM_COMMAND��Ϣ�����wparam���ǰ�ť��ID�������Զ����ID���ͱ����û������˰�ť��
��ʱ�����ڿ���ͨ��ID�ж����ĸ��ؼ�����Ϣ����������Ӧ��
�����л������˰�tab�ڿؼ�֮���л���
*/