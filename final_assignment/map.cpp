//����map��ʹ��maps���й���
//����洢���ŵ�ͼ���ݣ���
#include"map.h"


//��ȡpath�ļ�·���е����ݣ�������houses��roads����������Ӧ������
map::map(std::wstring path, const houses& my_houses, const roads& my_roads):my_houses(my_houses),my_roads(my_roads)
{
	/*
	std::ifstream file(path);
	if (file.is_open())
	{
		//����string��ʱ����line
		std::string line;
		//���ļ��ж�ȡÿһ�����ݲ��Ҵ���mapData��
		while (std::getline(file, line))
		{
			mapData.push_back(line);
		}
		file.close();
	}
	*/
};

//ʵ�ֻ�ͼ����
void map::draw(int length, int x, int y)
{
	
};
