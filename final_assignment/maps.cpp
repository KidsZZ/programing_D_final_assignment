#pragma once
//class maps ���ڹ���map�࣬������ͼ�浵�����ĵ�д��
//ʵ�ֵĵ�ͼΪ15��10��
#include"maps.h"


//����ͼ�浵����ȫ������һ���ļ����У��������ļ��е�·������path
//���캯�������������ļ�λ�ã�����read_file�����ͼ����
//��ʼ���б�
maps::maps(std::wstring path)
	: m_houses1(L"picture_hub/", 5), m_roads1(L"picture_hub/", 11)
{
	//Ĭ�ϵ�ͼIDΪ0����������ͼ
	selected_map_id = 0;
	//����forѭ����ʼ�����ŵ�ͼ�����������ͼ����
	for (int i = 0; i < 4; i++)
	{
		//����new�������ݵ�ַ
		//ƴ�ӳ�ÿ�ŵ�ͼ��·�����ļ���
		//�ٴ��ݸ�map���캯��
		path1 = path + L"map"+std::to_wstring(i) + L".txt";
		m_map[i] = new map(path1, this->m_houses1, this->m_roads1,column, row);
		read_file(i);
	}

}

//��ָ����ͼid�Ĵ浵�ļ��е����������ڴ�
void maps::read_file(int id)
{
	//����map�����к���
	m_map[id]->read_file();
}

//����ǰѡ��ĵ�ͼ����浵�ļ�
void maps::write_file()
{
	//����map�����к���
	m_map[selected_map_id]->write_file();
}

//���ص�ǰѡ��ĵ�ͼid
int maps::now_selected_map_id()
{
	return selected_map_id;
}

//���ĵ�ǰѡ��ĵ�ͼ
void maps::set_selected_map_id(int n)
{
	selected_map_id = n;
}

//����ָ��id�ĵ�ͼ
void maps::draw(int width, int height, int x, int y, int id) 
{
	m_map[id]->draw(width, height, x,y);
}

//���Ƶ�ǰѡ��ĵ�ͼ
void maps::draw_selected(int width, int height, int x, int y)
{
	draw( width,  height,  x,  y,  selected_map_id);
}



//��������������������selected_map_id
//���Ӷ���(����Ѿ����˾����
//��������ͷ���id(road id Ϊ0��
void maps::add_building(int x, int y, int house_type) 
{
	m_map[selected_map_id]->add_building(x, y, house_type);

}

//��������
//ɾ������
// ��������(ɾ�����Ӻ͵�·��һ�����������������û�ж����Ͳ��䣩
void maps::delete_build(int x, int y,int house_type) 
{
	m_map[selected_map_id]->delete_build(x, y,house_type);

}

bool maps::connect_houses(int house_type1, int house_type2)
{
	return true;
}

//�������·��(����֮����չ)
void maps::clear_connnect_houses() 
{

}

//���ظ����ĵ�ͼid�Ƿ񱻱༭��(����֮����չ)
bool maps::is_edited(int page_id) 
{
	return m_map[page_id]->is_edited();
}


