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
	roads();
	//�����������ͷŵ�·ͼƬ
	~roads();
	//���ƺ����������ŵ�ͼ��Ϣ�Ľṹ����л���
	void draw(int width,int height,int x,int y,int direction);
	
private:
	std::vector<IMAGE*> road_img;
};