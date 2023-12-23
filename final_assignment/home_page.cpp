#include "home_page.h"
#include <graphics.h>
#include "enum_lib.h"

//�ڳ�ʼ��ʱ����ഫ�뵱ǰҳ���id
home_page::home_page(int w, int h) :abstract_page(page_id::HOME_PAGE, w, h) {

	//���ñ���
	bk_img = new IMAGE();
	//����ͼƬ������Ŀ�ļ���background_img�£�����background.png
	loadimage(bk_img, L"background_img/background.png");

	//���ñ����ı�
	title_text = L"����У԰����ϵͳ";

	//���ñ���ߴ�
	title_size = 100;

	//���ñ���ĳߴ�
	//����������������������ȣ���λ��
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
	// ʹ��lambda���ʽ����ť���ð��º�Ļص�����
	//��һ����ť����ʼ��Ϸ
	my_button.push_back(new button(button_width, button_height, first_button_x, first_button_y, first_button_text, [this]() {set_next_id(page_id::MAP_SELECT_PAGE); }));
	//�ڶ�����ť���˳���Ϸ
	my_button.push_back(new button(button_width, button_height, second_button_x, second_button_y, second_button_text, [this]() {set_next_id(page_id::EXIT); }));

}

//���������Ϣ
//�����ҳ����Ҫ�жϰ�ť
void home_page::get_keyboard_message() {
	
	ExMessage msg;

	while (peekmessage(&msg)) {

		//������û�а��£�����over����
		if (msg.message == WM_MOUSEMOVE) {
			for (button* tbutton_ptr : my_button) {
				//over�������鵱ǰ�Ƿ���Ҫ���°�ť����Ĳ���
				tbutton_ptr->checkMouseOver(msg.x, msg.y);
			}
		}

		//�����갴�£�����click��������Ƿ�����ť
		//��������ť�����ù���ʱ���õĻص�����
		else if (msg.message == WM_LBUTTONDOWN) {
			for (button* tbutton_ptr : my_button) {
				tbutton_ptr->checkMouseClick(msg.x,msg.y);
			}
		}
	}
}
void home_page::draw() {

	//���Ʊ���
	//ʹ�ñ���ͼƬ���
	putimage(0, 0, width, height, bk_img, 0, 0);

	//��easyx�У���Ҫ������������ĺ����������»��Ʊ���
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

	//�ͷű���ͼƬ
	delete bk_img;

	//�ͷŰ�ť����
	while (!my_button.empty()) {
		delete my_button.back();
		my_button.pop_back();
	}
}