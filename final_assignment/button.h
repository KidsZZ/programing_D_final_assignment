
//button����ѡ��Ļ���,�翪ʼ�����ѡ���ͼ�����ѡ��
//����ѡ������ݣ�λ��
//�ڴ���button��ʱ��Ҫע��ص�������lambda���ʽ��

#pragma once
#include <string>
#include <functional>
class button {
public:

	//���캯������ʼ��selected��width��height��x,y,scale
	button(int width, int height, int x, int y, const std::wstring& text, const std::function<void()>& my_fun);

	//�������Ƿ���ѡ���ϣ��������ݳ�Ա��
	bool checkMouseOver(int mouse_x, int mouse_y);

	//�������Ƿ��°�ť
	bool checkMouseClick(int mouse_x, int mouse_y);

	//ѡ��Ļ��ƺ���
	//1.�ж�ѡ���Ƿ�ѡ�У��ò�ͬ��ɫ�ͷ���������
	//2.����ѡ������ͺ��Ȼ���ѡ��ѡ��
	void draw();

protected:
	//�ص�����(��⵽��ť����ʱ����)
	std::function<void()> on_Click;

	//��ť�ı���Ϣ
	std::wstring text;

	//��¼��ǰѡ���Ƿ�ѡ��
	bool is_mouse_over;

	//ѡ��Ŀ��
	int width, height;

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