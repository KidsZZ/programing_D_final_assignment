#pragma once
//class maps ���ڹ���map�࣬������ͼ�浵�����ĵ�д��
//ʵ�ֵĵ�ͼΪ15��10��
#include"maps.h"


//����ͼ�浵����ȫ������һ���ļ����У��������ļ��е�·������path
//���캯�������������ļ�λ�ã�����read_file�����ͼ����
//��ʼ���б�
maps::maps(std::wstring path)
	:selected_map_id(0), my_houses(L"picture_hub/", 5), my_roads(L"picture_hub/", 11)
{
	my_map[selected_map_id] = new map(path,my_houses,my_roads,column,row);

}

//��ָ����ͼid�Ĵ浵�ļ��е����������ڴ�
void maps::read_file(int id)
{
	my_map[id]->read_file();
}

//���ص�ǰѡ��ĵ�ͼid
int maps::now_selected_map_id()
{

};

//���ĵ�ǰѡ��ĵ�ͼ
void maps::set_selected_map_id(int n)
{

};

//����ǰѡ��ĵ�ͼ����浵�ļ�
void maps::write_file() 
{

};

//����ָ��id�ĵ�ͼ
void maps::draw(int width, int height, int x, int y, int id) 
{

};

//���Ƶ�ǰѡ��ĵ�ͼ
void maps::draw_selected(int width, int height, int x, int y)
{
	draw( width,  height,  x,  y,  selected_map_id);
}



//��������������������selected_map_id
//���Ӷ���(����Ѿ����˾����
//��������ͷ���id(road id Ϊ0��
void add_building(int x, int y, int house_type) 
{

};
//��������
//ɾ������
// ��������(ɾ�����Ӻ͵�·��һ�����������������û�ж����Ͳ��䣩
void maps::delete_build(int x, int y) 
{

};

//�������أ����·��
bool maps::connect_houses(int house_type1, int house_type2) 
{

};

//�������·��
void maps::clear_connnect_houses() 
{

};

//���ظ����ĵ�ͼid�Ƿ񱻱༭��
bool maps::is_edited(int page_id) 
{

};

