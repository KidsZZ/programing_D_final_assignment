#pragma once
//enum_lib��ʹ��enum������ೣ����ȷ����������Ϣͨ����ȷ��Ч
//��·����
enum roads_direction{
	//�Ե�·������б�ţ������ѭ�������£�
	//����·��
	up_left, up_right, up_down, left_right, left_down, right_down,
	//����·
	no_up, no_left, no_right, no_down,
	//ʮ��·��
	crossroads
};
//��������
enum house_type {
	road=0,
	library,
	dorminory,
	teaching_building,
	canteen
};
//�жϷ��ų�����ʹ�õĴ��γ���
enum direction {
	up,
	left,
	right,
	down
};
//ҳ������
enum page_id {
	HOME_PAGE = 0,
	MAP_SELECT_PAGE,
	MAP_EDITING_PAGE,
	NAVIGATION_PAGE,
	EXIT
};

const int building_num = 5;
