#pragma once
#include "abstract_page.h"
#include "maps.h"
//class map_editingʵ�ֶԵ�ͼ�ı༭
class map_editing :public abstract_page {
public:
	map_editing(int next_id, int w, int h, maps<show_maps_num>& my_maps);
	//virtual void update_maps()override;
	virtual bool get_keyboard_message()override;
	virtual void draw()override;
	//��ͼ�༭�����˳�ǰ�Ա༭���ĵ�ͼִ��д���ļ�����
	virtual int return_page_id()override;
	virtual ~map_editing();
private:
	//ʹ��maps��ʵ�ֵ�ͼ���漰����(���ô��ݣ�
	maps<show_maps_num>& my_maps;
};