//此页面主要实现对存在的地图的导航
//左边放置地图，用于展示路径
//右边放置建筑，用于用户点击后展示连接

#pragma once
#include <vector>
#include <graphics.h>
#include "abstract_page.h"
#include "maps.h"
#include "button.h"
#include "picture_button.h"

class navigation_page :public abstract_page {
public:

	//构造函数
	navigation_page(int w, int h,maps& my_maps);

	//对基类虚函数的重载
	virtual void get_keyboard_message()override;
	virtual void draw()override;
	virtual ~navigation_page();
	virtual int return_page_id()override;

private:

	//使用maps类实现地图保存及操作(引用传递）
	maps& my_maps;

	//背景图片
	IMAGE* bk_img;

	//返回按键
	button* return_button;

	//左右模块尺寸
	int left_width, left_height;
	int right_width, right_height;

	 //放缩比例
	double scale;

	//地图实际坐标
	int map_real_x;
	int map_real_y;
	//地图实际长宽
	int map_width, map_height;

	//右功能菜单按钮属性
	//做成和地图编辑菜单差不多，当用户选择两个建筑的时候，就将其传入maps进行绘制路线
	std::vector<picture_button*> my_picture_button;
	//如果当前没有选建筑，就记录这个建筑
	//如果当前已经选了一个建筑，就调用maps
	//如果当前已经选了两个建筑，无法选择新建筑
	//如果点击选择的建筑，就删除该选择
	void set_now_select_building_id(int i);
	//记录当前选择的建筑
	int now_select_building[2];
	//记录当前选择建筑数，利于逻辑实现
	int now_select_building_num;
	// 一个建筑选项的长宽(指右边选项中的建筑）（外层尺寸）
	int single_object_width;
	int single_object_height;
};