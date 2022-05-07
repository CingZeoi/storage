#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <ShlObj.h>
#include <Shlwapi.h>
#include "recorder.h"
#pragma comment (lib,"Shlwapi.lib")
HMODULE hModule;
char folder [256];
int length=0,v=0;
void (__stdcall *lpfnDestroy)();
void (__stdcall *lpfnInit)();
BOOL (__stdcall *lpfnBegin)();
BOOL (__stdcall *lpfnPause)();
BOOL (__stdcall *lpfnContinue)();
BOOL (__stdcall *lpfnStop)();
BOOL (__stdcall *lpfnSave)(LPCSTR);
BOOL (__stdcall *lpfnIsRcrd)();
HWND handle[6];
HINSTANCE hinstance;
int i = 1;
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
MSG msg;
hinstance = hInstance;
hModule = LoadLibrary("recorder.dll");
if(!hModule)
{
MessageBox(NULL,"�����������ʧ��","message",48);
return 0;
}
lpfnDestroy = (void (__stdcall *)())GetProcAddress(hModule,"Destroy");
if(lpfnDestroy == NULL)
{
MessageBox(NULL,"δ�ҵ�������ַ","message",48);
FreeLibrary(hModule);
return 0;
}
lpfnInit = (void (__stdcall *)())GetProcAddress(hModule,"Init");
if(lpfnDestroy == NULL)
{
MessageBox(NULL,"δ�ҵ�������ַ","message",48);
FreeLibrary(hModule);
return 0;
}
lpfnBegin = (BOOL (__stdcall *)())GetProcAddress(hModule,"Begin");
if(lpfnBegin == NULL)
{
MessageBox(NULL,"δ�ҵ�������ַ","message",48);
FreeLibrary(hModule);
return 0;
}
lpfnPause = (BOOL (__stdcall *)())GetProcAddress(hModule,"Pause");
if(lpfnPause == NULL)
{
MessageBox(NULL,"δ�ҵ�������ַ","message",48);
FreeLibrary(hModule);
return 0;
}
lpfnContinue = (BOOL (__stdcall *)())GetProcAddress(hModule,"Continue");
if(lpfnContinue == NULL)
{
MessageBox(NULL,"δ�ҵ�������ַ","message",48);
FreeLibrary(hModule);
return 0;
}
lpfnStop = (BOOL (__stdcall *)())GetProcAddress(hModule,"Stop");
if(lpfnStop == NULL)
{
MessageBox(NULL,"δ�ҵ�������ַ","message",48);
FreeLibrary(hModule);
return 0;
}
lpfnSave = (BOOL (__stdcall *)(LPCSTR))GetProcAddress(hModule,"Save");
if(lpfnSave == NULL)
{
MessageBox(NULL,"δ�ҵ�������ַ","message",48);
FreeLibrary(hModule);
return 0;
}
lpfnIsRcrd = (BOOL (__stdcall *)())GetProcAddress(hModule,"IsRcrd");
if(lpfnIsRcrd == NULL)
{
MessageBox(NULL,"δ�ҵ�������ַ","message",48);
FreeLibrary(hModule);
return 0;
}
lpfnInit();
RgstrWndCls();
CrtDlg();
while(GetMessage(&msg,NULL,NULL,NULL))
{
if(msg.message == WM_KEYDOWN && msg.wParam == 9)
{
i++;
if(i > (handle[3] != NULL ? 5 : 2))
i = 1;
SetFocus(handle [i]);
}
else
if(msg.message == WM_KEYDOWN && msg.wParam == 13)
{
if(handle[3] != NULL && (msg.hwnd == handle[1] || msg.hwnd == handle[3]))
SendMessage(handle[0],WM_COMMAND,GetWindowLong(handle[4],GWL_ID),NULL);
else
SendMessage(handle[0],WM_COMMAND,GetWindowLong(GetFocus(),GWL_ID),NULL);
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
case WM_TIMER:
if(v >= length)
{
v=0;
lpfnStop();
lpfnBegin();
}
v++;
break;
case WM_SETFOCUS:
SetFocus(handle[i]);
break;
case WM_COMMAND:
if(LOWORD(wparam) == 10 && HIWORD(wparam) == EN_UPDATE)
{
char buffer [1024];
GetWindowText(handle[1],buffer,1024);
if(strlen(buffer)>256)
{
MessageBox(handle[0],"·��̫��","message",48);
buffer [256] = '\0';
SetWindowText(handle[1],buffer);
}
}
else
if(LOWORD(wparam) == 12 && HIWORD(wparam) == EN_UPDATE)
{
char buffer [1024];
GetWindowText(handle[3],buffer,1024);
if(strlen(buffer)>5)
{
MessageBox(handle[0],"¼����󳤶�ֻ�����õ���λ��","message",48);
buffer [5] = '\0';
SetWindowText(handle[3],buffer);
}
}
if(LOWORD(wparam)==11)
ClickBrowse();
else
if(LOWORD(wparam)==13)
ClickOK();
else
if(LOWORD(wparam)==14)
SendMessage(hWnd,WM_CLOSE,NULL,NULL);
else
if(LOWORD(wparam) == 20)
ClickBegin();
else
if(LOWORD(wparam)==21)
ClickPause();
break;
case WM_CLOSE:
if(lpfnIsRcrd())
{
int o = MessageBox(handle[0],"��ǰ����¼����ȷ���ر�","ѯ��",MB_YESNO | MB_ICONQUESTION);
if(o == IDYES)
{
if(length > 0)
KillTimer(handle[0],100);
lpfnStop();
}
else
if(o == IDNO)
return 0;
}
lpfnDestroy();
FreeLibrary(hModule);
DestroyWindow(hWnd);
PostQuitMessage(0);
break;
default:
return DefWindowProc(hWnd,message,wparam,lparam);
}
return 0;
}
BOOL RgstrWndCls()
{
WNDCLASS wndclass;
wndclass.style = CS_HREDRAW | CS_VREDRAW;
wndclass.lpfnWndProc = &WndProc;
wndclass.cbClsExtra = 0;
wndclass.cbWndExtra = 0;
wndclass.hInstance = hinstance;
wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
wndclass.lpszMenuName = NULL;
wndclass.lpszClassName = "My window";
if(!RegisterClass(&wndclass))
return FALSE;
return TRUE;
}
void CrtDlg()
{
handle[0] = CreateWindow("My Window","��ʼ��",WS_OVERLAPPEDWINDOW,50,50,270,220,NULL,NULL,hinstance,NULL);
CreateWindow("static","¼���ļ�����·����",WS_CHILD | WS_VISIBLE,10,10,200,20,handle[0],(HMENU)0,hinstance,NULL);
handle[1] = CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,10,40,140,20,handle[0],(HMENU)10,hinstance,NULL);
handle[2] = CreateWindow("button","���...",WS_CHILD | WS_VISIBLE,170,40,50,20,handle[0],(HMENU)11,hinstance,NULL);
CreateWindow("static","���¼�����ȣ���λ���룻��������д0����",WS_CHILD | WS_VISIBLE,10,80,250,20,handle[0],(HMENU)1,hinstance,NULL);
handle[3] = CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE,10,110,60,20,handle[0],(HMENU)12,hinstance,NULL);
handle[4] = CreateWindow("button","ȷ��",WS_CHILD | WS_VISIBLE,150,160,50,30,handle[0],(HMENU)13,hinstance,NULL);
handle[5] = CreateWindow("button","ȡ��",WS_CHILD | WS_VISIBLE,220,160,50,30,handle[0],(HMENU)14,hinstance,NULL);
ShowWindow(handle[0],SW_NORMAL);
UpdateWindow(handle[0]);
}
void CrtMnWnd()
{
memset(handle,0,sizeof(HWND)*6);
handle[0] = CreateWindow("My Window","¼����",WS_OVERLAPPEDWINDOW,50,50,200,100,NULL,NULL,hinstance,NULL);
handle[1] = CreateWindow("button","��ʼ",WS_CHILD | WS_VISIBLE,20,30,40,30,handle[0],(HMENU)20,hinstance,NULL);
handle[2] = CreateWindow("button","��ͣ",WS_CHILD | WS_VISIBLE,80,30,60,30,handle[0],(HMENU)21,hinstance,NULL);
EnableWindow(handle[2],FALSE);
i = 1;
ShowWindow(handle[0],SW_NORMAL);
UpdateWindow(handle[0]);
}
void ClickBrowse(void)
{
char buffer [256];
LPITEMIDLIST list = NULL;
BROWSEINFO b;
memset(&b,0,sizeof(BROWSEINFO));
b.hwndOwner = handle[0];
b.lpszTitle = "��ѡ��¼���ļ�����·��";
b.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_EDITBOX;
CoInitialize(NULL);
if(list = SHBrowseForFolder(&b))
{
SHGetPathFromIDList(list,buffer);
SetWindowText(handle[1],buffer);
}
CoTaskMemFree(list);
CoUninitialize();
}
void ClickOK(void)
{
char buffer [256];
int TextLength = 0;
int d = 0;
GetWindowText(handle[1],buffer,256);
if(!strcmp(buffer,""))
{
MessageBox(handle[0],"������¼���ļ�����·��","message",48);
return ;
}
if(!PathIsDirectory(buffer))
{
MessageBox(handle[0],"����·��������","message",48);
return ;
}
strcat(folder,buffer);
GetWindowText(handle[3],buffer,256);
if(!strcmp(buffer,""))
{
MessageBox(NULL,"���������¼������","message",48);
return ;
}
TextLength = strlen(buffer);
while(d < TextLength)
{
if(buffer[d]<48 || buffer[d] > 57)
{
MessageBox(handle[0],"¼���������벻�Ϸ�","message",48);
return;
}
d++;
}
d = 0;
while(d<TextLength)
{
length += (buffer [TextLength-1-d]-48)*ten(d);
d++;
}
DestroyWindow(handle[0]);
CrtMnWnd();
}
void ClickBegin(void)
{
time_t now;
struct tm *tm_now;
char buffer [256],name[256],*p;
GetWindowText(handle[1],buffer,5);
if(!strcmp(buffer,"��ʼ"))
{
if(!lpfnBegin())
{
MessageBox(handle[0],"�޷�¼��","message",48);
return;
}
if(length > 0)
SetTimer(handle[0],100,1000,NULL);
SetWindowText(handle[1],"ֹͣ");
EnableWindow(handle[2],TRUE);
}
else
{
SetWindowText(handle[1],"��ʼ");
lpfnStop();
if(length > 0)
{
KillTimer(handle[0],100);
v=0;
}
GetWindowText(handle[2],buffer,5);
if(strcmp(buffer,"����"))
SetWindowText(handle[2],"��ͣ");
EnableWindow(handle[2],FALSE);
if(MessageBox(handle[0],"�Ƿ񱣴�ղŵ�¼��","ѯ��",MB_YESNO | MB_ICONQUESTION) == IDYES)
{
time(&now);
tm_now = localtime(&now);
sprintf(name,"\\%d-%d-%d-%d-%d-%d.wav",tm_now->tm_year+1900,tm_now->tm_mon+1,tm_now->tm_mday,tm_now->tm_hour,tm_now->tm_min,tm_now->tm_sec);
strcat(buffer,folder);
strcat(buffer,name);
if(!lpfnSave(buffer))
MessageBox(handle[0],"�ļ�����ʧ��","message",48);
}
}
}
void ClickPause(void)
{
char buffer [5];
GetWindowText(handle[2],buffer,5);
if(!strcmp(buffer,"��ͣ"))
{
if(length > 0)
KillTimer(handle[0],100);
lpfnPause();
SetWindowText(handle[2],"����");
}
else
{
lpfnContinue();
if(length > 0)
SetTimer(handle[0],100,1000,NULL);
SetWindowText(handle[2],"��ͣ");
}
}
int ten(int a)
{
int i = 0,j = 1;
while(i < a)
{
j*=10;
i++;
}
return j;
}