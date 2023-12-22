#include"map.h"
//����map��ʹ��maps���й���
// �߼��ж��ڴ�ʵ��
//����洢���ŵ�ͼ����

	//����浵·����houses
map::map (std::wstring path, const houses& my_house, const roads& my_roads,  lines& my_lines,
	int column, int row,int width,int height)
	:my_houses(my_house), my_roads(my_roads),my_lines(my_lines),column(column),row(row),path(path), 
     mapData((row + 1), std::vector<char>(column, '-'))
{
	//�ȳ�ʼ��mapDate����
	this->height = height;
	this->width = width;
		
}

map::map(std::wstring path, const houses& my_house, const roads& my_roads, lines& my_lines, int column, int row)
	:my_houses(my_house), my_roads(my_roads),my_lines(my_lines)
{
	map(path, my_house, my_roads, my_lines, column, row, 0, 0);
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
		//�����Ƕ��������Ƿ��쳣���ж�
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
	file << row << " " << column << " " << char(1);
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
	if (j == 0)
	{
		if (mapData[i - 1][j] == '0' && (my_houses.house_orientation[(int)mapData[i - 1][j]][4]))
			road_type[0] = true;
		//���������Ϊ��ͼ�߽磬Ĭ��Ϊfalse
		if (mapData[i][j + 1] == '0' && (my_houses.house_orientation[(int)mapData[i][j + 1]][2]))
			road_type[2] = true;
		if (mapData[i + 1][j] == '0' && (my_houses.house_orientation[(int)mapData[i + 1][j]][4]))
			road_type[3] = true;
	}
	else
	{
		if (mapData[i - 1][j] == '0' && (my_houses.house_orientation[(int)mapData[i - 1][j]][4]))
			road_type[0] = true;
		if (mapData[i][j - 1] == '0' && (my_houses.house_orientation[(int)mapData[i][j - 1]][3]))
			road_type[1] = true;
		if (mapData[i][j + 1] == '0' && (my_houses.house_orientation[(int)mapData[i][j + 1]][2]))
			road_type[2] = true;
		if (mapData[i + 1][j] == '0' && (my_houses.house_orientation[(int)mapData[i + 1][j]][4]))
			road_type[3] = true;
		
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
	int length = (width / 15);

	for (int i = 1; i <= row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (mapData[i][j] != '0' && mapData[i][j] != '-')
			{
				my_houses.draw(length, (x+((i - 1) * length)), (y+(j * length)), (mapData[i][j] - '0'));
			}
			if (mapData[i][j] == '0')
			{
				my_roads.draw(length, (x + ((i - 1) * length)), (y + (j * length)), select_road_type(i, j));
			}
			else break;
		}
	}
	my_lines.draw(x, y);
}


//��������ͷ���id(road id Ϊ0��
void map::add_building(int x, int y, int house_type)
{
	//���ȼ����ʱ����λ����Ϣ��
	tranlate_xy(real_coord, x, y);
	//��Ϊ��һ�д�����ǵ�ͼ�����������Լ��Ƿ񱻸��ĵ�bool�������ڶ��п�ʼ�Ŵ洢��ͼ�ر�����
	mapData[real_coord[0]][real_coord[1]] = house_type;
}

// ��������(ɾ�����Ӻ͵�·��һ�����������������û�ж����Ͳ��䣩
void map::delete_build(int x, int y)
{
	//���ȼ����ʱ����λ����Ϣ��
	tranlate_xy(real_coord, x, y);
	//��Ϊ��һ�д�����ǵ�ͼ�����������Լ��Ƿ񱻸��ĵ�bool�������ڶ��п�ʼ�Ŵ洢��ͼ�ر�����
	mapData[real_coord[0]][real_coord[1]] = '-';
}

//���ظ����ĵ�ͼid�Ƿ񱻱༭��
bool map::is_edited(int page_id)
{
	bool is_change = (bool)mapData[0][2];
	return is_change;
}

//���������x��y����Ӧ�ĸ���(����һ�����鱣���������ֵ)
void map::tranlate_xy(int* ans, int x, int y)
{
	int length = height/ row;
	ans[0] = (x / length) + 1;
	ans[0] = y / length;
}
