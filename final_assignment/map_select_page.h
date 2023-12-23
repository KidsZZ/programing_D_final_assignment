#pragma once

#include "abstract_page.h"
#include "maps.h"
#include <vector>
#include "button.h"
class map_select_page :public abstract_page {
public:
	//���캯����Ҫͨ�������ʼ��ҳ��Ŀ�ߺ���һ��ҳ��id
	map_select_page(int w,int h, maps& my_maps);
	//virtual void update_maps()override;
	virtual void get_keyboard_message()override;
	virtual void draw()override;

	virtual ~map_select_page();
private:
	//���õ�ǰѡ��Ľ���
	//ʹ��maps��ʵ�ֵ�ͼ���漰����(���ô��ݣ�
	maps &my_maps;
	std::vector<button*> my_button;
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
	//��ť�ߴ�
	int button_width, button_height;
	//��ť�ı�
	std::wstring first_button_text;
	std::wstring second_button_text;
	//��ťλ��
	int first_button_x, first_button_y;
	int second_button_x, second_button_y;
	//�������к��е�˳��洢��ͼ�Ƿ�ѡ��
	bool is_map_over[2][2];
	int map_selected_id;
	//��Ч�����Χ
	int map_left_space_x;
	int map_left_space_y;
	//��ͼ�Ŵ��ߴ�
	int map_left_space_x_selected;
	int map_left_space_y_selected;
};