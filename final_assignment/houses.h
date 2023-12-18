#pragma once
//class houses���ڶԵ�ͼ�еĽ���������Ⱦ
#include <graphics.h>
#include <string>
#include <vector>
#include "maps.h"
#include "enum_lib.h"
class houses {
public:
	//���캯������ʼ��img����(��������ַ��ͨ����ʽ����img/img*.png��ʹ��ʵ����Ƭ����滻*��ǣ�
	houses(std::wstring path, int n);
	//���ƺ���:���뵱ǰ��ͼ���ݣ��������ݻ�����
	void draw(int width,int height,int x,int y);
	//Ϊ���Ƶ�·�ṩ������ķ����Ƿ������������
	bool is_door(int direction, int house_type);
	//��������������img����
	//������Ϊ�麯������������û���µ����ݳ�Ա
	~houses();

private:
	//ʹ��ö�����¼���ӱ��
	
	//���淿�ӵ�ͼƬ
	std::vector<IMAGE*> house_img;
	//������ŵĳ���ʹ���������µ�˳��洢
	//����Ϊtrue��������Ϊfalse
	std::vector<bool[4]> house_orientation;
};