//���ļ�ʵ�ֶ�widget.h�ж���ľ������ʵ��
#include "Widget.h"

//enum_lib��һ���������������Ҫ�õ��ĳ����Ŀ⣨��������������Ϣ���ݣ�
#include "enum_lib.h"

//include�ĸ�������ҳ��ͷ�ļ�
#include "home_page.h"
#include "navigation_page.h"
#include "map_select_page.h"
#include "map_editing_page.h"

//easyxͷ�ļ�
#include <graphics.h>

//���캯��
//��ɶ����и��ֱ����ĳ�ʼ��
//������ͼ���ݱ�������Ŀ��map_lib�ļ�����
//����ʼ�Ľ�������Ϊhome_page
Widget::Widget(int w, int h) :width(w),height(h),now_page_id(page_id::HOME_PAGE),path(L"maps_lib/"),my_maps(path) {

	//��widget��չ���������򴰿�
	//����ҳ��ʵ�ֶ�widget�ഴ���Ĵ��ڵľ������
	//ͨ�����Ʋ�ͬ����ʵ�ֲ�ͬ����
	initgraph(width, height);

	//��ʼ���ĸ�ҳ��
	//��ʼ����
	my_page.push_back(new home_page(width, height));
	//��ͼѡ�����
	my_page.push_back(new map_select_page(width, height,my_maps));
	//��ͼ�༭����
	my_page.push_back(new map_editing_page(width, height, my_maps));
	//��ͼ��������
	my_page.push_back(new navigation_page(width, height, my_maps));
}

//widget��������ʵ��ѭ��
void Widget::run() {
	//��¼��ǰ״̬����runningΪfalseʱ�˳�ѭ��	
	bool running = true;

	//ʹ����Ⱦ������,��ֹ����
	//ʹ�ô˷����󣬻Ὣ���������ƵĻ���ȫ����������һ��ͼ����
	//Ȼ��һ���Գ��ֵ�������
	BeginBatchDraw();

	//���߼�������
	while (running) {

		//��õ�ǰʱ��
		DWORD start_time = GetTickCount();

		//��������
		//ҳ�������ڴ˺����и�����ز���
		my_page[now_page_id]->get_keyboard_message();

		//����������������
		//ҳ����󽫸��¹��Ĳ������Ƶ�������
		my_page[now_page_id]->draw();

		//����ҳ�淵�ص���һ��ҳ�������
		now_page_id = my_page[now_page_id]->return_page_id();

		//���ҳ�淵�ص���exit�����˳�ѭ�����˳�����
		if (now_page_id == page_id::EXIT) {
			running = false;
		}

		//�л������������ƺõ�ͼ��һ���Գ��ֵ�������
		FlushBatchDraw();

		//��ȡ��ǰʱ��
		DWORD end_time = GetTickCount();

		//����˴�ѭ�����������˶೤ʱ��
		DWORD delta_time = end_time - start_time;

		//ʹ�ö�̬ˢ��
		//�����������ʱ��С��һ֡��Ҫ��ʱ�䣬����ʱ�������ʱ��
		//��ǰΪһ��60֡
		if (delta_time < 1000 / 60) {
			Sleep(1000 / 60 - delta_time);
		}
	}
	//�ر���Ⱦ������
	EndBatchDraw();
	return;
}

//����رպ�������ɶ�̬�ڴ����Ŀռ���ڴ��ͷ�
void Widget::close() {

	//�رջ���
	closegraph();

	//�ͷ�ÿһ��ҳ�����
	while (!my_page.empty()) {

		//ɾ��β��ָ��ָ��ռ������ڴ�
		delete my_page.back();

		//�ͷ�β��
		my_page.pop_back();
	}
}