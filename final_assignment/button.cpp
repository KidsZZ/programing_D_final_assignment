#include "button.h"
#include <graphics.h>

button::button(int width, int height, int x, int y, const std::wstring& text, const std::function<void()>& on_Click) :text(text), is_mouse_over(false), width(width), height(height), x(x), y(y), scale(1.0), on_Click(on_Click){
	//draw();
}

void button::draw() {

	//�����Ƿ�ѡ����İ�ť����ɫ
	if (is_mouse_over) {
		setlinecolor(RGB(BRS, BGS, BBS));
		setfillcolor(RGB(FRS, FGS, FBS));
	}
	else {
		setlinecolor(RGB(BR, BG, BB));
		setfillcolor(RGB(FR, FG, FB));
	}

	// ���ź�İ�ť���
	int scaledWidth = width * scale; 

	// ���ź�İ�ť�߶�
	int scaledHeight = height * scale; 

	// ���ź�İ�ťx����
	int scaledX = x + (width - scaledWidth) / 2; 

	// ���ź�İ�ťy����
	int scaledY = y + (height - scaledHeight) / 2; 

	// ���ư�ť
	fillrectangle(scaledX, scaledY, scaledX + scaledWidth, scaledY + scaledHeight); 

	//�����ı���ɫΪ��ɫ
	settextcolor(BLACK); 

	//�����ı�����͸��
	setbkmode(TRANSPARENT);

	//�ı���С
	settextstyle(35 * scale, 0, _T("΢���ź�"));

	//������ʾ��ť�ı�
	//�����ı��ڰ�ť�����x����
	int textX = scaledX + (scaledWidth - textwidth(text.c_str())) / 2; 
	//�����ı��ڰ�ť�����y����

	//�ڰ�ť�ϻ����ı�
	int textY = scaledY + (scaledHeight - textheight(_T("TEST"))) / 2; 
	outtextxy(textX, textY, text.c_str()); 
}


//�ж�����Ƿ���ѡ���ϣ����ݴ��޸�is_mouse_over��scale
bool button::checkMouseOver(int mouse_x,int mouse_y) {
	if (is_mouse_over = (mouse_x >= x) && (mouse_x <= (x + width)) && (mouse_y >= y) && (mouse_y <= (y + height))) {
		scale = 0.9;
		return true;
	}
	else {
		scale = 1.0;
		return false;
	}
}

bool button::checkMouseClick(int mouse_x, int mouse_y)
{
	if ((mouse_x != 0 || mouse_y != 0) && (mouse_x >= x) && (mouse_x <= (x + width)) && (mouse_y >= y) && (mouse_y <= (y + height))) {
		on_Click();
		return true;
	}
	else {
		return false;
	}
}
