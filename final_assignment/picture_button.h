#pragma once
//class picture_button���ڷ�����ͼƬ��ѡ������ڵ�ͼ�༭ҳ�Ľ�������·ѡ����ƣ�
#include <graphics.h>
#include <string>
class picture_button {
public:
	picture_button(std::wstring path,std::wstring exp,int width,int height,int x,int y);
	void checkMouseOver(int mouse_x, int mouse_y);
	void checkMouseClick(int mouse_x, int mouse_y);
	//����heightҪ��width���Ҳ���֤һ�����ڸ�����Χ��
	void draw();
private:
	//����ͼƬ
	IMAGE* opt_img;
	//����ͼƬ˵��������ͼƬ�·���
	std::wstring exp;
	//����ͼƬ����
	double scale;
	double over_scale;
	//ѡ�������ߴ�
	int width, height;
	//ѡ������
	int x, y;
	int real_img_x;
	int real_img_y;
	int real_img_length;
	bool is_mouse_over;
	//����λ��
	int real_text_x;
	int real_text_y;
};
