#include"map.h"
//����map��ʹ��maps���й���
// �߼��ж��ڴ�ʵ��
//����洢���ŵ�ͼ����

	//����浵·����houses
map::map (std::wstring path, const houses& my_house, const roads& my_roads, int column, int row)
	:my_houses(my_house), my_roads(my_roads),column(column),row(row),path(path), 
     mapData((row + 1), std::vector<char>(column, '-'))
{
	//�ȳ�ʼ��mapDate����
		
}

void map::read_file()
{
	mapData.clear();
	std::ifstream file(path);
	if (file.is_open())//����ļ��Ƿ��ܳɹ���
	{
		std::string line;
		std::getline(file ,line);
		//�ȶ�ȡ��һ�У����row��column�Ƿ��쳣
		std::vector<char>rows;
		for (char c : line)
		{
			//������ǿո�������ά���鵱��
			if (c != ' ')
			{
				rows.push_back(c);
			}
		}
		mapData.push_back(rows);
		if (mapData[0][1] != char(column) || mapData[0][0] != char(row))
		{
			std::cout << "Error" << std::endl;
		}

		while (std::getline(file, line))//���ж�ȡ����
		{
			std::vector<char>rows;
			for (char c : line)
			{
				if (c != ' ')//������ǿո�������ά���鵱��
				{
					rows.push_back(c);
				}
			}
			mapData.push_back(rows);
		}
		file.close();
	}
	else
	{
		std::cout << "�޷����ļ�" << std::endl;
	}
}


void map::write_file()
{
	std::ofstream file(path);
	if (file.is_open())
	{
		for (const auto& row : mapData)
		{
			for (const auto& ch : row)
			{
				file << ch << " ";
			}
			file << "\n";
		}
		file.close();
		std::cout << "�ļ�д��ɹ�" << std::endl;
	}
	else
	{
		//���׼�����豸���ʹ�����Ϣ��
		std::cerr << "�޷����ļ�" << std::endl;
	}

}
void map::draw(int width, int height, int x, int y)
{

}


//��������ͷ���id(road id Ϊ0��
void map::add_building(int x, int y, int house_type)
{

}

// ��������(ɾ�����Ӻ͵�·��һ�����������������û�ж����Ͳ��䣩
void map::delete_build(int x, int y)
{

}

//���ظ����ĵ�ͼid�Ƿ񱻱༭��
bool map::is_edited(int page_id)
{

}
