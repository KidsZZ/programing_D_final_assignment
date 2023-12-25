#include"map.h"
//����map��ʹ��maps���й���
// �߼��ж��ڴ�ʵ��
//����洢���ŵ�ͼ����

//����浵·����houses

map::map(std::string path, houses& my_house, roads& my_roads,
	int column, int row)
	:my_houses(my_house), my_roads(my_roads), path(path),
	//��Ϊ��û�л��Ƶ�ͼ�����Խ�width,height,x,y������Ϊ-1
	height(-1), width(-1), x(-1), y(-1),
	//����¼��굱ǰ����λ�õı�����¼Ϊ-1�������Ƹ�����
	mouse_now_abstract_x(-1),mouse_now_abstract_y(-1)
{	
	//�ȳ�ʼ��mapDate����
	this->column = column;
	this->row = row;

	for (int i = 0; i < 2; i++)real_coord[i] = -1;

	//��ʼ������building_numΪ0
	building_num = 0;

	for (int i = 0; i < 5; i++) {
		//��ʼ������������Ϊ������
		is_building_present[i] = false;
	}

	//ʹ��path�ҵ�����������еĴ浵�ļ�
	read_file();
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
		// �ж��ļ���С�Ƿ�Ϊ0,���ļ��Ƿ�Ϊ���ļ�
		if (file.tellg() == 0)//�ǿ��ļ�
		{
			//��mapData���г�ʼ������
			//��ȫ����ռλ�������
			std::vector<std::vector<char>> mapData_temp((row), std::vector<char>(column, '-'));
			mapData = mapData_temp;
		}

		else
		{
			//�ȶ�ȡ��һ�У����row��column�Ƿ��쳣
			std::string line;
			std::vector<char>rows;
			std::getline(file, line);

			for (char c : line)
			{
				//������ǿո�����ʱ����rows����
				if (c != ' ')
				{
					rows.push_back(c);
				}
			}

			//�����Ƕ��������Ƿ��쳣���ж�
			//������ļ��м�¼�ĵ�Ԫ�������͵�Ԫ���������봫�������ͬ�򱨴�
			if (int(rows[0]) != (row+'0') || int(rows[1]) != (column+'0'))
			{
				std::cout << "Error the row or column is erroneous" << std::endl;
				return;
			}

			//���string
			line.clear();
			//���vector
			rows.clear();

			//���ж�ȡ����
			while (std::getline(file, line))
			{
				for (char c : line)
				{
					//������ǿո�������ά���鵱��
					if (c != ' ')
					{
						rows.push_back(c);
					}
				}

				//ʵ���˴��ļ��ڶ��п�ʼ�������ݣ�����mapData����
				//��row2����ѹ��mapData����
				mapData.push_back(rows);
				rows.clear();
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
				building_num++;
				is_building_present[(mapData[i][j] - '0')] = true;
				building_position[(mapData[i][j] - '0')][0] = i;
				building_position[(mapData[i][j] - '0')][1] = j;
			}
		}
	}
	
}


void map::write_file()
{
	//��ʼ�����캯��	  ��ȡfile�ļ����ڵ�λ��
	std::ofstream file(path,std::ios::trunc);
	//��һ�ŷ��õ�һ������������
	file << row << ' ' << column << ' ' << building_num<<std::endl;
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

	//ͨ������ж�������ҵ���Ӧ��ͼƬ
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


//draw��������˳��
//0.���浱ǰ���Ƶ�ͼ������
//1.���Ƶ�ͼ����
//2.���Ƶ�ǰ���ѡ������
//3.���Ƶ�ͼ������
//4.���ƽ���
//5.���Ƶ�·
void map::draw(int width, int height, int x, int y)
{
	//����ÿ��ı߳�
	length = (width / column);

	//�������һ�λ��Ƶ�ͼ�ĳ�����translate_xyʹ��
	this->width = width;
	this->height = height;

	//�������һ�λ��Ƶ�ͼ�����꣬��translate_xyʹ��
	this->x = x;
	this->y = y;

	//�ڵ�ͼ������Ʊ�������ֹ������
	setfillcolor(0xb4e014);
	rectangle(x, y, x + width, y + height);

	//�������ѡ������
	//������ڵ�ͼ��
	if (mouse_now_abstract_x != -1 && mouse_now_abstract_y != -1) {
		//����column�ϵı��
		rectangle(x + mouse_now_abstract_x * length, y, x + (mouse_now_abstract_x + 1) * length, y + height);
		//����row�ϵı��
		rectangle(x, y + mouse_now_abstract_y * length, x + width, y + (mouse_now_abstract_y + 1));
	}

	//���Ƹ��Ӽ����
	draw_subline();
	
	//ͨ�����������е�������ֱ����roads��houses���Ƶ�ͼ
	for (int i =0; i <row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (mapData[i][j] != '0' && mapData[i][j] != '-')
			{
				my_houses.draw(length, (x+(i  * length)), (y+(j * length)), (mapData[i][j] - '0'));
			}
			else if (mapData[i][j] == '0')
			{
				//�ڻ��Ƶ�·��ʱ����Ҫ����select_road_type��֪��·����
				my_roads.draw(length, (x + (i  * length)), (y + (j * length)), select_road_type(i, j));
			}
		}
	}


}


//��������ͷ���id(road id Ϊ0��
void map::add_building(int x, int y, int house_type)
{

	//���ȼ����ʱ����λ����Ϣ��
	translate_xy(real_coord, x, y);
	
	//����ǰ���ཨ��û�б�����ʱ��������ý���
	if (!is_building_present[house_type]) {
		mapData[real_coord[0]][real_coord[1]] = house_type;
		//�õ�ͼ������+1
		building_num++;

		//��¼��������
		building_position[house_type][0] = x;
		building_position[house_type][1] = y;
	}
}

// ��������(ɾ�����Ӻ͵�·��һ�����������������û�ж����Ͳ��䣩
void map::delete_build(int x, int y)
{
	//���ȼ����ʱ����λ����Ϣ��
	translate_xy(real_coord, x, y);
	
	//�����Ϊռλ������ɾ����λ�ý���
	if (mapData[real_coord[0]][real_coord[1]] != '-') {
		//�����Ϊ��·���������ر��
		if (mapData[real_coord[0]][real_coord[1]] != '0') {
			int house_type = mapData[real_coord[0]][real_coord[1]] - '0';
			is_building_present[house_type] = false;
			building_position[house_type][0] = -1;
			building_position[house_type][1] = -1;
			//������-1
			building_num--;
		}
		//��������Ϊ��-��
		mapData[real_coord[0]][real_coord[1]] = '-';
	}

}

//���ظ����ĵ�ͼid�Ƿ񱻱༭��
bool map::is_edited()
{
	if (building_num == 0) {
		return false;
	}
	else
	{
		return true;
	}
}

//���������x��y����Ӧ�ĸ���(����һ�����鱣���������ֵ)
bool map::translate_xy(int* ans, int x, int y)
{
	//��û�л��Ƶ�ͼ��ʱ��
	if (this->x == -1 && this->y == -1 && width == -1 && height == -1) {
		return false;
	}
	//�������ĵ��ڵ�ͼ�ϵ�ʱ��
	if (x > this->x && x<(this->x + width) && y>this->y && (y < this->y + height)) {
		
		//�����߼�ֵ
		ans[0] = (x - this->x) / length;
		ans[1] = (y - this->y) / length;

		//�ڵ�ͼ�ϣ�true
		return true;

	}else {

		//������ڵ�ͼ�ϣ���false
		return false;
	}
}


//��ʾ�����ͣ�ŵر�ͼ��������ķ�������
void map::show_house_type(std::string& name,int x, int y)
{
	translate_xy(real_coord, x, y);
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

//�������߸����ߺ����ĸ�������
//�˺���������Ƿ��ڰ�ť�ϵĺ������ƣ��������λ���ж��Ƿ���Ҫ���Ƽ�����������
void map::draw_dashed_line(int x,int y)
{
	if (!translate_xy(real_coord, x, y)) {
		//������ڵ�ͼ��
		mouse_now_abstract_x = -1;
		mouse_now_abstract_y = -1;
	}
	else {
		//����ǰ����λ�ü�¼����������draw�����л���
		mouse_now_abstract_x = real_coord[0];
		mouse_now_abstract_y = real_coord[1];
	}

}

//���Ƹ����ߣ������û����ý���
//(x,y)Ϊ���Ƶ�ͼ�ĵ����Ͻǣ�����λ����Ϊ��ͼ�Ŀ�Ⱥͳ���
void map::draw_subline()
{
	//����forѭ����������
	for (int i = 0; i <= column;i++)
	{
		line(x + i * length, y, x + i * length, y + height);
	}
	//����forѭ�����ƺ���
	for (int j = 0; j <= row; j++)
	{
		line(x, y + length * j, x + width, y + length * j);
	}
}





//�������أ����·��(����֮����չ)
bool map::connect_houses(int house_type1, int house_type2){

}

//�������·��(����֮����չ)
void clear_connnect_houses(){}

