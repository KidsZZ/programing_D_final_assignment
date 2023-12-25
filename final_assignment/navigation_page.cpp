#include "navigation_page.h"
#include "enum_lib.h"
#include "picture_button.h"
navigation_page::navigation_page(int w, int h, maps& my_maps) :abstract_page(page_id::NAVIGATION_PAGE, w, h), my_maps(my_maps)
{	

	//��������
	bk_img = new IMAGE();
	//����ͼƬ������Ŀ�ļ���background_img�£�����background.png
	loadimage(bk_img, L"background_img\\background0.jpg");

	//����ҳ��ģ��ߴ�
	left_width = width * 0.8;
	right_width = width - left_width;
	left_height = right_height = height;

	//��ͼ����
	scale = 0.85;

	//��ͼʵ�ʳ���
	map_width = (left_width * (1 - scale));
	map_height = map_width / 1.5;
	
	//��ͼʵ������
	map_real_x = (left_width - map_width) / 2;
	map_real_y = (left_height - map_height) / 2;

	// ���ذ�ť
	return_button = new button(150, 50, 0, 0, L"����", [this]() {
		set_next_id(page_id::MAP_SELECT_PAGE);
		});

	//�ұ߹��ܲ˵�����
	// һ������ѡ��ĳ���(ָ�ұ�ѡ���еĽ����������ߴ磩
	single_object_width = right_width;
	single_object_height = right_height / 4;

	//��ʼ��picture_button
	//���ð�ť�ı�
	std::wstring build_exp[building_num] = {
		L"road",
		L"library",
		L"dorminory",
		L"teaching_building",
		L"canteen" 
	};

	for (int i = 1; i < building_num; i++) {
		std::wstring temp_path = L"picture_hub\\house" + std::to_wstring(i) + L".png";
		my_picture_button.push_back(new picture_button(temp_path, build_exp[i].
			c_str(), single_object_width, single_object_height, left_width, single_object_height * (i - 1), [this, i]() {
				//Ϊÿ��ͼƬ��ť����lambda���ʽ
				set_now_select_building_id(i);
			}));

		//��Ĭ��ֵ����Ϊ-1����ʾ��ǰû��ѡ��
		now_select_building[0] = -1;
		now_select_building[1] = -1;
		now_select_building_num = 0;
	}
}

//��Ҫѡ�������������ܽ��е�����������Ҫ��set_now_select_building_id�н��з�������
void navigation_page::set_now_select_building_id(int i)
{
	switch (now_select_building_num) {

	case(0):
		//û��ѡ��ʱ
		++now_select_building_num;
		now_select_building[0] = i;
		break;

	case(1):

		//�ظ����ɾ��ѡ����
		if (now_select_building[0] == i) {
			now_select_building_num--;
			now_select_building[0] = -1;
		}

		//�����С�Ľ�������ǰ��
		else if (now_select_building[0] > i) {
			now_select_building_num++;
			now_select_building[1] = now_select_building[0];
			now_select_building[0] = i;
			//�����������������õ�������������������
			my_maps.connect_houses(now_select_building[0], now_select_building[1]);
		}
		else {
			now_select_building_num++;
			now_select_building[1] = i;
			//�����������������õ�������������������
			my_maps.connect_houses(now_select_building[0], now_select_building[1]);
		}
		break;
	case(2):
		//������ѡ����Ľ�������ɾ������
		if (now_select_building[0] == i) {
			now_select_building_num--;
			now_select_building[0] = now_select_building[1];
			now_select_building[1] = -1;
			//������ѡ�������������������
			my_maps.clear_connnect_houses();
		}

		else if (now_select_building[1] == i) {
			now_select_building_num--;
			now_select_building[1] = -1;
			//������ѡ�������������������
			my_maps.clear_connnect_houses();
		}
		//��������������Ϊ��Ч���
		else {
			printf("\nѡ����Ч��\n");
		}
		break;
	default:
		printf("navigation_page switch error2!");
	}
}


//�����������
void navigation_page::get_keyboard_message() {
	ExMessage msg;
	while (peekmessage(&msg)) {
		switch (msg.message) {

		//������ƶ�
		case(WM_MOUSEMOVE):

			//����Ƿ��ڷ��ذ�ť��
			return_button->checkMouseOver(msg.x, msg.y);

			//����Ƿ���ͼƬ��ť����
			for (auto tempptr : my_picture_button) {
				tempptr->checkMouseOver(msg.x, msg.y);
			}

			break;
		//����������
		case (WM_LBUTTONDOWN):

			//����ڷ��ذ�ť��
			return_button->checkMouseClick(msg.x, msg.y);

			//�ȼ���Ƿ���ͼƬ��ť����
			for (auto tempptr : my_picture_button) {
				tempptr->checkMouseClick(msg.x, msg.y);
			}
			break;
		}
	}
}

void navigation_page::draw() {

	//��������
	putimage(0, 0, width, height, bk_img, 0, 0);

	//���Ƶ�ͼ
	my_maps.draw_selected(map_width, map_height, map_real_x, map_real_y);

	//���ذ���
	return_button->draw();

	//����ѡ��
	for (auto tempptr : my_picture_button) {
		tempptr->draw();
	}
}

navigation_page::~navigation_page() {

	//ɾ������ͼƬ
	delete bk_img;

	//ɾ�����ذ�ť
	delete return_button;

	//ɾ������ѡ��
	while (!my_picture_button.empty()) {
		delete my_picture_button.back();
		my_picture_button.pop_back();
	}

}

int navigation_page::return_page_id()
{
	if (return_flag) {
		return_flag = false;
		return next_id;
	}
	else {
		return page_id::NAVIGATION_PAGE;
	}
}
