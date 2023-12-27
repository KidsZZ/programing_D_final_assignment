#include"houses.h"

//���캯������ʼ��img����(��������ַ��ͨ����ʽ����img/img*.png��ʹ��ʵ����Ƭ����滻*��ǣ�
//**********************  0�������ڸ���·ռλ����·����Ϊ0��  *****************

//������png��͸������,Դ�ļ�����picture_button.cpp
void putimage_alpha(IMAGE& image, int x, int y, int w = -1, int h = -1);

houses::houses(std::wstring path, int n) 
{	
	//house_orientation�±�Ϊ0�ĵط��Ǹ���·ռλ��
	//��ȫ��Ϊtrue��ע��vector����ֱ�ӷ�ֵ��Ҫpush��ȥ

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			house_orientation[i][j] = false;
		}
		
	}

	//ͼ���,���¿�
	house_orientation[house_type::library][direction::down] = true;
	//���ң����ҿ�
	house_orientation[house_type::dorminory][direction::right] = true;
	//���ң����Ͽ�
	house_orientation[house_type::teaching_building][direction::up] = true;
	//ʳ�ã������¿�
	house_orientation[house_type::canteen][direction::up] = true;
	house_orientation[house_type::canteen][direction::down] = true;

	house_img.push_back(nullptr);

	//����ͼƬ
	IMAGE* img;//ʹ��new�ڶ�������IMAGE���͵�ַ
	for (int i = 1; i <= n; i++)
	{	
		//ƴ��ͼƬ�����ļ�·���������ձ���չ��
		//ע�������ͼƬ˳��Ҫ��enum.lib�е�һһ��Ӧ����1��ʼ���
		std::wstring filename = path + L"house" + std::to_wstring(i) + L".png";
		img = new IMAGE();
		loadimage(img, filename.c_str());//����ͼƬ
		house_img.push_back(img);//��ͼƬ��ַ��ָ�����ݴ�ŵ�house_img�б���
	}
}

//���ƺ���:���뵱ǰ��ͼ���ݣ��������ݻ�����
void houses::draw(int length, int x, int y,int house_type)const
{	//��Ⱦ����ͼƬ
	putimage_alpha(*house_img[house_type], x, y, length, length);//�������ֵ��ƫ����
}

//Ϊ���Ƶ�·�ṩ������ķ����Ƿ������������
bool houses::is_door(int direction, char c) const
{
	int house_type = c - '0';
	return house_orientation[house_type][direction];
}


//��������������img����
//������Ϊ�麯������������û���µ����ݳ�Ա
houses::~houses()
{
	while (!house_img.empty()) {
		delete house_img.back();
		house_img.pop_back();
	}
}
















