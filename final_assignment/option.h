#pragma once
//option����ѡ��Ļ���,�翪ʼ�����ѡ���ͼ�����ѡ��
//����ѡ������֣�λ��
class option {
public:
	//Ĭ�Ϲ��캯������ʼ��selected��scale
	option();
	//���캯������ʼ��selected��width��length��x,y,scale
	option(int width, int length, int x, int y);
	//��ǰѡ���Ƿ�ѡ�У��������ݳ�Ա��
	void is_selected(bool);

	//ѡ��Ļ��ƺ���
	//1.�ж�ѡ���Ƿ�ѡ�У��ò�ͬ��ɫ�ͷ���������
	//2.����ѡ������ͺ��Ȼ���ѡ��ѡ��
	void draw();

	//set����
	void set_x(int x);
	void set_y(int y);
	void set_w(int w);
	void set_l(int l);

protected:

	//��¼��ǰѡ���Ƿ�ѡ��
	bool selected;

	//ѡ��ĺ���
	int width, length;

	//ѡ���λ��
	int x, y;

	//ѡ��ѡ��ʱ�Ĳ���
	//1.������
	double scale;
	//2.ѡ��ʱ����ɫ(selected)
	int BRS = 0, BGS = 120, BBS = 215;//�߿�(border)
	int FRS = 229, FGS = 241, FBS = 251;//��䣨filled��
	//3.δѡ��ʱ����ɫ
	int  BR = 173, BG = 173, BB = 173;
	int FR = 225, FG = 225, FB = 225;
};