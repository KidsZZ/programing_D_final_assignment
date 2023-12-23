#include "map_editing_page.h"
#include "enum_lib.h"
map_editing_page::map_editing_page(int w, int h, maps& my_maps) :abstract_page(page_id::MAP_EDITING_PAGE, w, h) ,my_maps(my_maps){
	//����ģ��ߴ�
	left_width = width * 0.8;
	right_width = width - left_width;
	left_height = right_height = height;
	//��ͼʵ�ʳߴ�
	map_width = left_width * 0.85;
	map_height = map_width / 1.5;
	map_real_x = (width - left_width) / 2;
	map_real_y = (height - map_height) / 2;
	//��ͼ��ߵĿռ�
	// һ������ѡ��ĳ���(ָ�ұ�ѡ���еĽ����������ߴ磩
	single_object_width = right_width;
	single_object_height = right_height / 5;
	//��ʼ��picture_button
	std::wstring build_exp[building_num] = { 
		L"road",
		L"library",
		L"dorminory",
		L"teaching_building",
		L"canteen" };
	for (int i = 0; i < building_num; i++) {
		std::wstring temp_path = L"building_img/build"+std::to_wstring(i)+L".png";
		my_picture_button.push_back(new picture_button(temp_path, build_exp[i].
			c_str(), single_object_width, single_object_height, left_width,single_object_height*i,[this,i](){
				//Ϊÿ��ͼƬ��ť����lambda���ʽ
				set_now_select_building_id(i);
}));
	}
	//Ĭ�ϲ�ѡ����(-1)
	now_select_building = -1;
	//���ذ���
	return_button = new button(150, 50, 0, 0, L"����", [this,&my_maps]() {
		//�л�ҳ�棬������Ϣ
		set_next_id(page_id::MAP_SELECT_PAGE); 
		my_maps.write_file();
		});
}

void map_editing_page::get_keyboard_message() {
	ExMessage msg;
	while (peekmessage(&msg)) {
		switch (msg.message) {
		case(WM_MOUSEMOVE):
			//�ȼ���Ƿ���ͼƬ��ť����
			for (auto tempptr : my_picture_button) {
				tempptr->checkMouseOver(msg.x,msg.y);
			}
			//����ڰ�ť��
			return_button->checkMouseOver(msg.x, msg.y);
			break;
		case (WM_ACTIVATE):
			//�ȼ���Ƿ���ͼƬ��ť����
			for (auto tempptr : my_picture_button) {
				tempptr->checkMouseClick(msg.x, msg.y);
			}
			//����Ƿ��ڵ�ͼ��
			//����ڵ�ͼ��ͼ�ϣ���now_select_building��Ϊ-1ʱ���ݲ�����maps
			if ((msg.x >= map_real_x) && (msg.x < (map_real_x + map_width)) && (msg.y >= map_real_y) && (msg.y <= (map_real_y + map_height))) {
				if (now_select_building != -1) {
					my_maps.add_building(msg.x, msg.y, now_select_building);
				}
			}
			//����ڰ�ť��
			return_button->checkMouseClick(msg.x, msg.y);
			break;
		}
	}
}

void map_editing_page::draw()
{
	//�Ȼ�����
	setbkcolor(0xf6eb76);
	cleardevice();
	//�ٻ���ͼ
	my_maps.draw_selected(map_width, map_height, map_real_x, map_real_y);
	//�ٻ����ذ�ť
	return_button->draw();
	//�ٻ�����ѡ��
	for (auto tempptr : my_picture_button) {
		tempptr->draw();
	}
}

map_editing_page::~map_editing_page() {
	//ɾ������ѡ��
	while (!my_picture_button.empty()) {
		delete my_picture_button.back();
		my_picture_button.pop_back();
	}
	delete return_button;
}
