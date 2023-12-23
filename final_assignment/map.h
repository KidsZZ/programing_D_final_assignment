#pragma once
//单个map，使用maps进行管理
// 逻辑判断在此实现
//具体存储单张地图数据
#include <string>
#include<iostream>
#include<fstream>
#include<vector>
#include "houses.h"
#include "roads.h"
#include"lines.h"
#include "enum_lib.h"
#include <string>
class map 
{
public:
	//在maps初始化时调用下方此函数
	//传入存档路径，my_houses,与my_roads在此初始化
	map(std::wstring path, houses& my_house, roads& my_roads, int column, int row);

	//读入数据传入mapData二维数组
	// 此外对于文件的数据也进行了一次判断是否匹配
	//由于有maps进行了地图管理所以读进数据时更加准确
	void read_file();
	
	//首先写入该张地图的row和column
	//其次再写入相对于的map.txt文件
	void write_file();
	
	//渲染地图，调用roads与maps类中的draw函数，进行逻辑判断后绘图
	void draw(int width, int height, int x, int y);

	//给定坐标和房子id(road id 为0）
	void add_building(int x, int y, int house_type);

	// 给定坐标(删除房子和道路用一个函数）
	void delete_build(int x, int y,int house_type);

	//返回给定的地图id是否被编辑过
	bool is_edited();

	//判断若绘制道路的话属于哪种道路类型
	int select_road_type(int i,int j);

	//连接两地（最短路）(用于之后扩展)
	//bool connect_houses(int house_type1, int house_type2);

	//清除导航路线(用于之后扩展)
	//void clear_connnect_houses();

	//显示鼠标所停放地标图标所代表的房屋类型
	void show_house_type(std::string& name, int x, int y);

	
private:
	//计算给定的x，y所对应的格子(传入一个数组保存算出来的值)
	void tranlate_xy(int *ans, int x, int y);

	//记录(x,y)所对应的格子（二维数组中的准确位置）
	int real_coord[2];

	//获得两地在二维数组中的具体位置
	void get_position(int* ans, int house_type1, int house_type2);

	//用来记录两地在二维数组当中的具体位置
	int position[4];

	//通过my_houses、my_roads对象来调用其中函数对象
	houses my_houses;
	roads my_roads;

	//lines my_lines;
	//暂时可能不使用,后期用于绘制辅助线
	
	//用来存储当前地图的数据
	std::vector<std::vector<char>>mapData;

	//地图单元格列数
	int column;
	//地图单元格行数
	int row;

	//地图长宽
	int height;
	int width;

	//存档文件的路径
	std::wstring path;


	//以动态string来储存当前选中建筑的类型
	static std::string house_name;

	//用Building_num变量来对于此地图进行计数操作
	int Building_num;

	//用position_array二维数组来存储每个房屋的横纵坐标
	//从1开始算一直到4，与enum.lib中设定相同，方便应用
	int position_array[5][2];
	
	//以length来储存每格的边长
	int length;
};