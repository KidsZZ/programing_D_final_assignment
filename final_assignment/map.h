#pragma once
//����map��ʹ��maps���й���
//����洢���ŵ�ͼ���ݣ���
#include <string>
#include "houses.h"
#include "roads.h"
#include "enum_lib.h"
#include<fstream>
#include <string>
class map {
public:
	//����浵·����houses
	map(std::wstring path,const houses &my_house,const roads& my_roads);
	void draw(int width,int height, int x, int y);
	void read_file();
	void write_file();
private:
	//���������x��y����Ӧ�ĸ���(����һ�����鱣���������ֵ)
	void tranlate_xy(int* ans, int x, int y);
	const houses& my_houses;
	const roads& my_roads;
	std::vector<std::string>mapData;
	//��ͼ����
	int column;
	int row;
	//�浵�ļ���·��
	std::wstring path;
};