#include"map.h"
//����map��ʹ��maps���й���
// �߼��ж��ڴ�ʵ��
//����洢���ŵ�ͼ����

//����浵·����houses

map::map(std::wstring path, houses& my_house, roads& my_roads, 
	int column, int row)
	:my_houses(my_house), my_roads(my_roads), path(path)
{
	//�ȳ�ʼ��mapDate����
	this->column = column;
	this->row = row;
	for (int i = 0; i < 2; i++)real_coord[i] = 0;
	Building_num = 0;
	if (is_edited())
	{
		mapData.clear();
		read_file();
	}	
}



void map::read_file()
{
	//�����ͼ·��
	std::ifstream file(path); 
	// �ж��ļ��Ƿ�ɹ���
	if (file.is_open())
	{
		// ��λ���ļ�ĩβ
		file.seekg(0, std::ios::end);
		// �ж��ļ���С�Ƿ�Ϊ0
		if (file.tellg() == 0)
		{
			//��mapData���г�ʼ������
			//��ȫ����ռλ�������
			std::vector<std::vector<char>> mapData_temp((row), std::vector<char>(column, '-'));
			mapData = mapData_temp;
		}

		else
		{
			//�ȶ�ȡ��һ�У����row��column�Ƿ��쳣
			std::string line1;
			std::vector<char>rows1;
			std::getline(file, line1);

			for (char c : line1)
			{
				//������ǿո�����ʱ����rows����
				if (c != ' ')
				{
					rows1.push_back(c);
				}
			}

			//�����Ƕ��������Ƿ��쳣���ж�
			//������ļ��м�¼�ĵ�Ԫ�������͵�Ԫ���������봫�������ͬ�򱨴�
			if (rows1[0] != char(row) || rows1[1] != char(column))
			{
				std::cout << "Error" << std::endl;
				return;
			}

			std::string line2;
			//���ж�ȡ����
			while (std::getline(file, line2))
			{
				std::vector<char>rows2;
				int lineNumber = 0;
				for (char c : line2)
				{
					//������ǿո�������ά���鵱��
					if (c != ' ')
					{
						rows2.push_back(c);
					}
				}

				//ʵ���˴��ļ��ڶ��п�ʼ�������ݣ�����mapData����
				if (lineNumber > 1)
				{
					//��row2����ѹ��mapData����
					mapData.push_back(rows2);
				}
			}

		}
		file.close(); // �ر��ļ�
	}

	else 
	{
		std::cout << "�޷���ָ���ļ�" << std::endl;
	}

	//���е�ǰ��ͼ����������ʼ���Ĳ���
	//��ȡ��ά�����е������ж��Ƿ�Ϊ�������ͣ����ǣ���Building_num++
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (mapData[i][j] != '-' || mapData[i][j] != '0')
			{
				Building_num++;
			}
		}
	}
	
}


void map::write_file()
{
	//��ʼ�����캯��	  ��ȡfile�ļ����ڵ�λ��
	std::ofstream file(path);
	file << row << " " << column << " " ;
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
		//���׼�����豸���ʹ�����Ϣ��������ʾ������Ϣ�����
		std::cerr << "�޷����ļ�" << std::endl;
	}

}


//�ж������Ƶ�·�Ļ��������ֵ�·����
int map::select_road_type(int i,int j)
{
	//���ȴ���һ��bool���͵�vector�������洢�˵�·���������ĸ��������Ϣ
	std::vector<bool>road_type(4, false);
	if (j == 0 && i != 0 && i != row)
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(4, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		//���������Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i][j + 1] == '0' ||
			((mapData[i][j + 1] != '-' && my_houses.is_door(2, mapData[i][j + 1]))))
		{
			road_type[2] = true;
		}

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(1, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	if (i == 0 && j != 0 && j != column)
	{
		//�������ϲ�Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(3, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		if (mapData[i][j + 1] == '0' ||
			((mapData[i][j + 1] != '-' && my_houses.is_door(2, mapData[i][j + 1]))))
		{
			road_type[2] = true;
		}

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(1, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	if (j == column && i != 0 && i != row)
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(4, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(3, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		//�������Ҳ�Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(1, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	if (i == row && j != 0 && j != column)
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(4, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(3, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		if (mapData[i][j + 1] == '0' ||
			((mapData[i][j + 1] != '-' && my_houses.is_door(2, mapData[i][j + 1]))))
		{
			road_type[2] = true;
		}

		//�������²�Ϊ��ͼ�߽磬Ĭ��Ϊfalse
	}

	if (i == 0 && j == 0)
	{
		//����||��·�����ʣ������߼�����
		//�������ϲ�Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		//���������Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i][j + 1] == '0' ||
			((mapData[i][j + 1] != '-' && my_houses.is_door(2, mapData[i][j + 1]))))
		{
			road_type[2] = true;
		}

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(1, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	if (i == 0 && j == column)
	{
		//����||��·�����ʣ������߼�����
		//�������ϲ�Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(3, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		//�������Ҳ�Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(1, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	if (i == row && j == 0)
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(4, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		//���������Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i][j + 1] == '0' ||
			((mapData[i][j + 1] != '-' && my_houses.is_door(2, mapData[i][j + 1]))))
		{
			road_type[2] = true;
		}

		//�������²�Ϊ��ͼ�߽磬Ĭ��Ϊfalse
	}

	if (i == row && j == column)
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(4, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(3, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		//�������Ҳ�Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		//�������²�Ϊ��ͼ�߽磬Ĭ��Ϊfalse
	}

	if((i>0&&i<row)&&(j>0&&j<column))
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(4, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(3, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		if (mapData[i][j + 1] == '0' ||
			((mapData[i][j + 1] != '-' && my_houses.is_door(2, mapData[i][j + 1]))))
		{
			road_type[2] = true;
		}

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(1, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	if (road_type[0] == 1 && road_type[1] == 1 && road_type[2] == 0 && road_type[3] == 0) {
		return 1;
	}
	if (road_type[0] == 1 && road_type[1] == 0 && road_type[2] == 1 && road_type[3] == 0) {
		return 2;
	}
	if (road_type[0] == 1 && road_type[1] == 0 && road_type[2] == 0 && road_type[3] == 1) {
		return 3;
	}
	if (road_type[0] == 0 && road_type[1] == 1 && road_type[2] == 1 && road_type[3] == 0) {
		return 4;
	}
	if (road_type[0] == 0 && road_type[1] == 1 && road_type[2] == 0 && road_type[3] == 1) {
		return 5;
	}
	if (road_type[0] == 0 && road_type[1] == 0 && road_type[2] == 1 && road_type[3] == 1) {
		return 6;
	}
	if (road_type[0] == 0 && road_type[1] == 1 && road_type[2] == 1 && road_type[3] == 1) {
		return 7;
	}
	if (road_type[0] == 1 && road_type[1] == 0 && road_type[2] == 1 && road_type[3] == 1) {
		return 8;
	}
	if (road_type[0] == 1 && road_type[1] == 1 && road_type[2] == 0 && road_type[3] == 1) {
		return 9;
	}
	if (road_type[0] == 1 && road_type[1] == 1 && road_type[2] == 1 && road_type[3] == 0) {
		return 10;
	}
	if (road_type[0] == 1 && road_type[1] == 1 && road_type[2] == 1 && road_type[3] == 1) {
		return 11;
	}
}

void map::draw(int width, int height, int x, int y)
{
	//����ÿ��ı߳�
	length = (width / 15);

	for (int i =0; i <width; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (mapData[i][j] != '0' && mapData[i][j] != '-')
			{
				my_houses.draw(length, (x+(i  * length)), (y+(j * length)), (mapData[i][j] - '0'));
			}
			if (mapData[i][j] == '0')
			{
				my_roads.draw(length, (x + (i  * length)), (y + (j * length)), select_road_type(i, j));
			}
			else break;
		}
	}


}


//��������ͷ���id(road id Ϊ0��
void map::add_building(int x, int y, int house_type)
{

	//���ȼ����ʱ����λ����Ϣ��
	tranlate_xy(real_coord, x, y);

	//��Ϊ��һ�д�����ǵ�ͼ�����������Լ��Ƿ񱻸��ĵ�bool�������ڶ��п�ʼ�Ŵ洢��ͼ�ر�����
	mapData[real_coord[0]][real_coord[1]] = house_type;
	//�õ�ͼ������+1
	Building_num++;
	//��¼��������
	position_array[house_type][0] = x;
	position_array[house_type][1] = y;
}

// ��������(ɾ�����Ӻ͵�·��һ�����������������û�ж����Ͳ��䣩
void map::delete_build(int x, int y,int house_type)
{
	//���ȼ����ʱ����λ����Ϣ��
	tranlate_xy(real_coord, x, y);
	//��������Ϊ��-��
	mapData[real_coord[0]][real_coord[1]] = '-';
	//������-1
	Building_num--;
	//��ֹ�����
	if (Building_num < 0)Building_num = 0;
	//���÷�������
	position_array[house_type][0] = -1;
	position_array[house_type][1] = -1;

}

//���ظ����ĵ�ͼid�Ƿ񱻱༭��
bool map::is_edited()
{
	if (Building_num == 0)
		return false;
	else
	{
		return true;
	}
}

//���������x��y����Ӧ�ĸ���(����һ�����鱣���������ֵ)
void map::tranlate_xy(int* ans, int x, int y)
{
	int length = height/ row;
	ans[0] = (x / length);
	ans[0] = y / length;
}


//������¼�����ڶ�ά���鵱�еľ���λ��
void map::get_position(int* ans, int house_type1, int house_type2)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if ((mapData[i][j] - '0') == house_type1)
			{
				position[0] = i;

				position[1] = j;
			}
			if ((mapData[i][j] - '0') == house_type2)
			{
				position[2] = i;
				position[3] = j;
			}
		}
	}
}


//��ʾ�����ͣ�ŵر�ͼ��������ķ�������
void map::show_house_type(std::string& name,int x, int y)
{
	tranlate_xy(real_coord, x, y);
	int indexX = real_coord[0];
	int indexY = real_coord[1];
	int house_type = mapData[indexX][indexY]-'0';

	switch (house_type)
	{
	case 1:
		name = "library";
		break;
	case 2:
		name = "dormitory";
		break;
	case 3:
		name = "teaching_building";
		break;
	case 4:
		name = "canteen";
		break;
	default:
		break;
	}
}







//�������أ����·��(����֮����չ)
//bool map::connect_houses(int house_type1, int house_type2){}

//�������·��(����֮����չ)
//void clear_connnect_houses(){}

