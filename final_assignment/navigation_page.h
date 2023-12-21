#pragma once
#include "abstract_page.h"
#include "maps.h"
#include "button.h"
#include <vector>
#include "picture_button.h"
//class navigationʵ�ֶ��Ա༭��ͼ��һϵ�й���
class navigation_page :public abstract_page {
public:
	navigation_page(int next_id, int w, int h,maps& my_maps);
	//virtual void update_maps()override;
	virtual void get_keyboard_message()override;
	virtual void draw()override;
	virtual ~navigation_page();
private:
	//ʹ��maps��ʵ�ֵ�ͼ���漰����(���ô��ݣ�
	maps& my_maps;
	//���ذ���
	button* return_button;
	//����ģ��ߴ�
	int left_width, left_height;
	int right_width, right_height;
	 //��������
	double scale;
	//��ͼʵ������
	int map_real_x;
	int map_real_y;
	//��ͼʵ�ʳ���
	int map_width, map_height;

	//�ҹ��ܲ˵���ť����
	//���ɺ͵�ͼ�༭�˵���࣬���û�ѡ������������ʱ�򣬾ͽ��䴫��maps���л���·��
	std::vector<picture_button*> my_picture_button;
	//�����ǰû��ѡ�������ͼ�¼�������
	//�����ǰ�Ѿ�ѡ��һ���������͵���maps
	//�����ǰ�Ѿ�ѡ�������������޷�ѡ���½���
	//������ѡ��Ľ�������ɾ����ѡ��
	void set_now_select_building_id(int i);
	//��¼��ǰѡ��Ľ���
	int now_select_building[2];
	//��¼��ǰѡ�������������߼�ʵ��
	int now_select_building_num;
	// һ������ѡ��ĳ���(ָ�ұ�ѡ���еĽ����������ߴ磩
	int single_object_width;
	int single_object_height;
};