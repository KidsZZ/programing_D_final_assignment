#include <iostream>
#include <windows.h>
//option����ѡ��Ļ���,�翪ʼ�����ѡ���ͼ�����ѡ��
//����ѡ������ݣ�λ��
//�ڴ���option��ʱ��Ҫע��ص�������lambda���ʽ��
#include <string>
#include <functional>
class option {
public:
	//���캯������ʼ��selected��width��height��x,y,scale
	option(int width, int height, int x, int y, const std::wstring& text, const std::function<void()>& my_fun);
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
//using namespace std;

#include <graphics.h>

option::option(int width, int height, int x, int y, const std::wstring& text, const std::function<void()>& on_Click) :text(text), is_mouse_over(false), width(width), height(height), x(x), y(y), scale(1.0), on_Click(on_Click) {
	//draw();
}

void option::draw() {
	if (is_mouse_over) {
		setlinecolor(RGB(BRS, BGS, BBS));
		setfillcolor(RGB(FRS, FGS, FBS));
	}
	else {
		setlinecolor(RGB(BR, BG, BB));
		setfillcolor(RGB(FR, FG, FB));
	}
	int scaledWidth = width * scale; // ���ź�İ�ť���
	int scaledHeight = height * scale; // ���ź�İ�ť�߶�
	int scaledX = x + (width - scaledWidth) / 2; // ���ź�İ�ťx����
	int scaledY = y + (height - scaledHeight) / 2; // ���ź�İ�ťy����
	fillrectangle(scaledX, scaledY, scaledX + scaledWidth, scaledY + scaledHeight); // ���ư�ť
	settextcolor(BLACK); // �����ı���ɫΪ��ɫ
	setbkmode(TRANSPARENT); // �����ı�����͸��
	settextstyle(35 * scale, 0, _T("΢���ź�"));//�ı���С
	//������ʾ��ť�ı�
	int textX = scaledX + (scaledWidth - textwidth(text.c_str())) / 2; // �����ı��ڰ�ť�����x����
	int textY = scaledY + (scaledHeight - textheight(_T("TEST"))) / 2; // �����ı��ڰ�ť�����y����
	outtextxy(textX, textY, text.c_str()); // �ڰ�ť�ϻ����ı�
}


//�ж�����Ƿ���ѡ���ϣ����ݴ��޸�is_mouse_over��scale
bool option::checkMouseOver(int mouse_x, int mouse_y) {
	if (is_mouse_over = (mouse_x >= x) && (mouse_x <= (x + width)) && (mouse_y >= y) && (mouse_y <= (y + height))) {
		scale = 0.9;
		return true;
	}
	else {
		scale = 1.0;
		return false;
	}
}

bool option::checkMouseClick(int mouse_x, int mouse_y)
{
	if ((mouse_x >= x) && (mouse_x <= (x + width)) && (mouse_y >= y) && (mouse_y <= (y + height))) {
		on_Click();
		return true;
	}
	else {
		return false;
	}
}

#include <iostream>
int main() {
	initgraph(1920, 1690);
	option* my_option = new option(400, 100, 800, 600, L"lidhlkdjfd", []() {std::cout << "hello world!"; });
	while (true) {
		my_option->draw();
	}
	return 0;
}