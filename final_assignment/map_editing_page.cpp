#include "map_editing_page.h"

map_editing_page::map_editing_page(int next_id, int w, int h, maps& my_maps) :abstract_page(next_id, w, h) ,my_maps(my_maps){
	//����ģ��ߴ�
	left_width = width * 0.8;
	right_width = width - left_width;
	left_height = right_height = height;
	//��ͼʵ�ʳߴ�
	map_width = left_width * 0.85;
	map_height = map_width / 1.5;
	//��ͼ��ߵĿռ�
	// һ������ѡ��ĳ���(ָ�ұ�ѡ���еĽ����������ߴ磩
	single_object_width = right_width;
	single_object_height = right_height / 5;

}
