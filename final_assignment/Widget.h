#pragma once
//������ҳ�洰�ڣ�����ͬҳ�棨*��Ϊeasyx��֧�ֶര�ڣ�����ͨ���Բ�ͬ���ڼ�¼indexֵ���л���ͬ����
#include <vector>
#include "abstract_page.h"
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
	//ҳ��id����
	enum{
		home_page = 0,
		map_editing,
		navigation
	};
	//��һ֡��ҳ��id
	int now_page_id = home_page;
	//ҳ��Ŀ�͸�
	int width, height;
};