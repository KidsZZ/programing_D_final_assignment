//�˺���ʵ�ֶ�map_select_map��ѡ��ĵ�ͼ�ı༭
//��Ϊ�������֣�
//�ұ߳���Ԥ��Ľ��������û�ѡ��
//��߷��õ�ͼ���û�����ͨ�������ͼ�ϵĸ���ʵ�ֶ��ұ�ѡ��Ľ����ķ���

#pragma once

#include <vector>
#include "abstract_page.h"
#include "maps.h"
#include "picture_button.h"
#include "button.h"

//class map_editingʵ�ֶԵ�ͼ�ı༭
class map_editing_page :public abstract_page {
public:
	
	//���캯��
	map_editing_page(int w, int h, maps& my_maps);

	//�Ի��๹�캯�����麯��������
	virtual void get_keyboard_message()override;
	virtual void draw()override;
	virtual ~map_editing_page();
	virtual int return_page_id()override;

private:

	//����ͼƬ
	IMAGE* bk_img;

	//ʹ��maps��ʵ�ֵ�ͼ���漰����(���ô��ݣ�
	maps& my_maps;

	//���õ�ǰѡ��Ľ���id
	//�ú���ΪΪ�ұ�ѡ�����İ�ť�Ļص�����
	void set_now_select_building_id(int id) {
		now_select_building = id;
	}

	//�����ұߵĽ���ѡ��
	std::vector<picture_button*> my_picture_button;

	//���ذ���
	button* return_button;

	//��ǰѡ��Ľ���
	//�ڻ�����ѡ��Ľ���ʱ�����䱳���������⴦��
	int now_select_building;

	//��ͼԪ������
	// ��ߵ�ͼ����ռ��
	int left_width, left_height;
	// �ұ�ѡ���ռ��
	int right_width, right_height;
	// ��ͼʵ�ʳ��ȣ����У�
	int map_width;
	// ��ͼʵ�ʿ��
	int map_height;
	//��ͼʵ������
	int map_real_x;
	int map_real_y;

	// һ������ѡ��ĳ���(ָ�ұ�ѡ���еĽ����������ߴ磩
	int single_object_width;
	int single_object_height;
	
};