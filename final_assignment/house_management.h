#pragma once
#include "houses.h"
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
	std::vector <houses*> my_house;
};