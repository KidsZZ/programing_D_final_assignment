#include"houses.h"

//���캯������ʼ��img����(��������ַ��ͨ����ʽ����img/img*.png��ʹ��ʵ����Ƭ����滻*��ǣ�
houses::houses(std::wstring path, int n) 
{
	std::wstring filename = path + std::to_wstring(n) + L".png";//ƴ��ͼƬ�����ļ�·���������ձ���չ��
	IMAGE* img = new IMAGE;//ʹ��new�ڶ�������IMAGE���͵�ַ
	loadimage(img, filename.c_str());//����ͼƬ
	house_img.push_back(img);//��ֻ��ͼƬ��ַ��ָ�����ݴ�ŵ�house_img�б���
};

//���ƺ���:���뵱ǰ��ͼ���ݣ��������ݻ�����
void houses::draw(int width, int height, int x, int y)
{
	putimage(x, y, house_img[0]);//��Ⱦ����ͼƬ
};

//Ϊ���Ƶ�·�ṩ������ķ����Ƿ������������
bool houses::is_door(int direction, int house_type) 
{
	return (house_orientation[house_type][direction]);//���ڿ���չ
};
	//��������������img����
	//������Ϊ�麯������������û���µ����ݳ�Ա
houses::~houses()
{
	for (auto img:house_img)
	{
		delete(img);
	}
};
