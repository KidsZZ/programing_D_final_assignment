#include"houses.h"
using namespace std;

class houses {
public:
	//���캯������ʼ��img����(��������ַ��ͨ����ʽ����img/img*.png��ʹ��ʵ����Ƭ����滻*��ǣ�
	houses(std::string path, int n) 
	{
		//�����ַ������ڽ���ͼ������·��
		string img_path = path;
		//������int���͵����ݽ��շ��ݵ�index��
		int enum_num = n;
	};
	//���ƺ���:���뵱ǰ��ͼ���ݣ��������ݻ�����
	void draw(int width, int height, int x, int y)
	{
		int width = width;
		int height = height;
		int origin_x = x;
		int origin_y = y;

		//��������ͼ���IMAGE�Ķ���ָ��
		IMAGE img;
	
	}
	//Ϊ���Ƶ�·�ṩ������ķ����Ƿ������������
	bool is_door(int direction, int house_type);
	//��������������img����
	//������Ϊ�麯������������û���µ����ݳ�Ա
	~houses();

private:
	//ʹ��ö�����¼���ӱ��
	house_type my_house_type;
	//���淿�ӵ�ͼƬ
	std::vector<IMAGE*> house_img;
	//������ŵĳ���ʹ���������µ�˳��洢
	direction house_direction;
	//����Ϊtrue��������Ϊfalse
	std::vector<bool[4]> house_orientation;
};