/** ******************************************\brief
 *�ļ�����gameLib.c
 *��  ��������game.h�ж���Ĳ�������
 *ʱ  �䣺2019/1/5
 *�����ˣ�֣Զ��
 ****************************************************/
 #include "gameLib.h"

 void SetTitle(char *title) //�޸ĳ������
 {
     SetConsoleTitle(title);
 }

void SetColor(int foreColor,int backColor)
  {
      HANDLE winHandle;     //���
      winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
      //����������ɫ
      SetConsoleTextAttribute(winHandle,foreColor+backColor*0x10);
  }

 void SetPostion(int x,int y)
 {
      HANDLE winHandle;     //���
      COORD pos={x,y};

      winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleCursorPosition(winHandle,pos);
 }


