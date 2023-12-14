#pragma once
//����Ϊ�����࣬Ϊ����ҳ�����ṩ�ӿں���
//���Ǵ��ڵĻ��࣬��Widget.h��ͨ����������ҳ�����ʵ�ֵĺ���ʵ��ҳ�����л�
class abstract_page {
public:
	//������һ��ҳ��id������ҳ��ĳ����
	abstract_page(int next_id,int w,int h);
	//���µ�ͼ���ݺ�������������������ʹ��ͬһ��maps�����ͼ���ݣ�
	//virtual void update_maps() = 0;
	//��Ϣ���뼰����������
	virtual bool get_keyboard_message() = 0;
	//���ƻ���
	virtual void draw() = 0;
	//������һ��ҳ�����(������-1ʱ��������)
	virtual int return_page_id() = 0;
	//�����������麯����
	virtual ~abstract_page() = 0;
protected:
	//������һ��ҳ���id
	int next_id;
	//����ҳ�����;
	int width, height;
	//ʹ��4����ͼ�浵
	static const int show_maps_num = 4;
};