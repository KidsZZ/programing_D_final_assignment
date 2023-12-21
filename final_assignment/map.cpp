//����map��ʹ��maps���й���
//����洢���ŵ�ͼ���ݣ���
#include"map.h"

class map {
public:
	//��ȡpath�ļ�·���е����ݣ�������houses��roads����������Ӧ������
	map(std::string path, const houses& my_houses, const roads& my_roads):my_houses(my_houses),my_roads(my_roads)
	{

		std::ifstream file(path);
		if (file.is_open())
		{
			//budong
			std::string line;
			//���ļ��ж�ȡÿһ�����ݲ��Ҵ���mapData��
			while (std::getline(file, line))
			{
				mapData.push_back(line);
			}
			file.close();
		}

	};
	//ʵ�ֻ�ͼ����
	void draw(int length, int x, int y)
	{
		//i���ڱ���ÿһ������
		for (int i = 0; i < mapData.size(); i++)
		{
			std::string row = mapData[i];
			//j���ڱ���i�е�ÿһλ����
			for (int j = 0; i < row.size(); j++)
			{
				
				if(row[i] == '0')
				{
					my_roads.draw(length, (x + j * length), (y + i * length), 1);
				}
				else if (row[j] == 'h')
				{
					my_houses.draw(length, (x + j * length), (y + i * length), 1);
				}
			}
	    }
	};
private:
	const houses& my_houses;
	const roads& my_roads;
	std::vector<std::string>mapData;

};