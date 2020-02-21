// 俄罗斯方块.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "俄罗斯方块.h"
#include <time.h>

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

#define ID_DOWNTIME 1

//地图网格		1:代表正在往下落的方块；
//2：已经落下的
int g_arrBackground[20][10] = {0};

int g_arrTetrisBlock[2][4] = { 0 };		//俄罗斯方块

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void				Onpaint(HDC hdc);
void				DrawBlock(HDC hdc);
void				OnStart(HWND hWnd);
void				OnCreate();//窗口创建
void				CreateTetriBlock();//随机生成俄罗斯方块
void				CopyTetrisBlock();//将随机生成的网格复制到方块上
void				OnTimer(HWND hWnd);//定时器处理函数
void				BlockDown();//方块下落
BOOL				IsDownBottom();//判断是否到达底部
void				AdjustStatue();//调整状态
BOOL				IsOtherBlock();//碰到其他方块

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 500,680, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE://窗口创建
		OnCreate();
		break;
	case WM_KEYDOWN://键盘按下
		switch (wParam)
		{
		case VK_RETURN://按下回车键
			OnStart(hWnd);//开始
			break;
		}
		break;
	case WM_TIMER:
		switch (wParam)
		{
		case ID_DOWNTIME:
			OnTimer(hWnd);
			break;
		}
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
			Onpaint(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

//绘制图形
void Onpaint(HDC hdc)
{
	//创建一个内存DC，双缓冲
	HDC hMemDC = CreateCompatibleDC(hdc);
	//创建一张兼容位图
	HBITMAP hBackBmp = CreateCompatibleBitmap(hdc,300,600);
	SelectObject(hMemDC,hBackBmp);

	//绘制图形
	DrawBlock(hMemDC);

	//复制到界面
	BitBlt(hdc,0,0,300,600,hMemDC,0,0,SRCCOPY);
	//释放DC
	DeleteDC(hMemDC);
}
//绘制方块
void	DrawBlock(HDC hdc)
{
	//绘制一个大背景
	Rectangle(hdc,0,0,300,600);

	//绘制每一个小方块30*30
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (g_arrBackground[i][j] == 1 || g_arrBackground[i][j] == 2)
			{
				//绘制小方块

				Rectangle(hdc, j * 30 + 1, i * 30 + 1, j * 30 + 30 - 1, i * 30 + 30 - 1);
			}
		}
	}
}
void OnCreate()
{
	srand((UINT)time(NULL));
	//生成随机图像
	CreateTetriBlock();
	//将俄罗斯方块复制到网格
	CopyTetrisBlock();

}

void OnStart(HWND hWnd)//开始
{
	SetTimer(hWnd,ID_DOWNTIME,700,NULL);
}

void CreateTetriBlock()
{
	int nIndex = rand() % 7;	//7种方块

	//数组要清零
	memset(g_arrTetrisBlock,0,sizeof(g_arrTetrisBlock));
	
	switch (nIndex)
	{
	case 0:
		g_arrTetrisBlock[0][0] = 1;g_arrTetrisBlock[0][1] = 1;g_arrTetrisBlock[0][2] = 1;g_arrTetrisBlock[0][3] = 1;
		g_arrTetrisBlock[1][0] = 0; g_arrTetrisBlock[1][1] = 0; g_arrTetrisBlock[1][2] = 0; g_arrTetrisBlock[1][3] = 0;
		break;
	case 1:
		g_arrTetrisBlock[0][0] = 1; g_arrTetrisBlock[0][1] = 0; g_arrTetrisBlock[0][2] =0; g_arrTetrisBlock[0][3] = 0;
		g_arrTetrisBlock[1][0] = 1; g_arrTetrisBlock[1][1] = 1; g_arrTetrisBlock[1][2] = 1; g_arrTetrisBlock[1][3] = 0;
		break;
	case 2:
		g_arrTetrisBlock[0][0] = 0; g_arrTetrisBlock[0][1] = 0; g_arrTetrisBlock[0][2] = 1; g_arrTetrisBlock[0][3] = 0;
		g_arrTetrisBlock[1][0] = 1; g_arrTetrisBlock[1][1] = 1; g_arrTetrisBlock[1][2] = 1; g_arrTetrisBlock[1][3] = 0;
		break;
	case 3:
		g_arrTetrisBlock[0][0] = 0; g_arrTetrisBlock[0][1] = 1; g_arrTetrisBlock[0][2] = 1; g_arrTetrisBlock[0][3] = 0;
		g_arrTetrisBlock[1][0] = 0; g_arrTetrisBlock[1][1] = 1; g_arrTetrisBlock[1][2] = 1; g_arrTetrisBlock[1][3] = 0;
		break;
	case 4:
		g_arrTetrisBlock[0][0] = 0; g_arrTetrisBlock[0][1] = 1; g_arrTetrisBlock[0][2] = 1; g_arrTetrisBlock[0][3] = 0;
		g_arrTetrisBlock[1][0] = 1; g_arrTetrisBlock[1][1] = 1; g_arrTetrisBlock[1][2] = 0; g_arrTetrisBlock[1][3] = 0;
		break;
	case 5:
		g_arrTetrisBlock[0][0] = 0; g_arrTetrisBlock[0][1] = 1; g_arrTetrisBlock[0][2] = 0; g_arrTetrisBlock[0][3] = 0;
		g_arrTetrisBlock[1][0] = 1; g_arrTetrisBlock[1][1] = 1; g_arrTetrisBlock[1][2] = 1; g_arrTetrisBlock[1][3] = 0;
		break;
	case 6:
		g_arrTetrisBlock[0][0] = 1; g_arrTetrisBlock[0][1] = 1; g_arrTetrisBlock[0][2] = 0; g_arrTetrisBlock[0][3] = 0;
		g_arrTetrisBlock[1][0] =0; g_arrTetrisBlock[1][1] = 1; g_arrTetrisBlock[1][2] = 1; g_arrTetrisBlock[1][3] = 0;
		break;
	}
}

void CopyTetrisBlock()
{
	for (int i = 0; i < 2; i++)
	{
		for(int j=0;j<4;j++)
		{
			g_arrBackground[i][j + 3] = g_arrTetrisBlock[i][j];
		}
	}
}

void OnTimer(HWND hWnd)
{
	//到了底端或者碰到了其他方块
	if (FALSE == IsDownBottom() && FALSE==IsOtherBlock ())
	{
		BlockDown();
	}
	else
	{
		//调整方块状态
		AdjustStatue();
		//创建新方块
		CreateTetriBlock();
		//复制到网格
		CopyTetrisBlock();
	}
		

	//重新绘制
	InvalidateRect(hWnd,NULL,TRUE);

}

void BlockDown()
{
	for (int i = 19; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (g_arrBackground[i][j] == 1)
			{
				g_arrBackground[i + 1][j] = 1;
				g_arrBackground[i][j] = 0;
			}
		}
	}
}

BOOL IsDownBottom()
{
	for (int i = 0; i < 10; i++)
	{
		if (g_arrBackground[19][i] == 1)
			return TRUE;
	}
	return FALSE;
}
//调整状态
void AdjustStatue()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (g_arrBackground[i][j] == 1)
				g_arrBackground[i][j] = 2;
		}
	}

}

BOOL IsOtherBlock()//碰到其他方块
{
	for (int i = 19; i >= 0;i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (g_arrBackground[i][j] == 1 && g_arrBackground[i + 1][j] == 2)
				return TRUE;
		}
	}
	return FALSE;
}