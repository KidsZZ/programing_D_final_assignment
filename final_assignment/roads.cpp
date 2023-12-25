#include"roads.h"


//������png��͸������
#pragma comment(lib,"MSIMG32.LIB")
inline void putimage_alpha(int x, int y, int w, int h, IMAGE* img)
{

	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
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
	putimage_alpha(x, y, length, length, road_img[direction]);//�������ֵ��ƫ����
}

//�����������ͷŵ�·ͼƬ
roads::	~roads() 
{
	while (!road_img.empty()) {
		delete road_img.back();
		road_img.pop_back();
	}
}



