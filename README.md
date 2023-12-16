# Programing D final assignment

## 项目名称

简易校园导航系统

## 小组成员

郑喆宇，李佳徽

## 配置

### 语言

c++

### 图形库

easyX

### 开发工具

visual studio 2022

### 协作工具

git+github

## 项目预设

1. 通过easyX创建gui程序
2. 制定文件保存格式
3. 使用键盘输入

## 项目架构

1. map类中包含houses类和roads类，通过调用map的draw()函数调用houses和roads的draw()函数

## 窗口设计

使用三个窗口，首页窗口，地图编辑窗口，导航窗口

## 地图数据存放数据结构设计

### 地图物体的编号

0：无物体

1：道路

2~INF：各种建筑

### 举例

一行中每个数字空一格

```
2（有效地图数） 0（当前选择地图编号，从0开始）
0（地图编号）
3（行数） 3（列数）
1 1 1
2 0 3
0 1 1（储存建筑）
1（地图编号）
略
```

### 查找地图的方法

暂定通过逐行查找，知道找到索引值
