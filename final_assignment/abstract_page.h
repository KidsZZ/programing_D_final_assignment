#pragma once
//����Ϊ�����࣬Ϊ����ҳ�����ṩ�ӿں���
//���Ǵ��ڵĻ��࣬��Widget.h��ͨ����������ҳ�����ʵ�ֵĺ���ʵ��ҳ�����л�
class abstract_page {
protected:
	//��������ҳ��ĳ����
	virtual void init() = 0;
	//���ƻ���
	virtual void draw() = 0;
	//������һ��ҳ�����
	virtual int return_page_id() = 0;
	//�����������麯����
	virtual ~abstract_page() = 0;
};