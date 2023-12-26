#pragma once
//class houses���ڶԵ�ͼ�еĽ���������Ⱦ
#include <graphics.h>
#include <string>
#include <vector>
#include "enum_lib.h"
#include<cstdlib>
class houses 
{
public:

	//���캯������ʼ��img����(��������ַ��ͨ����ʽ����img/img*.png��ʹ��ʵ����Ƭ����滻*��ǣ�
	houses(std::wstring path, int n);

	//���ƺ���:���뵱ǰ��ͼ���ݣ��������ݻ�����
	void draw(int length,int x,int y,int house_type)const;

	//Ϊ���Ƶ�·�ṩ������ķ����Ƿ������������
	//�ڴ˺����е�����char_to_int��������ת�����Ͳ���
	bool is_door(int direction, char c)const;

	//��������������img����
	//������Ϊ�麯������������û���µ����ݳ�Ա
	~houses();


private:
	//ʹ��ö�����¼���ӱ��
	//���淿�ӵ�ͼƬ
	std::vector<IMAGE*> house_img;

	//������ŵĳ���ʹ���������µ�˳��洢
	//����Ϊtrue��������Ϊfalse
	//Ԥ�ȿ����㹻�Ŀռ�
	bool house_orientation[30][4];
};


















