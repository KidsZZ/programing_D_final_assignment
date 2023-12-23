#include "home_page.h"
#include <graphics.h>
#include "enum_lib.h"
home_page::home_page(int w, int h) :abstract_page(page_id::HOME_PAGE, w, h), mouse_x(0), mouse_y(0) {
	//���ñ���


	//���ñ����ı�
	title_text = L"����У԰����ϵͳ";
	//���ñ���ߴ�
	title_size = 100;
	//���ñ���ĳߴ�
	settextstyle(title_size, 0, L"������κ");
	//���ñ���λ��
	title_x = (width - textwidth(title_text.c_str())) / 2;//����
	title_y = height * 0.15;//���붥��20%�Ŀ��


	//��ť���
	button_width = 400;
	//��ť�߶�
	button_height = 100;

	//���õ�һ����ť����
	// ��ť�ı�
	first_button_text = L"��ʼ��Ϸ";
	//��ť����
	first_button_x = (width - button_width) / 2;
	first_button_y = (height / 2);

	//���õڶ�����ť����
	// ��ť�ı�
	second_button_text = L"�˳���Ϸ";
	//��ť����
	second_button_x = (width - button_width) / 2;
	second_button_y = (height * 0.75);


	//���ð�ť
	my_button.push_back(new button(button_width, button_height, first_button_x, first_button_y, first_button_text, [this]() {set_next_id(page_id::MAP_SELECT_PAGE); }));
	my_button.push_back(new button(button_width, button_height, second_button_x, second_button_y, second_button_text, [this]() {set_next_id(page_id::EXIT); }));

	//draw();

}

void home_page::get_keyboard_message() {
	ExMessage msg;
	while (peekmessage(&msg)) {
		if (msg.message == WM_MOUSEMOVE) {
			for (button* tbutton_ptr : my_button) {
				tbutton_ptr->checkMouseOver(msg.x, msg.y);
			}
		}
		else if (msg.message == WM_LBUTTONDOWN) {
			for (button* tbutton_ptr : my_button) {
				tbutton_ptr->checkMouseClick(msg.x,msg.y);
			}
		}
	}
}
void home_page::draw() {
	//���Ʊ���
	setbkcolor(LIGHTBLUE);
	cleardevice();
	//���Ʊ���
	settextstyle(title_size, 0, L"����");
	outtextxy(title_x, title_y, title_text.c_str());
	//���ư�ť
	for (button* tbutton_ptr : my_button) {
		tbutton_ptr->draw();
	}
}

home_page::~home_page() {
	while (!my_button.empty()) {
		delete my_button.back();
		my_button.pop_back();
	}
}