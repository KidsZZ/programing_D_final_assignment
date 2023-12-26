#include"map.h"
#include <iostream>
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

	//��mapData���г�ʼ������
	//��ȫ����ռλ�������
	std::vector<std::vector<char>> mapData_temp(row, std::vector<char>(column, '-'));
	mapData = mapData_temp;

	//ʹ��path�ҵ�����������еĴ浵�ļ�
	read_file();

	//��ʼ��Ϊ��Ҫ����
	is_navigation = false;

	//����ʼ����·��ȫ��Ϊfalse
	std::vector<std::vector<bool>> mapNavigation_temp(row, std::vector<bool>(column, false));
	mapNavigation = mapNavigation_temp;
}


//���ļ���ͷ��һ�п��У�һ�����з����������ж��ļ��Ƿ��ǿ��ļ�
void map::read_file()
{
	//�����ͼ·��
	std::ifstream file(path); 
	// �ж��ļ��Ƿ�ɹ���
	if (file.is_open())
	{
		// ��λ���ļ�ĩβ
		char temp_c;
		file >> temp_c;
		// �ж��ļ���С�Ƿ�Ϊ0,���ļ��Ƿ�Ϊ���ļ�
		if (file.eof())//�ǿ��ļ�
		{
			//�����д���
		}

		else
		{
			//�ȶ�ȡ��һ�У����row��column�Ƿ��쳣
			int fileRow, fileColumn;
			file >> fileRow >> fileColumn;

			//�����Ƕ��������Ƿ��쳣���ж�
			//������ļ��м�¼�ĵ�Ԫ�������͵�Ԫ���������봫�������ͬ�򱨴�
			if (fileRow != row || fileColumn != column)
			{
				std::cout << "Error the row or column is erroneous" << std::endl;
				return;
			}
			char tempc;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					file >> tempc;
					if (tempc != '-') {
						mapData[i][j] = tempc;
					}
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
			if (mapData[i][j] != '-' && mapData[i][j] != '0')
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
	//��һ�з�һ��0
	file << '0' << std::endl;
	//�ڶ��ŷ�������������
	file << row << ' ' << column <<std::endl;
	//���������õ�ͼ����
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
	//printf("select_road_type init!\n");
	//���ȴ���һ��bool���͵�vector�������洢�˵�·���������ĸ��������Ϣ
	std::vector<bool>road_type(4, false);
	if (j == 0 && i != 0 && i != row-1)
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(direction::down, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		//���������Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i][j + 1] == '0' ||
			((mapData[i][j + 1] != '-' && my_houses.is_door(direction::left, mapData[i][j + 1]))))
		{
			road_type[2] = true;
		}

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(direction::up, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	if (i == 0 && j != 0 && j != column-1)
	{
		//�������ϲ�Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(direction::right, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		if (mapData[i][j + 1] == '0' ||
			((mapData[i][j + 1] != '-' && my_houses.is_door(direction::left, mapData[i][j + 1]))))
		{
			road_type[2] = true;
		}

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(direction::up, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	if (j == column-1 && i != 0 && i != row-1)
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(direction::down, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(direction::right, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		//�������Ҳ�Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(direction::up, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	if (i == row-1 && j != 0 && j != column-1)
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(direction::down, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(direction::right, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		if (mapData[i][j + 1] == '0' ||
			((mapData[i][j + 1] != '-' && my_houses.is_door(direction::left, mapData[i][j + 1]))))
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
			((mapData[i][j + 1] != '-' && my_houses.is_door(direction::left, mapData[i][j + 1]))))
		{
			road_type[2] = true;
		}

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(direction::up, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	if (i == 0 && j == column-1)
	{
		//����||��·�����ʣ������߼�����
		//�������ϲ�Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(direction::right, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		//�������Ҳ�Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(direction::up, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	if (i == row-1 && j == 0)
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(direction::down, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		//���������Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		if (mapData[i][j + 1] == '0' ||
			((mapData[i][j + 1] != '-' && my_houses.is_door(direction::left, mapData[i][j + 1]))))
		{
			road_type[2] = true;
		}

		//�������²�Ϊ��ͼ�߽磬Ĭ��Ϊfalse
	}

	if (i == row-1 && j == column-1)
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(direction::down, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(direction::right, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		//�������Ҳ�Ϊ��ͼ�߽磬Ĭ��Ϊfalse

		//�������²�Ϊ��ͼ�߽磬Ĭ��Ϊfalse
	}

	if((i>0&&i<row-1)&&(j>0&&j<column-1))
	{
		//����||��·�����ʣ������߼�����
		if (mapData[i - 1][j] == '0' ||
			((mapData[i - 1][j] != '-' && my_houses.is_door(direction::down, mapData[i - 1][j]))))
		{
			road_type[0] = true;
		}

		if (mapData[i][j - 1] == '0' ||
			((mapData[i][j - 1] != '-' && my_houses.is_door(direction::right, mapData[i][j - 1]))))
		{
			road_type[1] = true;
		}

		if (mapData[i][j + 1] == '0' ||
			((mapData[i][j + 1] != '-' && my_houses.is_door(direction::left, mapData[i][j + 1]))))
		{
			road_type[2] = true;
		}

		if (mapData[i + 1][j] == '0' ||
			((mapData[i + 1][j] != '-' && my_houses.is_door(direction::up, mapData[i + 1][j]))))
		{
			road_type[3] = true;
		}
	}

	//û��true��Ĭ��up_down
	if (road_type[0] == 0 && road_type[1] == 0 && road_type[2] == 0 && road_type[3] == 0) {
		return 3;
	}

	//һ��true
	if (road_type[0] == 1 && road_type[1] == 0 && road_type[2] == 0 && road_type[3] == 0) {
		return 3;
	}
	if (road_type[0] == 0 && road_type[1] == 1 && road_type[2] == 0 && road_type[3] == 0) {
		return 4;
	}
	if (road_type[0] == 0 && road_type[1] == 0 && road_type[2] == 1 && road_type[3] == 0) {
		return 4;
	}
	if (road_type[0] == 0 && road_type[1] == 0 && road_type[2] == 0 && road_type[3] == 1) {
		return 3;
	}

	//ͨ������ж�������ҵ���Ӧ��ͼƬ
	//����true
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

	//����true
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

	//�ĸ�true
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
//6.���Ƶ����������Ҫ��
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
	setfillcolor(0xcbe2ea);
	solidrectangle(x, y, x + width, y + height);

	//�������ѡ������
	//������ڵ�ͼ��
	if (mouse_now_abstract_x != -1 && mouse_now_abstract_y != -1) {
		//printf("dashed_line draw\nmouse_x:%d mouse_y:%d\n", mouse_now_abstract_x, mouse_now_abstract_y);
		//����column�ϵı��
		//printf("x:%d y:%d width:%d height:%d\n", x, y, width, height);
		//printf("draw solidrectangle\n left:%d top:%d right:%d bottom:%d\n", x + mouse_now_abstract_x * length, y, x + (mouse_now_abstract_x + 1) * length, y + height);
		setfillcolor(0xAAAA00);
		solidrectangle(x + mouse_now_abstract_x * length, y, x + (mouse_now_abstract_x + 1) * length, y + height);
		//����row�ϵı��
		//printf("draw solidrectangle\n left:%d top:%d right:%d bottom:%d\n", x, y + mouse_now_abstract_y * length, x + width, y + (mouse_now_abstract_y + 1));
		solidrectangle(x, y + mouse_now_abstract_y * length, x + width, y + (mouse_now_abstract_y + 1)*length);
	}

	//���Ƹ��Ӽ����
	draw_subline();
	
	//static int times = 0;
	//printf("building draw init no.%d\n",times++);

	//ͨ�����������е�������ֱ����roads��houses���Ƶ�ͼ
	for (int i =0; i <row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (mapData[i][j] != '0' && mapData[i][j] != '-')
			{
				//printf("draw house init\n");
				my_houses.draw(length, (x + (j * length)), (y + (i * length)), (mapData[i][j] - '0'));
				//printf("draw house success\n");
			}
			else if (mapData[i][j] == '0')
			{
				//�ڻ��Ƶ�·��ʱ����Ҫ����select_road_type��֪��·����
				//printf("draw road init\n");
				my_roads.draw(length, (x + (j  * length)), (y + (i * length)), select_road_type(i, j));
				//printf("draw road success\n");
			}
		}
	}

	//��is_navigation == true ʱ����mapNavigation���Ƶ���
	if (is_navigation) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (mapNavigation[i][j]) {
					setfillcolor(GREEN);
					//��·�����Ļ���ԲȦ
					solidcircle(x + j * length + length * 0.5, y + i * length + 0.5 * length, length * 0.1);
				}
			}
		}
	}

}


//��������ͷ���id(road id Ϊ0��
void map::add_building(int x, int y, int house_type)
{
	//printf("add_builiding active\n");
	//���ȼ����ʱ����λ����Ϣ��
	translate_xy(real_coord, x, y);
	
	//����ǰ���ཨ��û�б�����ʱ��������ý���
	if (!is_building_present[house_type]) {
		//printf("add house no.%d at x:%d y:%d\n", house_type, real_coord[1], real_coord[0]);
		mapData[real_coord[0]][real_coord[1]] = char(house_type+'0');
		//printf("%c\n", mapData[real_coord[0]][real_coord[1]]);
		
		//������õĽ������ǵ�·������±��
		if (house_type != 0) {
			//�õ�ͼ������+1
			building_num++;

			//��¼��������
			building_position[house_type][0] = real_coord[0];
			building_position[house_type][1] = real_coord[1];

			//��¼��ǰ���෿���ѱ�����
			is_building_present[house_type] = true;
			//printf("add house complete");
		}
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
	/*printf("\nnowx: %d", x);
	printf(" nowy: %d\n", y);
	printf("mapx:%d", this->x);
	printf("mapy:%d\n", this->y);*/
	//��û�л��Ƶ�ͼ��ʱ��
	if (this->x == -1 && this->y == -1 && width == -1 && height == -1) {
		return false;
	}
	//�������ĵ��ڵ�ͼ�ϵ�ʱ��
	if (x > this->x && x<(this->x + width) && y>this->y && (y < this->y + height)) {
		
		//�����߼�ֵ
		//���������������洢
		ans[1] = (x - this->x) / length;
		ans[0] = (y - this->y) / length;
		/*printf("ax:%d", ans[0]);
		printf(" ay:%d\n", ans[1]);*/

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
		mouse_now_abstract_x = real_coord[1];
		mouse_now_abstract_y = real_coord[0];
	}

}

//���Ƹ����ߣ������û����ý���
//(x,y)Ϊ���Ƶ�ͼ�ĵ����Ͻǣ�����λ����Ϊ��ͼ�Ŀ�Ⱥͳ���
void map::draw_subline()
{
	setlinecolor(RGB(225, 225, 225));
	setfillcolor(RGB(225, 225, 225));
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





//�������أ����·��
//ʹ�ÿ����������
bool map::connect_houses(int house_type1, int house_type2){
	printf("house_type1:%d house_type2:%d\n", house_type1, house_type2);

	//����mapNavigation
	std::vector<std::vector<bool>> mapNavigation_temp(row, std::vector<bool>(column, false));
	mapNavigation = mapNavigation_temp;

	//���������������û�з��ã��򷵻�false,��ʾ����ʧ��
	if (!is_building_present[house_type1] || !is_building_present[house_type2]) {
		is_navigation = false;
		return false;
	}

	//��ǵ�ǰ���Ƿ��Ѿ�����������
	//����Ѿ����������ˣ���Ϊtrue
	bool flag[30][30] = { false };

	

	//���������鱣�������ķ���
	static int move_x[4] = { 0,1,-1,0 };
	static int move_y[4] = { 1,0,0,-1 };

	//���������ҪѰ�ҵ�һϵ�е������
	//��ʹ��dequeģ����е�ԭ����֮��Ҫ����
	//qy�б����ά�����һ�qx�����ά����ڶ���
	int qx[1000] = { 0 };
	int qy[1000] = { 0 };

	//��ͷ��β����ʹ�ú��1
	//��ͷ����ȥ��Ԫ�أ���β�����ж϶����Ƿ�Ϊ��
	int head = 0;
	int tail = 0;

	//���û��ݶ���
	int memory[1000] = { 0 };

	//�������������
	qy[tail] = building_position[house_type1][0];
	qx[tail] = building_position[house_type1][1];

	//�����Ļ����±���Ϊ-1����ʾ���ڵ�
	memory[tail] = -1;

	//�������������ѱ�����
	flag[qy[tail]][qx[tail]] = true;

	++tail;



	//ֻҪ���в��գ���һֱ����
	int times=0;
	while (head != tail) {
		//printf("\n\ntimes:%d\n", times++);
		//ȡ����ͷ����
		int tempx = qx[head];
		int tempy = qy[head];
		//printf("headx:%d heady:%d\n",tempx,tempy);
		++head;

		//������ĵ�ĸ��׽ڵ�
		int fIndex = head - 1;

		for (int i = 0; i < 4; i++) {
			//�����һ����
			int nextx = tempx + move_x[i];
			int nexty = tempy + move_y[i];

			//�����ǰ���ڵ�ͼ��
			if (nextx >= 0 && nextx < column && nexty >= 0 && nexty < row &&
				//�ǵ�·
				(mapData[nexty][nextx]=='0'||
				//�����ǽ����Ҵ�·ͨ
				(mapData[nexty][nextx]>'0'&&mapData[nexty][nextx] <= building_num+'0')&&
				my_houses.is_door(i,mapData[nexty][nextx])) &&
				//��ǰ�㻹û�б�������
				!flag[nexty][nextx]
				) {

				//printf("nextx:%d nexty:%d\n", nextx, nexty);
				//printf("now mapData:%c\n", mapData[nexty][nextx]);

				/*for (int i = 0; i < row; i++) {
					for (int j = 0; j < column; j++) {
						printf("%c", mapData[i][j]);
					}
					printf("\n");
				}*/

				//��ʾ��ǰ���Ѿ�����������
				flag[nexty][nextx] = true;

				
				//����ҵ���Ŀ�ĵ�
				if (mapData[nexty][nextx] == house_type2 + '0') {
					printf("find success1\n");
					is_navigation = true;
					while (memory[fIndex] != -1) {
						//printf("y:%d x:%d\n", qy[fIndex], qx[fIndex]);
						mapNavigation[qy[fIndex]][qx[fIndex]] = true;
						fIndex = memory[fIndex];
					}
					printf("find success2\n");
					return true;
				}

				//����Ŀ�ĵ�
				qy[tail] = nexty;
				qx[tail] = nextx;
				memory[tail] = fIndex;
				tail++;
			}
		}
	}
	//û���ҵ�
	is_navigation = false;
	return false;

}

//�������·��(����֮����չ)
void map::clear_connect_houses(){
	is_navigation = false;
	printf("clear_connect_house success!\n");
}

