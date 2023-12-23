#include"lines.h"


//���캯������ʼ������
lines::lines(int length, int width, int row, int column, int fixed_length)
{
    //����lines�������ݳ�Ա���г�ʼ������
	this->length = length;
	this->width = width;
	this->row = row;
    this->column = column;
    this->fixed_length = fixed_length;
}
//��������
lines::~lines()
{
    //���������ڴ�
    this->length = 0;
    this->width = 0;
    this->row = 0;
    this->column = 0;
    this->fixed_length = 0;

}
//���ƺ��������Ʒָ��ߣ�x,y��Ϊ��ͼ���Ͻǵĵ�
void lines::draw(int x, int y)
{
   
    // ���㵥Ԫ���Ⱥ͸߶�,��Ϊ�����������Լ���һ��
    int cellLength = length / column;


    // ���ƽ���
    for (int i = 0; i <= column; i++)
    {
        line(x, (y+i * cellLength), width, (y+i * cellLength));
    }
    for (int i = 0; i <= row; i++)
    {
        line((x+i * cellLength), y, (x + i * cellLength), length);
    }
}
