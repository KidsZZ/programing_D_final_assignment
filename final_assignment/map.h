#pragma once
//����map��ʹ��maps���й���
// �߼��ж��ڴ�ʵ��
//����洢���ŵ�ͼ����
#include <string>
#include<iostream>
#include "houses.h"
#include "roads.h"
#include"lines.h"
#include "enum_lib.h"
#include<fstream>
#include <string>
class map {
public:
	friend maps;
	//����浵·����houses
	map(std::wstring path,const houses &my_house,const roads& my_roads, lines& my_lines, int column,int row, int width, int height);
	//��maps��ʼ��ʱ�����·��˺���
	map(std::wstring path, const houses& my_house, const roads& my_roads,  lines& my_lines, int column, int row);
	void read_file();
	void write_file();
	void draw(int width, int height, int x, int y);

	//��������ͷ���id(road id Ϊ0��
	void add_building(int x, int y, int house_type);

	// ��������(ɾ�����Ӻ͵�·��һ��������
	void delete_build(int x, int y);

	//���ظ����ĵ�ͼid�Ƿ񱻱༭��
	bool is_edited(int page_id);

	//�ж������Ƶ�·�Ļ��������ֵ�·����
	int select_road_type(int i,int j);
	
private:
	//���������x��y����Ӧ�ĸ���(����һ�����鱣���������ֵ)
	void tranlate_xy(int* ans, int x, int y);
	const houses& my_houses;
	const roads& my_roads;
	lines& my_lines;
	std::vector<std::vector<char>>mapData;
	//��ͼ����
	int column;
	int row;
	//��ͼ����
	int height;
	int width;
	//�浵�ļ���·��
	std::wstring path;
	//bool���͵����������жϵ�·������
	bool is_edited(int page_id);
	//��¼(x,y)����Ӧ�ĸ���
	static int real_coord[2];
};