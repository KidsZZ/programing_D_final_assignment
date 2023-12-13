#pragma once
//class abstract_house�ǲ�ͬhouse��Ļ��࣬Ϊhouse_management��ͨ����̬���й����ṩ�ӿں���
#include <graphics.h>
#include <string>
class abstract_house {
public:
	//���캯������ʼ��img����(��������Ĺ��캯����Ҫ�Ի����Ա���и��Ի���ֵ
	abstract_house(std::string path);
	virtual int get_id() = 0;
	//���ƺ���
	virtual void draw(int x, int y) = 0;
	//��������������img����
	//������Ϊ�麯������������û���µ����ݳ�Ա
	~abstract_house();
protected:
	//ʹ��ö�����¼���ӱ��
	enum house_type{
		museum = 1,
		dorminory,
		teaching_building,
		canteen
	};
	//���淿�ӵ�
	IMAGE* img;
	//������ŵĳ���ʹ���������ҵ�˳��洢
	//����Ϊtrue��������Ϊfalse
	bool door_orientation[4];
};