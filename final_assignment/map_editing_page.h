#pragma once
#include "abstract_page.h"
#include "maps.h"
#include "picture_button.h"
#include <vector>
#include "button.h"
//class map_editingʵ�ֶԵ�ͼ�ı༭
class map_editing_page :public abstract_page {
public:
	map_editing_page(int w, int h, maps& my_maps);
	//virtual void update_maps()override;
	virtual void get_keyboard_message()override;
	virtual void draw()override;
	virtual ~map_editing_page();
private:
	//ʹ��maps��ʵ�ֵ�ͼ���漰����(���ô��ݣ�
	maps& my_maps;
	//���õ�ǰѡ��Ľ���id
	void set_now_select_building_id(int id) {
		now_select_building = id;
	}
	//�����ұߵĽ���ѡ��
	std::vector<picture_button*> my_picture_button;
	//���ذ���
	button* return_button;
	//��ǰѡ��Ľ���
	int now_select_building;
	// ��ߵ�ͼ����ռ��
	int left_width, left_height;
	// �ұ�ѡ���ռ��
	int right_width, right_height;
	// ��ͼʵ�ʳ��ȣ����У�
	int map_width;
	// ��ͼʵ�ʿ��
	int map_height;
	//��ͼ��ߵĿռ�
	int map_real_x;
	int map_real_y;
	// һ������ѡ��ĳ���(ָ�ұ�ѡ���еĽ����������ߴ磩
	int single_object_width;
	int single_object_height;
	
};