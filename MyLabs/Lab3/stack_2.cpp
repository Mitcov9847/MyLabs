#include <iostream>

#include <stdlib.h>
#include <iostream>

int* stackMemory1()
{
    int a = 1;
    return &a; //  указатель на лок переменную 'a'
}

int* stackMemory2()
{
    int b = 2;
    return &b; // Тоже самое, просто указатель на лок переменную'b'
}

int main()
{
    int* b = stackMemory1(); // b указывает на область памяти
    int a1 = *b; // Вывести значение по адрессу, на который указывает b
    int* c = stackMemory2(); // c указывает на другую область памяти
    int a2 = *c; // Вывести значение по адрессу, на который указывает  c
    int a3 = *b; // Вывести значение по адрессу, на который указывает  b 

    std::cout << a1 << std::endl; // Вывести a1
    std::cout << a2 << std::endl; // Вывести a2
    std::cout << a3 << std::endl; // Вывести a3 
    std::cout << ((std::byte*)b - (std::byte*)c) << std::endl; // Вывести разницу в адресах b и c

    return 0;
}

}
