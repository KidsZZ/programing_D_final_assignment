#pragma once
#include "abstract_house.h"
#include "map.h"
#include <vector>
class house_management {
public:
	//Ĭ�Ϲ��캯����������house��ʼ��
	house_management();
	//�����ͼ�ṹ�壬���Ʒ��ݵ���ͼ��
	void draw(map& my_map);
	//��������
	~house_management();
private:
	std::vector <abstract_house*> my_house;
};