#pragma once
//class picture_button���ڷ�����ͼƬ��ѡ������ڵ�ͼ�༭ҳ�Ľ�������·ѡ����ƣ�
#include <graphics.h>
#include <string>
#include <functional>
class picture_button {
public:
	picture_button(std::wstring path,std::wstring exp,int width,int height,int x,int y,std::function<void()> my_fun);
	void checkMouseOver(int mouse_x, int mouse_y);
	void checkMouseClick(int mouse_x, int mouse_y);
	//����heightҪ��width���Ҳ���֤һ�����ڸ�����Χ��
	void draw();
	~picture_button();
private:
	//����ͼƬ
	IMAGE* opt_img;
	//����ͼƬ˵��������ͼƬ�·���
	std::wstring exp;
	std::function<void()> my_fun;
	//����ͼƬ����
	double scale;
	//ѡ�������ߴ�
	int width, height;
	//ѡ������
	int x, y;
	int real_img_x;
	int real_img_y;
	int real_img_length;
	bool is_selected;
	//����λ��
	int real_text_x;
	int real_text_y;
};
