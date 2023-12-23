//������ҳ�洰�ڣ�����ͬҳ�棨*��Ϊeasyx��֧�ֶര�ڣ�����ͨ���Բ�ͬ���ڼ�¼indexֵ���л���ͬ���ڣ�
//ʹ��abstract_pageͳһ���ڽӿڣ���ʹ��vector<abstract_page*>����ͳһ����͹���
//��run������ѭ����β�����´ε���ҳ��ţ�ʵ�ֽ��յ�ǰ��ҳ���ص��¸���ҳ��ֵ
//����ҳ��������ɾ�����ҳ�Ķ���ʵ�֣�����widget���н�������

#pragma once

#include <vector>
#include <string>
#include "abstract_page.h"
#include "maps.h"
#include "enum_lib.h"


class Widget {

public:

	//���캯��
	//���ĸ�ҳ������my_page,����ҳ�泤��ȣ���now_page_id��Ϊhome_page_id
	Widget(int w,int h);

	//����Ա����
	//ͨ����ѭ������ִ���û���Ϣ���룬������ͼ����Ȳ���
	//ʹ��GetTickCount()��ʵ�ֶ�̬��ʱ����֤60֡ˢ��Ƶ�ʲ��ᱻ��������ʱ��ı�
	void run();

	//�ر�Ӧ�ó�����ҳ
	//������������Ĺ��ܣ�ʵ�־�����ҳ����ռ���ͷ�
	void close();

private:
	
	//ʹ��vector���������ҳ�����ָ�룬ʹ�õ�����ļ̳����֪ʶ���е�����ת��
	//�����ָ��ͳһ��abstract_page���棬�����˶�̬��˼�룬����˴��븴����
	std::vector<abstract_page*> my_page;

	//ҳ��id����(������ʹ��ͳһmy_mpas����)
	//int previous_page_id = HOME_PAGE;
	
	//��ǰҳ��id
	//��run����������ĩβ��Ҫ���յ�ǰҳ��ķ���ֵ���£�ʹ��ҳ����л���Ϊ����
	int now_page_id;

	//ҳ��Ŀ�͸�
	//��Ҫ���ݸ�����ҳ��Ķ�����ɶ�ҳ���в�ͬԪ�صĶ�λ
	int width, height;

	//ʹ��4����ͼ�浵
	//Ŀǰδʹ�ã�����Ϊ��¼
	static const int show_maps_num = 4;

	//���洢���ͼ���ݵ��ļ��ĵ�ַ
	//��Ϊeasyx��Ҫ֧�ֿ��ַ���������Ŀ�е��ַ�������wstring���棬Ȼ��ʹ��.c_str()����ת��Ϊc�����ַ���
	const std::string path;

	//�����ͼ��Ϣ
	//��Ŀ�߼����Ķ���ʵ�ֶԵ�ͼ���ݵı��棬���ƺ�����
	//�ǳ���Ҫ
	//������һ���ԣ�ֻ��widget�б���һ�ݣ�����ͨ�����õķ�ʽ���ݸ�����ҳ��
	maps my_maps;

};










