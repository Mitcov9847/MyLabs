#include <iostream>

#include <stdlib.h>
#include <iostream>

int* stackMemory1()
{
    int a = 1;
    return &a; // ¬озвращаем указатель на локальную переменную 'a'
}

int* stackMemory2()
{
    int b = 2;
    return &b; // ¬озвращаем указатель на другую локальную переменную 'b'
}

int main()
{
    int* b = stackMemory1(); // b указывает на область пам€ти
    int a1 = *b; // ѕрочитать значение по адресу, на который указывает b
    int* c = stackMemory2(); // c указывает на другую область пам€ти
    int a2 = *c; // ѕрочитать значение по адресу, на который указывает c
    int a3 = *b; // ѕрочитать значение по адресу, на который указывает b 

    std::cout << a1 << std::endl; // ¬ывести значение a1
    std::cout << a2 << std::endl; // ¬ывести значение a2
    std::cout << a3 << std::endl; // ¬ывести значение a3 
    std::cout << ((std::byte*)b - (std::byte*)c) << std::endl; // ¬ывести разницу в адресах b и c

    return 0;
}

}
