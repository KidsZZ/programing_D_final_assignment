#pragma once
//class maps ���ڴ����ͼ������Ϣ
//ģ���࣬ʵ���ļ�Ҫ����ͷ�ļ���
#include <string>
#include "map.h"
#include "houses.h"
#include "roads.h"

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
	void draw(int length, int x, int y, int id);
	//���Ƶ�ǰѡ��ĵ�ͼ
	void draw_selected(int length, int x, int y);
	//��������������������selected_map_id
	//��������ͷ���id
	void change_house(int x, int y, int house_type);
	//��������
	void change_road(int x, int y);
	//�������أ����·��
	bool connect_houses(int house_type, int house_type);
private:
	int selected_map_id;
	string path;
	map my_map[NUM];
	roads my_roads;
	houses my_houses;
	//ÿ����ͼ15�У�10��
	const static int column = 15;
	const static int row = 10;
};