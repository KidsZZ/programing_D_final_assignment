#pragma once
//class picture_option���ڷ�����ͼƬ��ѡ������ڵ�ͼѡ��ҳ�Ĵ浵���Ƽ���ͼ�༭ҳ��ѡ����ƣ�
#include "option.h"
#include <graphics.h>
#include <string>
class picture_option :public option {
public:
	picture_option(std::string path,std::string exp);
	picture_option(int width,int length,int x,int y,std::string path,std::string exp);
	void draw(int width, int length, int x, int y);
private:
	//����ͼƬ
	IMAGE* opt_img;
	//����ͼƬ˵��
	std::string exp��
};
