#include <iostream>
#include <stdlib.h>
#include <iostream>

int* stackMemory1()
{
    int a = 1;
    return &a; // Возвращаем указатель на локальную переменную 'a'
}

int* stackMemory2()
{
    int b = 2;
    return &b; // Возвращаем указатель на другую локальную переменную 'b'
}

int main()
{
    int* b = stackMemory1(); // b указывает на область памяти
    int a1 = *b; // Прочитать значение по адресу, на который указывает b
    int* c = stackMemory2(); // c указывает на другую область памяти
    int a2 = *c; // Прочитать значение по адресу, на который указывает c
    int a3 = *b; // Прочитать значение по адресу, на который указывает b 

    std::cout << a1 << std::endl; // Вывести значение a1
    std::cout << a2 << std::endl; // Вывести значение a2
    std::cout << a3 << std::endl; // Вывести значение a3 
    std::cout << ((std::byte*)b - (std::byte*)c) << std::endl; // Вывести разницу в адресах b и c

    return 0;
}

}
