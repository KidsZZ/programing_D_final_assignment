#include"roads.h"


//������png��͸������
#pragma comment (lib, "MSIMG32.lib")
void putimage_alpha(IMAGE& image, int x, int y, int w = -1, int h = -1)
{
	BLENDFUNCTION blendfunc = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	int width = image.getwidth();
	int height = image.getheight();
	if (w == -1)w = width;
	if (h == -1)h = height;
	AlphaBlend(GetImageHDC(), x, y, w, h, GetImageHDC(&image), 0, 0, width, height, blendfunc);
}

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
	putimage_alpha(*road_img[direction], x, y, length, length);//�������ֵ��ƫ����
}

//�����������ͷŵ�·ͼƬ
roads::	~roads() 
{
	while (!road_img.empty()) {
		delete road_img.back();
		road_img.pop_back();
	}
}



