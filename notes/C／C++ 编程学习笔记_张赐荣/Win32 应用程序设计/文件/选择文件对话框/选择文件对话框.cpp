/*
ʱ�䣺2017��7��31������һ
16��26��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
*/
#include <windows.h>
#include <stdio.h>
#define ID1 1001
#define ID2 1002
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
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
hWnd = CreateWindow("My Window","ѡ���ļ�",WS_OVERLAPPEDWINDOW,50,50,380,250,NULL,NULL,hInstance,NULL);
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
static char* szFile = new char[512];
static char* szFileTitle = new char[512];
	static OPENFILENAME ofn;
char buffer [1024];
switch(message)
{
case WM_COMMAND:
	if(LOWORD(wparam) == ID1)
	{
if(GetOpenFileName(&ofn))
{
	sprintf(buffer,"�ļ�����%s\n·����%s\n",szFileTitle,szFile);
MessageBox(hWnd,buffer,"Message",64);
}
	}
if(LOWORD(wparam) == ID2)
{
if(GetSaveFileName(&ofn))
{	
sprintf(buffer,"Ŀ¼��%s",szFile);
MessageBox(hWnd,buffer,"Message",64);
}
}
break;
case WM_CREATE:
memset(&ofn, 0, sizeof(ofn));
memset(szFile, 0, sizeof(char)*512);
memset(szFileTitle, 0, sizeof(char)*512);
ofn.lStructSize = sizeof(ofn);
ofn.hwndOwner = hWnd;
ofn.hInstance = hinstance;
ofn.lpstrFilter = "��Ƶ�ļ�\0*.mp3;*.wma;*.wav\0��Ƶ�ļ�\0*.mp4;*.flv;*.rmvb\0�ı��ļ�\0*.txt;*.doc\0All File\0*.*\0";
ofn.nFilterIndex = 1;
ofn.lpstrFile = szFile;
ofn.nMaxFile = sizeof(WCHAR)*512;
ofn.lpstrFileTitle = szFileTitle;
ofn.nMaxFileTitle = sizeof(WCHAR)*512;
ofn.Flags = OFN_EXPLORER;
	CreateWindow("button","���ļ�",WS_CHILD | WS_VISIBLE,50,50,100,60,hWnd,(HMENU)ID1,hinstance,NULL);
CreateWindow("button","�����ļ�",WS_CHILD | WS_VISIBLE,200,50,100,60,hWnd,(HMENU)ID2,hinstance,NULL);
	break;
case WM_CLOSE:
DestroyWindow(hWnd);
break;
case WM_DESTROY:
delete szFileTitle;
delete []szFile;
	PostQuitMessage(0);
break;
default:
return DefWindowProc(hWnd,message,wparam,lparam);
break;
}
return 0;
}
/*
������Ҫ�ṩ���·���������OpenFileName�ṹ�岻��������
*/