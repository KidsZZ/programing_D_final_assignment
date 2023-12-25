//class maps ���ڹ���map�࣬������ͼ�浵�����ĵ�д��
//ʵ�ֵĵ�ͼΪ15��10��

#pragma once
#include <string>
#include "map.h"
class maps 
{
public:
	//���캯��
	// ����ͼ�浵����ȫ������һ���ļ����У��������ļ��е�·������path
	//���������ļ�λ�ã�����read_file�����ͼ����
	maps(std::string path);//��ʼ���б�

	//��ָ����ͼid�Ĵ浵�ļ��е����������ڴ�
	void read_file(int id);

	//���ص�ǰѡ��ĵ�ͼid
	int now_selected_map_id();

	//���ĵ�ǰѡ��ĵ�ͼ
	void set_selected_map_id(int id);

	//����ǰѡ��ĵ�ͼ����浵�ļ�
	void write_file();

	//����ָ��id�ĵ�ͼ
	void draw(int width,int height, int x, int y, int id);

	//���Ƶ�ǰѡ��ĵ�ͼ
	void draw_selected(int width,int height, int x, int y);

	//��������������������selected_map_id
	//���Ӷ���(����Ѿ����˾����
	//��������ͷ���id(road id Ϊ0��
	//�����ӵĻ���enum.lib�е�ӳ���Ӧ
	void add_building(int x, int y, int house_type);

	//��������
	//ɾ������
	// ��������ɾ�����Ӻ͵�·��һ��������
	void delete_build(int x, int y);


	//�������أ����·��(����֮����չ)
	bool connect_houses(int house_type1, int house_type2);

	//�������·��(����֮����չ)
	void clear_connnect_houses();

	//���ظ����ĵ�ͼid�Ƿ񱻱༭��
	bool is_edited(int page_id);

	//���Ƹ����ߣ������û����ý���
	//(x,y)Ϊ���Ƶ�ͼ�ĵ����Ͻǣ�����λ����Ϊ��ͼ�Ŀ�Ⱥͳ���
	void draw_dashed_line(int x, int y);

	//��������
	~maps();

private:

	//��ȡ�����б����֮ǰѡ��ĵ�ͼid
	int read_select_map_id();

	//�������д�뵱ǰѡ��ĵ�ͼid
	void write_select_map_id();

	//Ŀǰ��ͼ�����ţ����Խ�NUM��Ϊ4�����Ժ��ڸ���
	const static int NUM = 4;

	//�����ͼ��ţ�ֻ�и��ĵ�ǰѡ���ͼ�Ż��������ID����
	//ÿ�β���ǰ��Ҫȷ����ʱ��id
	int selected_map_id;

	//��ŵ�ͼ���ݵ��ļ���λ��
	std::string path;

	//����map*ָ�����ڵ���map�з�װ�ĺ���
	map* my_maps[NUM];

	//����roads�������ڵ���roads�з�װ�ĺ���
	roads my_roads;

	//����houses�������ڵ���houses�з�װ�ĺ���
	houses my_houses;

	//����lines�������ڵ���lines�з�װ�ĺ���
	
	// ֮�����ڻ��Ƹ�����
	//lines my_lines
	//
	//ÿ����ͼ15�У�10��
	const  int column = 15;
	const  int row = 10;
};