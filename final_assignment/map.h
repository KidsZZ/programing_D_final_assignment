#pragma once
//����map��ʹ��maps���й���
// �߼��ж��ڴ�ʵ��
//����洢���ŵ�ͼ����
#include <string>
#include<iostream>
#include<vector>
#include "houses.h"
#include "roads.h"
#include"lines.h"
#include "enum_lib.h"
#include<fstream>
#include <string>
class map {
public:
	//��maps��ʼ��ʱ�����·��˺���
	//����浵·����my_houses,��my_roads��my_lines�ڴ˳�ʼ��
	map(std::wstring path,const houses &my_house,const roads& my_roads,  int column,int row);

	
	//�������ݴ���mapData��ά����
	void read_file();
	
	//����mapData���������ղ��������뵱ǰ��������
	void write_file();
	
	//��Ⱦ��ͼ������roads��maps���е�draw�����������߼��жϺ��ͼ
	void draw(int width, int height, int x, int y);

	//��������ͷ���id(road id Ϊ0��
	void add_building(int x, int y, int house_type);

	// ��������(ɾ�����Ӻ͵�·��һ��������
	void delete_build(int x, int y);

	//���ظ����ĵ�ͼid�Ƿ񱻱༭��
	bool is_edited();

	//�ж������Ƶ�·�Ļ��������ֵ�·����
	int select_road_type(int i,int j);

	//�������أ����·��(����֮����չ)
	bool connect_houses(int house_type1, int house_type2);

	//�������·��(����֮����չ)
	void clear_connnect_houses();

	//��ʾ�����ͣ�ŵر�ͼ��������ķ�������
	void show_house_type(std::string& name,int x, int y);

	
private:
	//���������x��y����Ӧ�ĸ���(����һ�����鱣���������ֵ)
	void tranlate_xy(int* ans, int x, int y);

	//��¼(x,y)����Ӧ�ĸ��ӣ���ά�����е�׼ȷλ�ã�
	static int real_coord[2];

	//��������ڶ�ά�����еľ���λ��
	void get_position(int* ans, int house_type1, int house_type2);

	//������¼�����ڶ�ά���鵱�еľ���λ��
	static int position[4];

	//ͨ��my_houses��my_roads��my_lines�������������к�������
	const houses& my_houses;
	const roads& my_roads;

	//lines my_lines;
	//��ʱ���ܲ�ʹ��
	
	//�����洢��ǰ��ͼ������
	std::vector<std::vector<char>>mapData;

	//��ͼ��Ԫ������
	int column;
	//��ͼ��Ԫ������
	int row;

	//��ͼ����
	int height;
	int width;

	//�浵�ļ���·��
	std::wstring path;

	//bool���͵����������жϵ�·������
	bool is_edited(int page_id);

	//�Զ�̬string�����浱ǰѡ�н���������
	static std::string house_name;

	//����Building_num���������ڴ˵�ͼ���м�������
	int Building_num;
	
};