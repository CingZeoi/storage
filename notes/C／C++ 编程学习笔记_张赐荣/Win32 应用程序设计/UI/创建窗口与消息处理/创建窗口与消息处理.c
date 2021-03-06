/*
时间：2017年7月8日星期六
1点23分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <windows.h>
#include <stdio.h>
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
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
hWnd = CreateWindow("My Window","hello,windows",WS_OVERLAPPEDWINDOW,50,50,380,250,NULL,NULL,hInstance,NULL);
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
case WM_CREATE:
MessageBox(hWnd,"hello,win","Message",64);
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
win32应用程序的入口函数是WinMain，原型如下：
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd);
WinMain不同与main，WinMain可以让操作系统在启动程序时传递更多的信息给应用程序；
hInstance：应用程序实体句柄，是一个应用程序的标识；
hPrevInstance：应用程序上一个实力句柄，在32位及以后的系统中，该值永远是NULL；
lpCmdLine：命令行；
nShowCmd：指定窗口显示方式；
创建窗口首先要定义窗口类和注册窗口类；
定义窗口类就是定义一个WNDCLASS的实力并初始化每个字段；
WNDCLASS原型如下：
struct WNDCLASS
{
    UINT        style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HINSTANCE   hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    LPCSTR      lpszMenuName;
    LPCSTR      lpszClassName;
};
style：窗口样式，照抄；
lpfnWndProc：函数指针，指向消息处理函数，
消息处理函数原型如下：
LRESULT WndProc(HWND,UINT,WPARAM,LPARAM);
当然函数名随便，因为传的是地址；
cbClsExtra：窗口类额外空间字节数，写0；
cbWndExtra：窗口额外空间字节数，写0；
hInstance：应用程序实体句柄；
hIcon：图标句柄，照抄；
hCursor：光标句柄，照抄；
hbrBackground：画刷句柄，照抄；
lpszMenuName：菜单资源名，写NULL；
lpszClassName：窗口类名；
然后是注册窗口类；
RegisterClass函数可以注册窗口类，原型如下：
ATOM RegisterClass(WNDCLASS *lpWndClass);
lpWndClass：指向WNDCLASS实力的指针；
CreateWindow可以创建窗口，函数原型如下：
HWND CreateWindow(LPCTSTR lpClassName,LPCTSTR lpWindowName,DWORD dwStyle,int x,int y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
返回创建后的窗口句柄；
lpClassName：要创建的窗口类名；
lpWindowName：窗口标题；
dwStyle：窗口样式，照抄；
x：窗口距离屏幕左边的距离；
y：窗口距离屏幕顶部的距离；
nWidth：窗口宽度；
nHeight：窗口高度；
hWndParent：副窗口句柄；
hMenu：菜单；
hInstance：应用程序实力句柄；
lpParam：附加参数；
ShowWindow更改窗口显示方式，窗口创建好后默认是不可见的，函数原型如下：
BOOL ShowWindow(HWND hWnd,int nCmdShow);
hWnd：要设置的窗口的句柄；
nCmdShow：要设置成的状态，可以为以下值之一：
SW_HIDE：隐藏；
SW_MAXIMIZE：最大化；
SW_MINIMIZE：最小化；
SW_RESTORE：还原原始大小；
SW_SHOW：激活；
SW_SHOWMAXIMIZED：激活并最大化；
SW_SHOWMINIMIZED：激活并最小化；
SW_SHOWMINNOACTIVE：最小化，但不激活；
SW_SHOWNA：显示，但不激活；
SW_SHOWNOACTIVATE：还原原始大小但不激活；
SW_SHOWNORMAL：还原原始大小并激活；
UpdateWindow：更新窗口，如果窗口绘制区域不为空，UpdateWindow将绕过消息队列，直接发送WM_PAINT消息给消息处理函数，通知windows绘制窗口，如果为空则不发送；
后面是消息循环；
GetMessage函数从消息队列中取出消息，第一个参数是指向MSG结构体的指针，取出的消息将放到结构体中，所以要先定义MSG实力，MSG都有哪些字段，这里就不列举了；
后面三个参数是消息过滤，统一写NULL；
关于GetMessage的返回值后面在说；
Translate函数是对键盘消息的转换，参数是指向MSG实力的指针；
DispatchMessage函数通知Windows给消息处理函数发送消息，参数是指向MSG结构体的指针，消息处理函数返回后，这个函数才返回，进行下一轮循环；
windows为应用程序维护一个消息队列，当用户对应用程序进行操作时，windows会在应用程序的消息队列中放置一条消息，
应用程序通过GetMessage来取出一条消息，转换键盘消息，然后通知windows调用消息处理函数，消息处理函数通过消息的值就能知道用户进行了什么操作，应用程序给出响应；
在本例中，我们并没有手动调用消息处理函数，是windows自动调用的，这点尤其重要；
消息处理函数原型如下：
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wparam,LPARAM lparam);
hWnd表示消息来自哪个窗口，message表示消息的值，wparam与lparam是附加参数；
这个附加参数，比如用户按了键盘上的一个键，windows发送一条WM_KEYDOWN消息，这时wparam中的值就是虚拟键码；
后面就是对消息进行判断；
WM_KEYDOWN：按下某键；
WM_KEYUP：放开某键；
WM_CHAR：字符输入；
下面着重说一下窗口销毁过程及程序退出；
当用户单机窗口右上角的关闭按钮或在系统菜单中选择关闭菜单项时，windows会发送一条WM_CLOSE消息，表示用户试图关闭窗口；
这时应用程序可以调用DestroyWindow函数来销毁窗口，参数是窗口句柄；
调用销毁窗口函数后，windows会发送一条WM_DESTROY消息，注意这时候窗口还没有被销毁；
当消息处理函数处理这条消息返回后，窗口才会销毁；
如果要结束消息循环，就调用PostQuitMessage，参数写0就行，它会通知windows发送一条WM_QUIT消息；
当GetMessage取出的是WM_QUIT消息时，就会返回0，循环条件不成立，从而结束消息循环，程序退出；
程序不处理的消息就调用DefWndProc，这是系统默认消息处理函数，把消息处理函数接收到的四个值按顺序传进去就行；
*/