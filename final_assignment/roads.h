#pragma once
//ͨ��������ͼ�����е�roadλ�ã��Ե�·ͼƬ������Ⱦ
#include <vector>
#include <graphics.h>
#include "enum_lib.h"
#include<string>
class roads 
{
public:

	//���캯���������·ͼƬ
	roads(std::wstring path, int n);

	//���ƺ����������ŵ�ͼ��Ϣ�Ľṹ����л���
	void draw(int length,int x,int y,int direction)const;

	//�����������ͷŵ�·ͼƬ
	~roads();
	
private:

	//����vector������IMAGE*������ݣ�����Ϊroad_img
	std::vector<IMAGE*> road_img;
};











