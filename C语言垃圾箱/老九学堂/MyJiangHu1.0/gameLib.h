#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
/** ******************************************\brief
 *�ļ�����gameLib.h
 *��  ��������������Ϸ�еĳ���ϵͳ����
 *ʱ  �䣺2019/1/5
 *�����ˣ�֣Զ��
 ****************************************************/
 #include <stdio.h>
 #include <windows.h>

 /*���ÿ���̨���ڵı���*/
 void SetTitle(char *title) ;
 /*�������ֵ�ǰ��ɫ�ͱ���ɫ*/
 /*0-��ɫ��1-��ɫ��2-��ɫ��3-ǳ��ɫ��4-��ɫ��5-��ɫ
 **6-��ɫ��7-��ɫ��8-��ɫ��9-����ɫ��10-����ɫ��11-��ǳ��ɫ
 **12-����ɫ��13-����ɫ��14-����ɫ��15-����ɫ*/
 void SetColor(int foreColor,int backColor);

 /*���ù���λ��*/
 void SetPostion(int x,int y);

#endif // GAMELIB_H_INCLUDED
