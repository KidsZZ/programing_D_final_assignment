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

	//��ͼ������
	int row;       
	//��ͼ������
	int column;   
	//���ߡ��Ŀ��
	int fixed_length;  
	//��ͼ����
	int length;       
	//��ͼ���
	int width;       

};
