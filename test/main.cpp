#include <cstdio>

class A {
public:
    A(int& value) : a(value) {}  // ʹ�ù��캯����ʼ���б���Աa�󶨵�һ������������
    int& a;
};

int main() {
    int value = 5;
    A obj(value);
    obj.a = 9;
    printf("%d", value);
    // ���ڳ�Աa�Ѿ�����ʼ�����󶨵�����value��
    return 0;
}
