#pragma once
//ͨ��������ͼ�����е�roadλ�ã��Ե�·ͼƬ������Ⱦ
#include <vector>
#include <graphics.h>
#include "map.h"
#include "enum_lib.h"
#include<string>
class roads {
public:
	//���캯���������·ͼƬ
	roads(std::wstring path, int n);
	//�����������ͷŵ�·ͼƬ
	~roads();
	//���ƺ����������ŵ�ͼ��Ϣ�Ľṹ����л���
	void draw(int length,int x,int y,int direction)const;
	
private:
	std::vector<IMAGE*> road_img;
};