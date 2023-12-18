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
	void draw(int width,int height, int x, int y, int id);
	//���Ƶ�ǰѡ��ĵ�ͼ
	void draw_selected(int width,int height, int x, int y);
	//��������������������selected_map_id
	//���Ӷ���(����Ѿ����˾����
	//��������ͷ���id
	void add_house(int x, int y, int house_type);
	//��������
	void add_road(int x, int y);
	//ɾ������
	// ��������(ɾ�����Ӻ͵�·��һ�����������������û�ж����Ͳ��䣩
	void delete_build
	//�������أ����·��
	bool connect_houses(int house_type1, int house_type2);
	//���ظ����ĵ�ͼid�Ƿ񱻱༭��
	bool is_edited(int page_id);
private:
	//���������x��y����Ӧ�ĸ���(����һ�����鱣���������ֵ)
	void tranlate_xy(int* ans, int x, int y);
	int selected_map_id;
	std::wstring path;
	map my_map[NUM];
	roads my_roads;
	houses my_houses;
	//ÿ����ͼ15�У�10��
	const static int column = 15;
	const static int row = 10;
};