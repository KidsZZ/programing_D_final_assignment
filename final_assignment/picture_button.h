#pragma once
//class picture_button���ڷ�����ͼƬ��ѡ������ڵ�ͼѡ��ҳ�Ĵ浵���Ƽ���ͼ�༭ҳ��ѡ����ƣ�
#include "button.h"
#include <graphics.h>
#include <string>
class picture_button :public button {
public:
	picture_button(std::string path,std::string exp);
	picture_button(int width,int length,int x,int y,std::string path,std::string exp);
	void draw(int width, int length, int x, int y);
private:
	//����ͼƬ
	IMAGE* opt_img;
	//����ͼƬ˵��
	std::string exp��
};
