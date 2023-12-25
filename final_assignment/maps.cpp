#pragma once
//class maps ���ڹ���map�࣬������ͼ�浵�����ĵ�д��
//ʵ�ֵĵ�ͼΪ15��10��
#include"maps.h"

//**�ڴ����ַʱ������txt�ļ�������string������ͼƬ������wstring


//����ͼ�浵����ȫ������һ���ļ����У��������ļ��е�·������path
//���캯�������������ļ�λ�ã�����read_file�����ͼ����
//��ʼ���б�
maps::maps(std::string path)
	: my_houses(L"picture_hub\\", 4), my_roads(L"picture_hub\\", 11)
{
	//�Ӵ����ļ��ж���֮ǰѡ��ĵ�ͼid
	selected_map_id = read_select_map_id();

	//����forѭ����ʼ�����ŵ�ͼ�����������ͼ����
	for (int i = 0; i < NUM; i++)
	{
		//����new�������ݵ�ַ
		//ƴ�ӳ�ÿ�ŵ�ͼ��·�����ļ���
		//�ٴ��ݸ�map���캯��
		this->path = path + "map"+std::to_string(i) + ".txt";
		my_maps[i] = new map(this->path, my_houses, my_roads, column, row);
	}

}

int maps::read_select_map_id() {
	std::ifstream map_id_file(path + "index.txt");
	int file_map_id;
	map_id_file >> file_map_id;
	map_id_file.close();
	return file_map_id;
}
//���ļ���д�뵱ǰѡ��ĵ�ͼid
void maps::write_select_map_id() {
	std::ofstream map_id_file;
	//��ԭ��ѡ���idɾ��
	map_id_file.open(path + "index.txt", std::ios::trunc);
	map_id_file << selected_map_id;
	map_id_file.close();
	return;
}

//��ָ����ͼid�Ĵ浵�ļ��е����������ڴ�
void maps::read_file(int id)
{
	//����map�����к���
	my_maps[id]->read_file();
}

//����ǰѡ��ĵ�ͼ����浵�ļ�
void maps::write_file()
{
	//����map�����к���
	my_maps[selected_map_id]->write_file();
}

//���ص�ǰѡ��ĵ�ͼid
int maps::now_selected_map_id()
{
	return selected_map_id;
}

//���ĵ�ǰѡ��ĵ�ͼ
void maps::set_selected_map_id(int id)
{
	selected_map_id = id;
}

//����ָ��id�ĵ�ͼ
void maps::draw(int width, int height, int x, int y, int id) 
{
	my_maps[id]->draw(width, height, x,y);
}

//���Ƶ�ǰѡ��ĵ�ͼ
//����draw����������selected_map_id
void maps::draw_selected(int width, int height, int x, int y)
{
	draw(width, height, x, y, selected_map_id);
}



//��������������������selected_map_id
//���Ӷ���(����Ѿ����˾����
//��������ͷ���id(road id Ϊ0��
void maps::add_building(int x, int y, int house_type) 
{
	my_maps[selected_map_id]->add_building(x, y, house_type);

}

//��������
//ɾ������
// ��������(ɾ�����Ӻ͵�·��һ�����������������û�ж����Ͳ��䣩
void maps::delete_build(int x, int y) 
{
	my_maps[selected_map_id]->delete_build(x, y);

}

//�����û�ѡ������������ĵ���
bool maps::connect_houses(int house_type1, int house_type2)
{
	return my_maps[selected_map_id]->connect_houses(house_type1, house_type2);
}

//�������·��
void maps::clear_connnect_houses() 
{
	my_maps[selected_map_id]->clear_connect_houses();
}

//���ظ����ĵ�ͼid�Ƿ񱻱༭��
bool maps::is_edited(int page_id) 
{
	return my_maps[page_id]->is_edited();
}


//���Ƹ����ߣ������û����ý���
//������ǰ�������꣬��ѡ��ĵ�ͼ�ϻ��Ƴ����ý����ĸ�����
void maps::draw_dashed_line(int x, int y)
{
	my_maps[selected_map_id]->draw_dashed_line(x, y);
}

//��������
maps::~maps() {
	//���������д���û�ѡ��ĵ�ͼid
	write_select_map_id();

	//�ͷ�map����
	delete[] my_maps;
}
