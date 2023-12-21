#pragma once
//class maps ���ڹ���map�࣬������ͼ�浵�����ĵ�д��
//ʵ�ֵĵ�ͼΪ15��10��
#include <string>
#include "map.h"
#include "houses.h"
#include "roads.h"

class maps {
public:
	friend class map;
	//����ͼ�浵����ȫ������һ���ļ����У��������ļ��е�·������path
	//���캯�������������ļ�λ�ã�����read_file�����ͼ����
	maps(std::wstring path);//��ʼ���б�
	//��ָ����ͼid�Ĵ浵�ļ��е����������ڴ�
	void read_file(int id);
	//���ص�ǰѡ��ĵ�ͼid
	int now_selected_map_id();
	//���ĵ�ǰѡ��ĵ�ͼ
	void set_selected_map_id(int n);
	//����ǰѡ��ĵ�ͼ����浵�ļ�
	void write_file();
	//����ָ��id�ĵ�ͼ
	void draw(int width,int height, int x, int y, int id);
	//���Ƶ�ǰѡ��ĵ�ͼ
	void draw_selected(int width,int height, int x, int y);

	//��������������������selected_map_id
	//���Ӷ���(����Ѿ����˾����
	//��������ͷ���id(road id Ϊ0��
	void add_building(int x, int y, int house_type);
	//��������
	//ɾ������
	// ��������(ɾ�����Ӻ͵�·��һ�����������������û�ж����Ͳ��䣩
	void delete_build(int x, int y);


	//�������أ����·��
	bool connect_houses(int house_type1, int house_type2);
	//�������·��
	void clear_connnect_houses();
	//���ظ����ĵ�ͼid�Ƿ񱻱༭��
	bool is_edited(int page_id);
private:
	const static int NUM = 4;
	
	int selected_map_id;
	//��ŵ�ͼ���ݵ��ļ���λ��
	std::wstring path;
	map* my_map[NUM];
	roads my_roads;
	houses my_houses;
	//ÿ����ͼ15�У�10��
	const static int column = 15;
	const static int row = 10;
};