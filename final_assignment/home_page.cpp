#include "home_page.h"
#include <graphics.h>
#include "enum_lib.h"
home_page::home_page(int next_id, int w, int h) :abstract_page(next_id, w, h), mouse_x(0), mouse_y(0) {
	//���ñ���


	//���ñ����ı�
	title_text = L"��ӭʹ�ü���У԰����ϵͳ";
	//���ñ���ĳߴ�
	settextstyle(100, 0, L"΢���ź�");
	//���ñ���λ��
	//title_x = (width - textwidth(title_text.c_str())) / 2;//����
	title_x = 600;//����

	title_y = height * 2 / 10;//���붥��20%�Ŀ��

	//��ť���
	button_width = 400;
	//��ť�߶�
	button_height = 100;

	//���õ�һ����ť����
	// ��ť�ı�
	first_button_text = L"��ʼ��Ϸ";
	//��ť����
	first_button_x = (width - button_width / 2);
	first_button_y = (height / 2);

	//���õڶ�����ť����
	// ��ť�ı�
	second_button_text = L"�˳���Ϸ";
	//��ť����
	second_button_x = (width - button_width / 2);
	second_button_y = (height * 0.35);


	//���Ʊ���

	//���Ʊ���
	outtextxy(title_x, title_y, title_text.c_str());

	//���ð�ť
	my_option.push_back(new option(button_width, button_height, first_button_x, first_button_y, first_button_text, [this]() {set_next_id(page_id::MAP_SELECT_PAGE); }));
	my_option.push_back(new option(button_width, button_height, second_button_x, second_button_y, second_button_text, [this]() {set_next_id(page_id::EXIT); }));

}

void home_page::get_keyboard_message() {
	ExMessage msg;
	while (peekmessage(&msg)) {
		if (msg.message == WM_MOUSEMOVE) {
			for (option* toption_ptr : my_option) {
				toption_ptr->checkMouseOver(msg.x, msg.y);
			}
		}
		else if (msg.message == WM_LBUTTONDOWN) {
			for (option* toption_ptr : my_option) {
				toption_ptr->checkMouseClick(msg.x,msg.y);
			}
		}
	}
}
void home_page::draw() {
	for (option* toption_ptr : my_option) {
		toption_ptr->draw();
	}
}

home_page::~home_page() {
	while (!my_option.empty()) {
		delete my_option.back();
		my_option.pop_back();
	}
}