#pragma once
//��������ĵ�һ��ҳ�棬��Ҫ�����ǳ���һЩ��������Ϣ


#include <string>
#include <vector>
#include "abstract_page.h"
#include "button.h"
#include <graphics.h>

//�̳�abstract_pageʵ�־��幦��
class home_page :public abstract_page {
public:

	//����ҳ�泤��
	home_page(int w, int h);

	//�޸Ļ����е��麯��
	//ʹ��overrideȷ��������
	virtual void get_keyboard_message()override;
	virtual void draw()override;
	virtual ~home_page()override;

private:

	//����ͼƬ
	IMAGE* bk_img;

	//�����ı�
	std::wstring title_text;

	//��ť�ı�
	std::wstring first_button_text;
	std::wstring second_button_text;

	//ʹ��vector���水ťָ��
	std::vector<button*> my_button;

	//�����ֺŴ�С
	int title_size;


	//ҳ��Ԫ�ض�λ
	int title_x, title_y;
	int button_width, button_height;
	int first_button_x, first_button_y;
	int second_button_x, second_button_y;
};