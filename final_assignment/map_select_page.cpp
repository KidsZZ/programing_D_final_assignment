#include "map_select_page.h"
#include "enum_lib.h"
map_select_page::map_select_page(int w, int h, maps& my_maps) :abstract_page(page_id::MAP_SELECT_PAGE, w, h), my_maps(my_maps){

	//���ñ���
	bk_img = new IMAGE();
	//����ͼƬ������Ŀ�ļ���background_img�£�����background.png
	loadimage(bk_img, L"background_img\\background0.jpg");

	//���ģ��ռ��80%���ұ�ռ��20%
	left_width = width * 0.8;
	right_width = width - left_width;
	left_height = right_height = height;

	//��ͼ���,�ȷ�Ϊ4��
	map_width = left_width / 2;
	map_height = left_height / 2;

	//��ͼ���ű���
	unselected_scale = 0.65;
	selected_scale = 0.8;

	//��ť�ߴ�
	button_width = 200;
	button_height = 70;
	//��ť�ı�
	first_button_text = L"��ʼ����";
	second_button_text = L"�༭��ͼ";
	//��ť����
	//��һ����ť��������֮һ��λ��
	first_button_x = left_width;
	first_button_y = right_height / 3;
	//�ڶ�����ť��������֮����λ��
	second_button_x = first_button_x;
	second_button_y = right_height * 2 / 3;

	//��ʼ����ͣ״̬����
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			is_map_over[i][j] = false;
		}

		//����ǰѡ��ĵ�ͼ��my_maps�ж�ȡ
		map_selected_id = my_maps.now_selected_map_id();

		//������ť
		//��һ����ť����ʼ����
		my_button.push_back(new button(button_width, button_height, first_button_x, first_button_y, first_button_text, [this, &my_maps]() {
			set_next_id(page_id::NAVIGATION_PAGE);
			my_maps.set_selected_map_id(map_selected_id);
			//��Ҫ���ڱ��浱ǰѡ���ͼ�ı��
			my_maps.write_file();
			printf("click navigation_button\n");

			}));
		//�ڶ�����ť���༭��ͼ
		my_button.push_back(new button(button_width, button_height, second_button_x, second_button_y, second_button_text, [this, &my_maps]() {
			set_next_id(page_id::MAP_EDITING_PAGE);
			my_maps.set_selected_map_id(map_selected_id);
			//��Ҫ���ڱ��浱ǰѡ���ͼ�ı��
			my_maps.write_file();
			}));

		//���ذ�ť
		return_button = new button(250, 50, 0, 0, L"����", [this, &my_maps]() {
			//�л�ҳ�棬������Ϣ
			set_next_id(page_id::HOME_PAGE);
			my_maps.write_file();
			printf("click return_button\n");
			});

		//������겻������ʱ��ͼ�ߴ�
		map_left_space_x = map_width / 2 * (1 - unselected_scale);
		map_left_space_y = map_height / 2 * (1 - unselected_scale);
		//�������������ʱ��ͼ�ߴ�
		map_left_space_x_selected = map_width / 2 * (1 - selected_scale);
		map_left_space_y_selected = map_height / 2 * (1 - selected_scale);

		//��ʼ�����ŵ�ͼ��ʵ�����꣬����Ϊ���Ͻ�Ϊ0��0
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 1; j++) {
				map_real[i][j][0] = map_left_space_x;
				map_real[i][j][1] = map_left_space_y;
			}
		}

	}
}

//�����������
//��Ҫ��飺��ͼѡ����ذ�ť�����ܰ�ť
void map_select_page::get_keyboard_message()
{
	ExMessage msg;
	while (peekmessage(&msg)) {
		switch (msg.message) {
		case(WM_MOUSEMOVE):
			//�ȼ���Ƿ��ڹ��ܰ�ť����
			for (button* temp_button_ptr : my_button) {
				temp_button_ptr->checkMouseOver(msg.x,msg.y);
			}
			//�ټ���Ƿ��ڷ��ذ�����
			return_button->checkMouseOver(msg.x, msg.y);
			//�ټ���Ƿ��ڵ�ͼ��
			//����ͼ����ʱ����ⷶΧҲҪ�ı�
			for (int i = 0; i <= 1; i++) {
				for (int j = 0; j <= 1; j++) {
					if((map_real[i][j][0] + map_width * j) <= msg.x &&
						(map_width - map_real[i][j][0] + map_width * j) >= msg.x &&
						(map_real[i][j][1] + map_height * i) <= msg.y &&
						(map_height - map_real[i][j][1] + map_height * i >= msg.y)) {
						//���õ�ǰ��ͼΪѡ��
						is_map_over[i][j] = true;
						//������Ч�߽�
						map_real[i][j][0] = map_left_space_x_selected;
						map_real[i][j][1] = map_left_space_y_selected;
					}
					else {
						//����δѡ��
						is_map_over[i][j] = false;
						//������Ч�߽�
						map_real[i][j][0] = map_left_space_x;
						map_real[i][j][1] = map_left_space_y;
					}
				}
			}
			break;
		case (WM_LBUTTONDOWN):

			//�ȼ���Ƿ��ڷ��ذ�����
			return_button->checkMouseClick(msg.x, msg.y);

			//�ټ���Ƿ��ڹ��ܰ�����
			for (button* temp_button_ptr : my_button) {
				temp_button_ptr->checkMouseClick(msg.x, msg.y);
			}

			//�ټ���Ƿ��ڵ�ͼ��
			for (int i = 0; i <= 1; i++) {
				for (int j = 0; j <= 1; j++) {
					//���������ǵ�ͼ��������map_selected_id��������ǣ��ͺ���
					if ((map_real[i][j][0] + map_width * j) <= msg.x &&
						(map_width - map_real[i][j][0] + map_width * j) >= msg.x &&
						(map_real[i][j][1] + map_height * i) <= msg.y &&
						(map_height - map_real[i][j][1] + map_height * i >= msg.y)) {
						//���õ�ǰ��ͼΪѡ��
						map_selected_id = i * 2 + j;
					}
				}
			}
			break;
		}
	}
}

//����Ԫ�أ����ذ�������ͼѡ����ܰ�ť
void map_select_page::draw()
{	
	//���Ʊ���
	putimage(0, 0, width, height, bk_img, 0, 0);

	//���Ƶ�ͼ������ѡ�еĵ�ͼ����Ϊǳ����
	int map_i = map_selected_id / 2;
	int map_j = map_selected_id % 2;

	//���ñ�����ɫΪǳ��
	setfillcolor(0xe6d8ad);//��ʽΪbgr
	solidrectangle(map_width * map_j + map_width * 0.05, map_height * map_i + map_height * 0.05, map_width * (map_j + 1) - map_width * 0.05 , map_height * (map_i + 1) - map_height * 0.05);


	//���ƹ��ܰ�ť
	for (auto temp_ptr : my_button) {
		temp_ptr->draw();
	}


	//���Ƶ�ͼ
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			//ʹ�ô�����map_real�е����ݷֱ���Ƶ�ͼ
			my_maps.draw(map_width - map_real[i][j][0] * 2, map_height - map_real[i][j][1] * 2, map_width * j + map_real[i][j][0], map_height * i + map_real[i][j][1], i * 2 + j);
		}
	}
	//���Ʒ��ذ�ť
	return_button->draw();
}

//��������
//�ͷ��ڴ�
map_select_page::~map_select_page() {
	//����ͼƬ
	delete bk_img;

	//���ذ�ť
	delete return_button;

	//���ܰ�ť
	while (!my_button.empty()) {
		delete my_button.back();
		my_button.pop_back();

	}
}

int map_select_page::return_page_id() {
	if (return_flag) {
		return_flag = false;
		return next_id;
	}
	else {
		return page_id::MAP_SELECT_PAGE;
	}
}

