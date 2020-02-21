#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "GameLib.h"

void SetTitle(char * title)
{
    SetConsoleTitle(title);
}

void SetColor(int ForeColor, int BackGroundColor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    //��ȡ��ǰ���ھ��
    SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//������ɫ
}
void SetConsoleWindowSize(int width, int height)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ÿ���̨���ڵĻ�������С
	COORD size = {width, height};
	SetConsoleScreenBufferSize(handle, size);
	//���ÿ���̨���ڴ�С,��������ǻ�������С-1
	SMALL_RECT rect = {0, 0, width-1, height-1};
	SetConsoleWindowInfo(handle, 1, &rect);
}
void SetPosition(int x, int y)
{
    COORD cursorPosition;   //��������
    HANDLE handle;          //��ǰ���ھ��
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPosition.X = x;   //����x��y����
    cursorPosition.Y = y;
    SetConsoleCursorPosition(handle, cursorPosition);
}
void PrintString(const char * msgString)
{
    int length = strlen(msgString);
    int i = 0;
    for(; i < length; i++)
    {
        char tempChar = msgString[i];
        printf("%c", tempChar);
        usleep(1000 * 20);//20����
        fflush(stdout);
    }
}
void Read(char * Buffer, int BufferSize)
{
    DWORD Read;
    HANDLE handle;          //��ǰ���ھ��
    handle = GetStdHandle(STD_INPUT_HANDLE);
    ReadConsole(handle, Buffer, BufferSize, &Read, NULL);
}

int GetKey()

{
    HANDLE handle;          //��ǰ���ھ��
    handle = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Read;
    INPUT_RECORD Event;
    //�õ�����̨������
    ReadConsoleInput(handle, &Event, 1, &Read);
    //��������¼���һ�������¼����ͽ����жϣ����ذ��¼����������
    if(Event.EventType == KEY_EVENT)
    {
        if(Event.Event.KeyEvent.bKeyDown)//����ֵΪtrue����ʾ�м�������
        {
             return Event.Event.KeyEvent.wVirtualKeyCode;//���ذ��¼����������
        }
    }
    return 0;
}
char * GetGameTime()
{

    time_t rawtime;
    struct tm * timeinfo;
    static char buffer [128];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,sizeof(buffer),"%Y-%m-%d %H:%M:%S", timeinfo);
    return buffer;
}
void Clear(int X, int Y)
{
    DWORD written;
    COORD start;    //��ʼ����
    HANDLE handle;  //��ǰ���ھ��
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    start.X = X;
    start.Y = Y;
    FillConsoleOutputAttribute(handle, 15, 80*25, start, &written);
    FillConsoleOutputCharacter(handle, ' ', 80*25, start, &written);
    SetConsoleCursorPosition(handle, start);
}
void ClearMessage()
{
    //�����Ϣ��ʾ��
    COORD coordStart = {0, 12};
    DWORD written;
    HANDLE handle;  //��ǰ���ھ��
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    FillConsoleOutputAttribute(handle, 15, 120*7, coordStart, &written);
    FillConsoleOutputCharacter(handle, ' ', 120*7, coordStart, &written);
    SetConsoleCursorPosition(handle, coordStart);
}














