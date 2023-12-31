//class picture_button用于放置有图片的选择框（用于地图编辑页的建筑及道路选项绘制）

#pragma once

#include <graphics.h>
#include <string>
#include <functional>

class picture_button {
public:

	//传入选项需要绘制的图片，介绍，回调函数
	//给定height要比width宽，且不保证一定处于给定范围内
	picture_button(std::wstring path,std::wstring exp,int width,int height,int x,int y,std::function<void()> my_fun);

	void checkMouseOver(int mouse_x, int mouse_y);

	void checkMouseClick(int mouse_x, int mouse_y);

	void draw();

	~picture_button();
private:

	//保存图片
	IMAGE* opt_img;

	//保存图片说明（放于图片下方）
	std::wstring exp;

	//回调函数
	std::function<void()> my_fun;

	//保存图片缩放
	double scale;

	//选项最外层尺寸
	int width, height;

	//鼠标是否在选项上
	bool is_over;

	//图片实际坐标
	int x, y;
	int real_img_x;
	int real_img_y;
	int real_img_length;

	//文字实际坐标
	int real_text_x;
	int real_text_y;
};
