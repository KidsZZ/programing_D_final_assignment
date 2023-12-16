#include "option.h"
#include <graphics.h>

option::option(int width, int height, int x, int y, const std::wstring& text, const std::function<void()>& on_Click) :text(text), is_mouse_over(false), width(width), height(height), x(x), y(y), scale(1.0), on_Click(on_Click){
	draw();
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
bool option::checkMouseOver(int mouse_x,int mouse_y) {
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
