#include "map_select_page.h"
#include "enum_lib.h"
map_select_page::map_select_page(int next_id, int w, int h, maps& my_maps) :abstract_page(next_id, w, h), my_maps(my_maps) {
	//���ģ��ռ��80%���ұ�ռ��20%
	left_width = width * 0.8;
	right_width = width - left_width;
	left_height = right_width = height;
	//��ͼ���
	map_width = left_width / 2;
	map_height = left_height / 2;
	//��ͼ���ű���
	unselected_scale = 0.65;
	selected_scale = 0.8;
	//��ť�ߴ�
	button_width = 280;
	button_height = 60;
	//��ť�ı�
	first_button_text = L"��ʼ����";
	second_button_text = L"�༭��ͼ";
	//��ť����
	first_button_x = left_width + (right_width - button_width) / 2;
	first_button_y = right_height / 3;
	second_button_x = first_button_x;
	second_button_y = right_height * 2 / 3;
	//��ʼ����ͣ״̬����
	for (auto temp : is_map_over) {
		temp = false;
	}
	//����ǰѡ��ĵ�ͼ��my_maps�ж�ȡ
	map_selected_id = my_maps.now_selected_map_id();
	//������ť
	my_button.push_back(new button(button_width, button_height, first_button_x, first_button_y, first_button_text, [this,&my_maps]() {
		set_next_id(page_id::NAVIGATION_PAGE); 
		my_maps.set_selected_map_id(now_selected_page_id);
		my_maps.write_file();
		}));
	my_button.push_back(new button(button_width, button_height, second_button_x, second_button_y, second_button_text, [this,&my_maps]() {
		set_next_id(page_id::MAP_EDITING_PAGE); 
		my_maps.set_selected_map_id(now_selected_page_id);
		my_maps.write_file();
		}));
	//������Ч�����Χ
	map_left_space_x = map_width / 2 * (1 - unselected_scale);
	map_left_space_y = map_height / 2 * (1 - unselected_scale);
	//���õ�ͼ�Ŵ������
	map_left_space_x_selected = map_width / 2 * (1 - selected_scale);
	map_left_space_y_selected = map_height / 2 * (1 - selected_scale);
}

void map_select_page::get_keyboard_message()
{
	ExMessage msg;
	while (peekmessage(&msg)) {
		switch (msg.message) {
		case(WM_MOUSEMOVE):
			//�ȼ���Ƿ��ڰ�ť����
			for (button* temp_button_ptr : my_button) {
				temp_button_ptr->checkMouseOver(msg.x,msg.y);
			}
			//�ټ���Ƿ��ڵ�ͼ��
			for (int i = 0; i <= 1; i++) {
				for (int j = 0; j <= 1; j++) {
					if((map_left_space_x+map_width*j)<=msg.x && 
						(map_width - map_left_space_x+map_width*j)>=msg.x &&
						(map_left_space_y + map_height * i) <= msg.y &&
						(map_height - map_left_space_y + map_height * i >= msg.y)) {
						is_map_over[i][j] = true;
					}
					else {
						is_map_over[i][j] = false;
					}
		
				}
			}
			break;
		case (WM_ACTIVATE):
			for (int i = 0; i <= 1; i++) {
				for (int j = 0; j <= 1; j++) {
					if ((map_left_space_x + map_width * j) <= msg.x &&
						(map_width - map_left_space_x + map_width * j) >= msg.x &&
						(map_left_space_y + map_height * i) <= msg.y &&
						(map_height - map_left_space_y + map_height * i >= msg.y)) {
						map_selected_id = i * 2 + j;
					}
				}
			}
			break;
		}
	}
}

void map_select_page::draw()
{	
	//���ư�ť
	for (auto temp_ptr : my_button) {
		temp_ptr->draw();
	}
	//���Ƶ�ͼ������ѡ�еĵ�ͼ����Ϊǳ����
	int map_i = map_selected_id / 2;
	int map_j = map_selected_id % 2;
	//���ñ�����ɫΪǳ��
	setfillcolor(0xe6d8ad);//��ʽΪbgr
	rectangle(map_width * map_j, map_height * map_i, map_width * (map_j + 1), map_height * (map_i + 1));
	//���Ƶ�ͼ
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			if (is_map_over[i][j]) {
				my_maps.draw(map_width, map_height, map_left_space_x + map_width * j, map_left_space_y + map_height * i, i * 2 + j);
			}
			else {
				my_maps.draw(map_width, map_height, map_left_space_x_selected + map_width * j, map_left_space_y_selected + map_height * i, i * 2 + j);
			}
		}
	}
}

map_select_page::~map_select_page() {
	while (!my_button.empty()) {
		delete my_button.back();
		my_button.pop_back();

	}
}

