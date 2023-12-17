#pragma once

#include "abstract_page.h"
#include "maps.h"
#include <vector>
class map_select_page :public abstract_page {
public:
	//���캯����Ҫͨ�������ʼ��ҳ��Ŀ�ߺ���һ��ҳ��id
	map_select_page(int next_id,int w,int h, maps<show_maps_num>& my_maps);
	//virtual void update_maps()override;
	virtual void get_keyboard_message()override;
	virtual void draw()override;

	virtual ~map_select_page();
private:
	//ʹ��maps��ʵ�ֵ�ͼ���漰����(���ô��ݣ�
	maps<show_maps_num> &my_maps;
	//Ĭ��ѡ���һ�ŵ�ͼ
	int now_selected_page_id = page_id::HOME_PAGE;
	//���ͼѡ��ģ��Ŀ��
	int left_width, left_height;
	//��ѡ��ģ��Ŀ��
	int  right_width, right_height;
	//��ͼ�ߴ�
	int map_width, map_height;
	//��ͼѡ��ǰ�����ű�
	double unselected_scale;
	//��ͼѡ�������ű�
	double selected_scale;
};