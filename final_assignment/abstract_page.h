#pragma once

//����Ϊ�����࣬Ϊ�ĸ�ҳ�����ṩ�ӿں���
//���Ǵ��ڵĻ��࣬��Widget.h��ͨ�������ĸ�ҳ�����ʵ�ֵĺ���ʵ��ҳ�����л�

class abstract_page {
public:

	//������һ��ҳ��id���ڳ�ʼ��ʱ��Ϊ�����ڳ�������ʱ���и���
	//����ҳ��ĳ����
	abstract_page(int next_id, int w, int h) :next_id(next_id), width(w), height(h) ,return_flag(false){
	};

	//���µ�ͼ���ݺ�������������������ʹ��ͬһ��maps�����ͼ���ݣ�
	//virtual void update_maps() = 0;
	
	//��Ϣ���պ���
	//���������Ϣ�����д���
	virtual void get_keyboard_message() = 0;

	//���ƻ���
	//ͨ��������ҳ������е����ݣ��ڽ��������Ϣʱ���£��������»���
	//��Ҫ��ȫ����ԭ���Ļ������»���
	virtual void draw() = 0;

	//������һ��ҳ�����(������EXITʱ��������)
	virtual int return_page_id() = 0;

	//������һ��ҳ���id
	//����ť�Ȳ���������һ��ҳ���ṩͳһ�Ľӿ�
	void set_next_id(int id) {
		return_flag = true;
		next_id = id;
	}

	//��ֹҳ���ͷ�ʱ��������
	//�����������麯����
	virtual ~abstract_page() {};

//�����е����ݳ�Ա����ÿ��ҳ��ͨ�õ�����
protected:

	//������һ��ҳ���id
	int next_id;

	//����ҳ�����;
	int width, height;

	//ʹ��4����ͼ�浵
	static const int show_maps_num = 4;

	//ȷ���ٴλص�ҳ�治������
	bool return_flag;
};











