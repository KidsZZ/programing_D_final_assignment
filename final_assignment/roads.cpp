#include"roads.h"


//������png��͸������,Դ�ļ�����picture_button.cpp
void putimage_alpha(IMAGE& image, int x, int y, int w = -1, int h = -1);

//���캯���������·ͼƬ
roads::	roads(std::wstring path, int n) 
{
	road_img.push_back(nullptr);
	//����ͼƬ
	IMAGE* img;//ʹ��new�ڶ�������IMAGE���͵�ַ
	for (int i = 1; i <= n; i++)
	{
		//ƴ��ͼƬ�����ļ�·���������ձ���չ��
		//ע�������ͼƬ˳��Ҫ��enum.lib�е�һһ��Ӧ����1��ʼ���
		std::wstring filename = path + L"road"+std::to_wstring(i) + L".png";
		img = new IMAGE();
		loadimage(img, filename.c_str());//����ͼƬ
		road_img.push_back(img);//��ͼƬ��ַ��ָ�����ݴ�ŵ�house_img�б���
	}

}

//���ƺ����������ŵ�ͼ��Ϣ�Ľṹ����л���
void roads:: draw(int length, int x, int y, int direction)const
{
	//printf("direction:%d\n", direction);
	putimage_alpha(*road_img[direction], x, y, length, length);//�������ֵ��ƫ����
	//printf("put road success!\n");
}

//�����������ͷŵ�·ͼƬ
roads::	~roads() 
{
	while (!road_img.empty()) {
		delete road_img.back();
		road_img.pop_back();
	}
}



