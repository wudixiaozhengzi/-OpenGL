/** ******************************************\brief
 *文件名：gameLib.c
 *描  述：用来game.h中定义的操作函数
 *时  间：2019/1/5
 *创建人：郑远环
 ****************************************************/
 #include "gameLib.h"

 void SetTitle(char *title) //修改程序标题
 {
     SetConsoleTitle(title);
 }

void SetColor(int foreColor,int backColor)
  {
      HANDLE winHandle;     //句柄
      winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
      //设置文字颜色
      SetConsoleTextAttribute(winHandle,foreColor+backColor*0x10);
  }

 void SetPostion(int x,int y)
 {
      HANDLE winHandle;     //句柄
      COORD pos={x,y};

      winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleCursorPosition(winHandle,pos);
 }


