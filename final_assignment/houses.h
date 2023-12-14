#pragma once
//class houses���ڶԵ�ͼ�еĽ���������Ⱦ
#include <graphics.h>
#include <string>
#include <vector>
#include "maps.h"
class houses {
public:
	//���캯������ʼ��img����(��������ַ��ͨ����ʽ����img/img*.png��ʹ��ʵ����Ƭ����滻*��ǣ�
	houses(std::string path,int n);
	//���ƺ���:���뵱ǰ��ͼ���ݣ��������ݻ�����
	void draw(maps<> &my_maps);
	//��������������img����
	//������Ϊ�麯������������û���µ����ݳ�Ա
	~houses();
protected:
	//ʹ��ö�����¼���ӱ��
	enum house_type{
		museum = 1,
		dorminory,
		teaching_building,
		canteen
	};
	//���淿�ӵ�
	std::vector<IMAGE*> house_img;
	//������ŵĳ���ʹ���������ҵ�˳��洢
	//����Ϊtrue��������Ϊfalse
	std::vector<bool[4]> house_orientation;
};