#include <graphics.h>
#include <vector>
#include <conio.h>
#include <ctime>
#include <cmath>
#include<Windows.h>
#pragma comment( lib, "MSIMG32.LIB")
const int n = 15;

const int x = 50;
const int y = 50;

int chess_len = 30;//���ӳ���

int current_x = 0;//��ǰ����
int current_y = 0;

int current_play = 1;//��ǰ�����ɫ��1��ʾ���壬2��ʾ����
IMAGE bk;//����ͼƬ
IMAGE white;//����
IMAGE black;//����
int map[n + 1][n + 1] = { 0 };//��������
bool isEnd = false;//��Ϸ������־

void putTranspareImage(IMAGE* target, int x, int y, IMAGE* source)
{
	/*����Ļ����ʾ͸����ͼ����*/
	HDC targetDc = GetImageHDC(target);
	HDC sourceDc = GetImageHDC(source);
	int w = (*source).getwidth();
	int h = (*source).getheight();

	// �ṹ��ĵ�������Ա��ʾ�����͸���ȣ�0 ��ʾȫ͸����255 ��ʾ��͸����
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	//ʹ�� Windows GDI ����ʵ�ְ�͸��λͼ
	AlphaBlend(targetDc, x, y, w, h, sourceDc, 0, 0, w, h, bf);
}

//�ж���Ϸ�Ƿ����
void judge() {
	bool l = true, r = true;
	int count = 0;

	for (int i = 1; i <= 4; ++i) {
		if (l && current_y - i >= 0) {
			if (map[current_x][current_y - i] == current_play) {	//�ж�����ֱ��
				count++;
			}
			else {
				l = false;
			}
		}
		if (r && current_y + i <= n) {
			if (map[current_x][current_y + i] == current_play) {
				count++;
			}
			else {
				r = false;
			}
		}
	}
	if (count >= 4) {
		isEnd = true;
		return;
	}

	l = r = true;
	count = 0;
	for (int i = 1; i <= 4; ++i) {
		if (l && current_x - i >= 0) {
			if (map[current_x - i][current_y] == current_play) {	//�ж�����ֱ��
				count++;
			}
			else {
				l = false;
			}
		}
		if (r && current_x + i <= n) {
			if (map[current_x + i][current_y] == current_play) {
				count++;
			}
			else {
				r = false;
			}
		}
	}
	if (count >= 4) {
		isEnd = true;
		return;
	}

	l = r = true;
	count = 0;
	for (int i = 1; i <= 4; ++i) {	//���ϵ����µ�ֱ��
		if (l && current_x - i >= 0 && current_y - i >= 0) {
			if (map[current_x - i][current_y - i] == current_play) {
				count++;
			}
			else {
				l = false;
			}
		}
		if (r && current_x + i <= n && current_y + i <= n) {
			if (map[current_x + i][current_y + i] == current_play) {
				count++;
			}
			else {
				r = false;
			}
		}
	}
	if (count >= 4) {
		isEnd = true;
		return;
	}

	l = r = true;
	count = 0;
	for (int i = 1; i <= 4; ++i) {	//���ϵ����µ�ֱ��
		if (l && current_x - i >= 0 && current_y + i <= n) {
			if (map[current_x - i][current_y + i] == current_play) {
				count++;
			}
			else {
				l = false;
			}
		}
		if (r && current_x + i <= n && current_y - i >= 0) {
			if (map[current_x + i][current_y - i] == current_play) {
				count++;
			}
			else {
				r = false;
			}
		}
	}
	if (count >= 4) {
		isEnd = true;
		return;
	}
}

//��������
void updata(BYTE vkcode) {
	if (vkcode == 0x41) {   //A��
		if (current_y - 1 >= 0) {
			current_y -= 1;
		}
	}
	else if (vkcode == 0x44) {//D
		if (current_y + 1 <= n) {
			current_y += 1;
		}
	}
	else if (vkcode == 0x57) {//W
		if (current_x - 1 >= 0) {
			current_x -= 1;
		}
	}
	else if (vkcode == 0x53) {//S
		if (current_x + 1 <= n) {
			current_x += 1;
		}
	}
	else if (vkcode == VK_SPACE) {//�ո�
		if (!map[current_x][current_y]) {
			map[current_x][current_y] = current_play;
			judge();
			current_play = 3 - current_play;
		}
	}
}

//����
void draw() {

	//����
	putimage(0, 0, &bk);

	//��������
	setlinecolor(BLACK);
	for (int i = 0; i <= n; ++i) {
		line(x, y + i * chess_len, x + n * chess_len, y + i * chess_len);
		line(x + i * chess_len, y, x + i * chess_len, y + n * chess_len);
	}

	//�ڵ�ǰλ�û��ƺ�ɫ���
	setlinecolor(RED);
	rectangle(x + current_y * chess_len - chess_len / 2, y + current_x * chess_len - chess_len / 2,
		x + current_y * chess_len + chess_len / 2, y + current_x * chess_len + chess_len / 2);

	//��������
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (map[i][j] == 1) {
				putTranspareImage(NULL, x + j * chess_len - 14, y + i * chess_len - 14, &white);
			}
			else if (map[i][j] == 2) {
				putTranspareImage(NULL, x + j * chess_len - 14, y + i * chess_len - 14, &black);
			}
		}
	}
	setlinecolor(BLACK);
	rectangle(550, 50, 750, 350);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(50, 0, L"����");
	outtextxy(575, 50, L"���巽");
	if (current_play == 1) {
		setfillcolor(WHITE);
	}
	else if (current_play == 2) {
		setfillcolor(BLACK);
	}
	solidcircle(650, 200, 80);
}

int main() {
	loadimage(&bk, L"back.jpg");
	loadimage(&white, L"bai.png", 28, 28);
	loadimage(&black, L"hei.png", 28, 28);
	initgraph(800, 600);
	ExMessage msg;
	BeginBatchDraw();
	while (!isEnd) {

		if (peekmessage(&msg, EM_KEY)) {
			if (msg.message == WM_KEYUP) {
				updata(msg.vkcode);
			}
		}
		draw();
		FlushBatchDraw();
		Sleep(10);
		cleardevice();
	}

	MessageBox(GetHWnd(), current_play == 1 ? L"��Ϸ�����������ʤ��" : L"��Ϸ�����������ʤ��", L"Game Over", MB_OK);
	EndBatchDraw();
}