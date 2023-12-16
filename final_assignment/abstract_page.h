#pragma once
//����Ϊ�����࣬Ϊ����ҳ�����ṩ�ӿں���
//���Ǵ��ڵĻ��࣬��Widget.h��ͨ����������ҳ�����ʵ�ֵĺ���ʵ��ҳ�����л�
class abstract_page {
public:
	//������һ��ҳ��id������ҳ��ĳ����
	abstract_page(int next_id, int w, int h) :next_id(next_id), width(w), height(h) {
	};
	//���µ�ͼ���ݺ�������������������ʹ��ͬһ��maps�����ͼ���ݣ�
	//virtual void update_maps() = 0;
	//��Ϣ���뼰����������
	virtual void get_keyboard_message() = 0;
	//���ƻ���
	virtual void draw() = 0;
	//������һ��ҳ�����(������-1ʱ��������)
	int return_page_id() {
		return next_id;
	}
	//�����������麯����
	virtual ~abstract_page() {};
	void set_next_id(int id) {
		next_id = id;
	}
protected:
	//������һ��ҳ���id
	int next_id;
	//����ҳ�����;
	int width, height;
	//ʹ��4����ͼ�浵
	static const int show_maps_num = 4;
};