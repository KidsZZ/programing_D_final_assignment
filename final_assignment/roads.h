#pragma once
//ͨ��������ͼ�����е�roadλ�ã��Ե�·ͼƬ������Ⱦ
#include <vector>
#include <graphics.h>
#include "map.h"
class roads {
public:
	//���캯���������·ͼƬ
	roads();
	//�����������ͷŵ�·ͼƬ
	~roads();
	//���ƺ����������ŵ�ͼ��Ϣ�Ľṹ����л���
	void draw(map *my_map);
private:
	std::vector<IMAGE*> road_img;
};