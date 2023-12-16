#pragma once
//������ҳ�洰�ڣ�����ͬҳ�棨*��Ϊeasyx��֧�ֶര�ڣ�����ͨ���Բ�ͬ���ڼ�¼indexֵ���л���ͬ����
#include <vector>
#include <string>
#include "abstract_page.h"
#include "maps.h"
#include "enum_lib.h"
class Widget {
public:
	//���캯����������ҳ������my_page,����ҳ�泤��ȣ���now_page_id��Ϊhome_page_id
	Widget(int w,int h);
	//����Ա����
	void run();
	void close();
	~Widget();
private:
	std::vector<abstract_page*> my_page;
	//ҳ��id����(������ʹ��ͳһmy_mpas����)
	//int previous_page_id = HOME_PAGE;
	//��һ֡��ҳ��id
	int now_page_id = HOME_PAGE;
	//ҳ��Ŀ�͸�
	int width, height;
	//ʹ��4����ͼ�浵
	static const int show_maps_num = 4;
	//�����ͼ��Ϣ
	maps<show_maps_num> my_maps;
	const static std::string path;
};