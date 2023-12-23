#include "map_editing_page.h"
#include "enum_lib.h"

//���캯����������ز���
map_editing_page::map_editing_page(int w, int h, maps& my_maps) :abstract_page(page_id::MAP_EDITING_PAGE, w, h) ,my_maps(my_maps){

	//��������
	bk_img = new IMAGE();
	//����ͼƬ������Ŀ�ļ���background_img�£�����background.png
	loadimage(bk_img, L"background_img\\background.png");

	//����ģ��ߴ磬���ռ��80%
	left_width = width * 0.8;
	right_width = width - left_width;
	left_height = right_height = height;

	//��ͼʵ�ʳߴ�
	map_width = left_width * 0.85;
	map_height = map_width / 1.5;
	map_real_x = (left_width - map_width) / 2;
	map_real_y = (left_height - map_height) / 2;

	//��ͼ��ߵĿռ�
	// һ������ѡ��ĳ���(ָ�ұ�ѡ���еĽ����������ߴ磩
	//�ȷ��ұߵĿռ�
	single_object_width = right_width;
	single_object_height = right_height / 5;

	//��ʼ��picture_button
	//����ѡ���ı�
	std::wstring build_exp[building_num] = { 
		L"road",
		L"library",
		L"dorminory",
		L"teaching_building",
		L"canteen" 
	};

	//�������ý�����ť
	for (int i = 0; i < building_num; i++) {
		std::wstring temp_path = L"picture_hub\\house"+std::to_wstring(i)+L".png";
		my_picture_button.push_back(new picture_button(temp_path, build_exp[i].
			c_str(), single_object_width, single_object_height, left_width,single_object_height*i,[this,i](){
				//Ϊÿ��ͼƬ��ť����lambda���ʽ
				set_now_select_building_id(i);
			}
			)
		);
	}

	//Ĭ�ϲ�ѡ����(-1)
	now_select_building = -1;

	//���ذ���
	return_button = new button(250, 50, 0, 0, L"����", [this,&my_maps]() {
		//�л�ҳ�棬������Ϣ
		set_next_id(page_id::MAP_SELECT_PAGE); 
		my_maps.write_file();
		});
}


//����������ݣ����ذ�������ͼ����������
void map_editing_page::get_keyboard_message() {

	ExMessage msg;

	while (peekmessage(&msg)) {
		switch (msg.message) {
		case(WM_MOUSEMOVE):
			//�ȼ���Ƿ���ͼƬ��ť����
			for (auto tempptr : my_picture_button) {
				tempptr->checkMouseOver(msg.x,msg.y);
			}

			//����Ƿ��ڷ��ذ�ť��
			return_button->checkMouseOver(msg.x, msg.y);
			//***����Ƿ��ڵ�ͼ�ϣ���ûʵ�֣�***
			break;

		case (WM_ACTIVATE):
			//�ȼ���Ƿ���ͼƬ��ť����
			for (auto tempptr : my_picture_button) {
				tempptr->checkMouseClick(msg.x, msg.y);
			}

			//����ڰ�ť��
			return_button->checkMouseClick(msg.x, msg.y);

			//����Ƿ��ڵ�ͼ��
			//����ڵ�ͼ��ͼ�ϣ���now_select_building��Ϊ-1ʱ���ݲ�����maps
			if ((msg.x >= map_real_x) && (msg.x < (map_real_x + map_width)) && (msg.y >= map_real_y) && (msg.y <= (map_real_y + map_height))) {
				if (now_select_building != -1) {
					my_maps.add_building(msg.x, msg.y, now_select_building);
				}
			}
			break;
		}
	}
}

void map_editing_page::draw()
{
	//�Ȼ�����
	putimage(0, 0, width, height, bk_img, 0, 0);

	//��ͼ
	my_maps.draw_selected(map_width, map_height, map_real_x, map_real_y);

	//���ذ�ť
	return_button->draw();

	//�ٻ�����ѡ��
	//�����ǰ��ѡ����������ѡ��Ľ�����ͼ���Ʒ���
	if (now_select_building != -1) {
		setfillcolor(LIGHTGRAY);
		rectangle(left_width, single_object_height * now_select_building, width, single_object_height * (now_select_building + 1));
	}

	for (auto tempptr : my_picture_button) {
		tempptr->draw();
	}
}

map_editing_page::~map_editing_page() {
	//ɾ������ͼƬ
	delete bk_img;

	//ɾ������ѡ��
	while (!my_picture_button.empty()) {
		delete my_picture_button.back();
		my_picture_button.pop_back();
	}

	//ɾ�����ذ�ť
	delete return_button;
}
