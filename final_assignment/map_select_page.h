#pragma once

#include "abstract_page.h"
#include "maps.h"
#include <vector>
class map_select_page :public abstract_page {
public:
	//���캯����Ҫͨ�������ʼ��ҳ��Ŀ�ߺ���һ��ҳ��id
	map_select_page(int next_id,int w,int h, maps<show_maps_num>& my_maps);
	//virtual void update_maps()override;
	virtual bool get_keyboard_message()override;
	virtual void draw()override;

	virtual int return_page_id()override;
	virtual ~map_select_page();
private:
	//ʹ��maps��ʵ�ֵ�ͼ���漰����(���ô��ݣ�
	maps<show_maps_num> &my_maps;

};