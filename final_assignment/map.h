#pragma once
//����map��ʹ��maps���й���
// �߼��ж��ڴ�ʵ��
//����洢���ŵ�ͼ����
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include "houses.h"
#include "roads.h"
#include "lines.h"
#include "enum_lib.h"
class map 
{
public:

	//��maps��ʼ��ʱ�����·��˺���
	//����浵·����my_houses,��my_roads�ڴ˳�ʼ��
	map(std::string path, houses& my_house, roads& my_roads, int column, int row);

	//�������ݴ���mapData��ά����
	// ��������ļ�������Ҳ������һ���ж��Ƿ�ƥ��
	//������maps�����˵�ͼ�������Զ�������ʱ����׼ȷ
	void read_file();
	
	//����д����ŵ�ͼ��row��column
	//�����д������ڵ�map.txt�ļ�
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
	void show_house_type(std::string& name, int x, int y);

	//�������߸����ߣ������û����ý���
    //(x,y)Ϊ���Ƶ�ͼ�ĵ����Ͻǣ�����λ����Ϊ��ͼ�Ŀ�Ⱥͳ���
	void draw_subline();

	//�������߸����ߺ����ĸ�������
	void draw_dashed_line(int x,int y);
private:
	//���������x��y����Ӧ�ĸ���(����һ�����鱣���������ֵ)
	bool translate_xy(int *ans, int x, int y);

	//��¼(x,y)����Ӧ�ĸ��ӣ���ά�����е�׼ȷλ�ã�
	int real_coord[2];


	//ͨ��my_houses��my_roads�������������к�������
	houses my_houses;
	roads my_roads;

	//lines my_lines;
	//��ʱ���ܲ�ʹ��,�������ڻ��Ƹ�����
	
	//�����洢��ǰ��ͼ������
	//ʹ��char�洢
	//-��ռλ����0Ϊ��·����������Ϊ����
	std::vector<std::vector<char>>mapData;

	//��ͼ��Ԫ������
	int column;
	//��ͼ��Ԫ������
	int row;

	//�������һ�λ��Ƶ�ͼʱ�ĵ�ͼ��������꣬�����������ͼ�и��ӵ�����ʹ��
	int height,width;
	int x, y;

	//�浵�ļ���·��
	std::string path;


	//�Զ�̬string�����浱ǰѡ�н���������
	static std::string house_name;

	//��building_num���������ڴ˵�ͼ���м�������
	int building_num;

	//��building_position��ά�������洢ÿ�����ݵĺ�������
	//��1��ʼ��һֱ��4����enum.lib���趨��ͬ������Ӧ��
	int building_position[5][2];
	//����ÿ�������Ƿ񶼱����ã����ڲ���
	bool is_building_present[5];
	
	//��length������ÿ��ı߳�
	int length;

	//��굱ǰ���ڵ��߼����꣨ȫΪ-1�����ڵ�ͼ�ϣ�
	// ���ڸ����������ѡ������
	//��ʼ��Ϊ-1����������draw_dashed_line����ֵʱ��Զ������Ƹ�����
	int mouse_now_abstract_x;
	int mouse_now_abstract_y;
};