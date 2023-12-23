//map_select_page�Ĺ��������û�ѡ��ǰ��Ҫ���в����ĵ�ͼ
//��������ͼʹ������ͼ����ʽ������ѡ���ϣ��Ա�ѡ��
//�ڶ�������Ҫ����maps��������ã�ͨ��maps���������غ���

#pragma once

#include <vector>
#include "abstract_page.h"
#include "maps.h"
#include "button.h"

//�̳�abstract_page��ʵ�־��庯��
class map_select_page :public abstract_page {
public:

	//���캯��
	//Ҫͨ�������ʼ��ҳ��Ŀ�ߺ���һ��ҳ��id
	map_select_page(int w,int h, maps& my_maps);

	//����������ݣ����õ�ͼѡ��Ͱ�ť��غ���
	virtual void get_keyboard_message()override;

	//���ƻ���
	virtual void draw()override;

	//��������
	//�ͷŷ��ذ��������ܰ�ť
	virtual ~map_select_page();

private:

	//ʹ��maps��ʵ�ֵ�ͼ���漰����(���ô��ݣ�
	maps &my_maps;

	//����ͼƬ
	IMAGE* bk_img;

	//�ұ߹��ܲ˵���ť
	std::vector<button*> my_button;

	//���ذ�ť
	button* return_button;

	//��ͼ�ߴ�
	int map_width, map_height;

	//��ͼѡ��ǰ�����ű�
	double unselected_scale;
	//��ͼѡ�������ű�
	double selected_scale;

	//��ť�ߴ�
	int button_width, button_height;

	//��ť�ı�
	std::wstring first_button_text;
	std::wstring second_button_text;


	//ҳ��Ԫ�ض�λ�������
	//���ͼѡ��ģ��Ŀ��
	int left_width, left_height;
	//��ѡ��ģ��Ŀ��
	int  right_width, right_height;
	//��ťλ��
	int first_button_x, first_button_y;
	int second_button_x, second_button_y;

	//�������к��е�˳��洢����Ƿ��ڵ�ͼ��
	bool is_map_over[2][2];
	//���浱ǰѡ�еĵ�ͼid
	int map_selected_id;
	//��ͼ�Ŵ�ǰ����ռ�
	int map_left_space_x;
	int map_left_space_y;
	//��ͼ�Ŵ�����ռ�
	int map_left_space_x_selected;
	int map_left_space_y_selected;

	//���ŵ�ͼ��ǰ����ռ�
	int map_real[2][2][2];
};