#include"lines.h"


//���캯������ʼ������
lines::lines(int length, int width, int row, int column, int fixed_length)
{
	this->length = length;
	this->width = width;
	this->row = row;
	this->column;
    this->fixed_length;


}
//��������
lines::~lines()
{

}
//���ƺ��������Ʒָ��ߣ�x,y��Ϊ��ͼ���Ͻǵĵ�
void lines::draw(int x, int y)
{
   
    // ���㵥Ԫ���Ⱥ͸߶�,��Ϊ�����������Լ���һ��
    int cellLength = length / column;


    // ���ƽ���
    for (int i = 0; i <= column; i++) {
        line(x, (y+i * cellLength), width, (y+i * cellLength));
    }
    for (int i = 0; i <= row; i++) {
        line((x+i * cellLength), y, (x + i * cellLength), length);
        
    }
}
