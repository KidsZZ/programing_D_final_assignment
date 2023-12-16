#include "Widget.h"
#include "home_page.h"
#include "navigation_page.h"
#include "map_select_page.h"
#include "map_editing_page.h"
#include <graphics.h>
#include "enum_lib.h"

Widget::Widget(int w, int h) :width(w),height(h),now_page_id(page_id::HOME_PAGE)/*,my_maps(path)*/ {
	//��ʼ��my_maps
	//my_maps.read_file();
	//��ʼ���ĸ�ҳ��
	my_page.push_back(new home_page(page_id::HOME_PAGE, width, height));
	/*my_page.push_back(new map_select_page(page_id::MAP_SELECT_PAGE, width, height,my_maps));
	my_page.push_back(new map_editing_page(page_id:: MAP_EDITING_PAGE, width, height, my_maps));
	my_page.push_back(new navigation_page(page_id::NAVIGATION_PAGE, width, height,my_maps));*/
}

void Widget::run() {
	bool running = true;
	//ʹ����Ⱦ������
	BeginBatchDraw();
	while (running) {
		DWORD start_time = GetTickCount();
		//��������
		my_page[now_page_id]->get_keyboard_message();

		//����������������
		my_page[now_page_id]->draw();

		//����ҳ�潻��
		if ((now_page_id = my_page[now_page_id]->return_page_id()) == page_id::EXIT) {
			running = false;
		}
		//�л�����
		FlushBatchDraw();

		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;

		//ʹ�ö�̬ˢ��
		if (delta_time < 1000 / 60) {
			Sleep(1000 / 60 - delta_time);
		}
	}
	//�ر���Ⱦ������
	EndBatchDraw();
	return;
}

void Widget::close() {
	closegraph();
	for (int i = 0; i < 4; i++) {
		delete my_page[i];
	}
}