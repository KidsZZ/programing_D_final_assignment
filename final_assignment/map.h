#pragma once
//����map��ʹ��maps���й���
// �߼��ж��ڴ�ʵ��
//����洢���ŵ�ͼ����
#include <string>
#include<iostream>
#include "houses.h"
#include "roads.h"
#include "enum_lib.h"
#include<fstream>
#include <string>
class map {
public:
	//����浵·����houses
	map(std::wstring path,const houses &my_house,const roads& my_roads,int column,int row);
	void read_file();
	void write_file();
	void draw(int width, int height, int x, int y);

	//��������ͷ���id(road id Ϊ0��
	void add_building(int x, int y, int house_type);

	// ��������(ɾ�����Ӻ͵�·��һ�����������������û�ж����Ͳ��䣩
	void delete_build(int x, int y);

	//���ظ����ĵ�ͼid�Ƿ񱻱༭��
	bool is_edited(int page_id);
private:
	//���������x��y����Ӧ�ĸ���(����һ�����鱣���������ֵ)
	void tranlate_xy(int* ans, int x, int y);
	const houses& my_houses;
	const roads& my_roads;
	std::vector<std::vector<char>>mapData;
	//��ͼ����
	int column;
	int row;
	//�浵�ļ���·��
	std::wstring path;
	bool is_edited(int page_id);
};