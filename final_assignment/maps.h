#pragma once
//class maps ���ڴ����ͼ������Ϣ
#include <string>
#include "map.h"

template<int NUM=4>
class maps {
public:
	//���캯�������������ļ�λ��
	maps(std::string path);
	//���ļ��е����������ڴ�
	void read_file();
	//���ĵ�ǰѡ��ĵ�ͼ
	void set_selected_map_id(int n);
	//���༭���ĵ�ͼ���������ļ�(Ϊ�˷��㣬ȫ����д��
	void write_file();
	//����ָ��id�ĵ�ͼ
	void draw(int width, int length, int x, int y, int id);
	//���Ƶ�ǰѡ��ĵ�ͼ
	void draw_selected(int width, int length, int x, int y);
private:
	int selected_map_id;
	string path;
	map my_map[NUM];
};