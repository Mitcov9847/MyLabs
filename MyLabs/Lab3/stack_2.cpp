#include <iostream>

#include <stdlib.h>
#include <iostream>

int* stackMemory1()
{
    int a = 1;
    return &a; // ���������� ��������� �� ��������� ���������� 'a'
}

int* stackMemory2()
{
    int b = 2;
    return &b; // ���������� ��������� �� ������ ��������� ���������� 'b'
}

int main()
{
    int* b = stackMemory1(); // b ��������� �� ������� ������
    int a1 = *b; // ��������� �������� �� ������, �� ������� ��������� b
    int* c = stackMemory2(); // c ��������� �� ������ ������� ������
    int a2 = *c; // ��������� �������� �� ������, �� ������� ��������� c
    int a3 = *b; // ��������� �������� �� ������, �� ������� ��������� b 

    std::cout << a1 << std::endl; // ������� �������� a1
    std::cout << a2 << std::endl; // ������� �������� a2
    std::cout << a3 << std::endl; // ������� �������� a3 
    std::cout << ((std::byte*)b - (std::byte*)c) << std::endl; // ������� ������� � ������� b � c

    return 0;
}

}
