#pragma once
#include <string>
#include<iostream>
#include "enum_lib.h"
#include<fstream>
#include <string>
#include <graphics.h>
class lines
{
public:
	lines() {};
	//���캯������ʼ������
	lines(int length, int width, int row,int column,int fixed_length);
	//��������
	~lines();
	//���ƺ��������Ʒָ��ߣ�x,y��Ϊ��ͼ���Ͻǵĵ�
	void draw(int x,int y);

	static int row;           //��ͼ������
	static int column;        //��ͼ������
	static int fixed_length;  //���ߡ��Ŀ��
	static int length;        //��ͼ����
	static int width;         //��ͼ���

};
