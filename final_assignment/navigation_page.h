#pragma once
#include "abstract_page.h"
#include "maps.h"
//class navigationʵ�ֶ��Ա༭��ͼ��һϵ�й���
class navigation_page :public abstract_page {
public:
	navigation_page(int next_id, int w, int h,maps<show_maps_num>& my_maps);
	//virtual void update_maps()override;
	virtual void get_keyboard_message()override;
	virtual void draw()override;
	virtual ~navigation_page();
private:
	//ʹ��maps��ʵ�ֵ�ͼ���漰����(���ô��ݣ�
	maps<show_maps_num>& my_maps;
};