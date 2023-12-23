#include"houses.h"

//���캯������ʼ��img����(��������ַ��ͨ����ʽ����img/img*.png��ʹ��ʵ����Ƭ����滻*��ǣ�
//**************************  0�������ڸ���·ռλ����·����Ϊ0��  ************************************
houses::houses(std::wstring path, int n) 
{	
	//��ȫ��Ϊtrue��ע��vector����ֱ�ӷ�ֵ��Ҫpush��ȥ
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			house_orientation[i][j] = true;
		}
		
	}

	house_img.push_back(nullptr);

	//����ͼƬ
	IMAGE* img;//ʹ��new�ڶ�������IMAGE���͵�ַ
	for (int i = 1; i <= n; i++)
	{	
		//ƴ��ͼƬ�����ļ�·���������ձ���չ��
		//ע�������ͼƬ˳��Ҫ��enum.lib�е�һһ��Ӧ����1��ʼ���
		std::wstring filename = path + std::to_wstring(i) + L".png";
		img = new IMAGE();
		loadimage(img, filename.c_str());//����ͼƬ
		house_img.push_back(img);//��ͼƬ��ַ��ָ�����ݴ�ŵ�house_img�б���
	}
}

//���ƺ���:���뵱ǰ��ͼ���ݣ��������ݻ�����
void houses::draw(int length, int x, int y,int house_type)const
{	//��Ⱦ����ͼƬ
	putimage(x, y, length,length,house_img[house_type],0,0);//�������ֵ��ƫ����
}

//Ϊ���Ƶ�·�ṩ������ķ����Ƿ������������
bool houses::is_door(int direction, char c) const
{
	int house_type = c - '0';
	return house_orientation[house_type][direction];//���ڿ���չ
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
