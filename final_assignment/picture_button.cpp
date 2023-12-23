#include "picture_button.h"

picture_button::picture_button(std::wstring path, std::wstring exp, int width, int height, int x, int y, std::function<void()> my_fun) :exp(exp), width(width), height(height), x(x), y(y), my_fun(my_fun)
{
	//��ʼ��ѡ��ͼƬ
	opt_img = new IMAGE();
	loadimage(opt_img, path.c_str());

	//ͼƬ����
	scale = 0.8;

	//����ͼƬ�ĳߴ�
	real_img_length = width * scale;
	real_img_x = x + (width -real_img_length) / 2;
	real_img_y = y + (height - real_img_length * 1.1) / 2;

	//Ĭ����겻��ѡ����
	is_over = false;

	//�õ����ֳߴ�
	//�����������
	settextstyle(20, 0, L"����");
	real_text_x = x + (width - textwidth(exp.c_str())) / 2;
	real_text_y = y + height * 0.9;

}

void picture_button::checkMouseOver(int mouse_x, int mouse_y) {
	if ((mouse_x >= real_img_x) && (mouse_x <= real_img_x + real_img_length) && (mouse_y >= real_img_y) && (mouse_y <= real_img_y + real_img_length)) {
		scale = 0.9;
		is_over = true;
	}
	else {
		scale = 0.8;
		is_over = false;
	}
}

void picture_button::checkMouseClick(int mouse_x, int mouse_y) {
	if ((mouse_x >= real_img_x) && (mouse_x <= real_img_x + real_img_x) && (mouse_y >= real_img_y) && (mouse_y <= real_img_y + real_img_length)) {
		my_fun();
	}
}

void picture_button::draw() {
	
	//����scale����ͼƬ�ߴ�
	real_img_length = width * scale;
	real_img_x = x + (width - real_img_length) / 2;
	real_img_y = y + (height - real_img_length * 1.1) / 2;

	//����ѡ��ͼƬ
	putimage(real_img_x, real_img_y, real_img_length, real_img_length, opt_img, 0, 0);

	//��������
	settextstyle(20, 0, L"����");
	outtextxy(real_text_x, real_img_y, exp.c_str());
}
picture_button::~picture_button() {
	delete opt_img;
}
