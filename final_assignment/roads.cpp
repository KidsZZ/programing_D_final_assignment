#include"roads.h"

//���캯���������·ͼƬ
roads::	roads(std::wstring path, int n=11) 
{
	road_img.push_back(nullptr);
	//����ͼƬ
	IMAGE* img;//ʹ��new�ڶ�������IMAGE���͵�ַ
	for (int i = 1; i <= n; i++)
	{
		//ƴ��ͼƬ�����ļ�·���������ձ���չ��
		//ע�������ͼƬ˳��Ҫ��enum.lib�е�һһ��Ӧ����1��ʼ���
		std::wstring filename = path + std::to_wstring(i) + L".png";
		img = new IMAGE();
		loadimage(img, filename.c_str());//����ͼƬ
		road_img.push_back(img);//��ͼƬ��ַ��ָ�����ݴ�ŵ�house_img�б���
	}

};


//�����������ͷŵ�·ͼƬ
roads::	~roads() 
{
	for (auto img : road_img)
	{
		delete(img);
	}
};

//���ƺ����������ŵ�ͼ��Ϣ�Ľṹ����л���
void roads:: draw(int length, int x, int y, int direction)
{
	putimage(x, y, length, length, road_img[direction], 0, 0);//�������ֵ��ƫ����
};
