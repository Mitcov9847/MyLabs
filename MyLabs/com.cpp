#include <iostream>

struct TwoInts
{
  int a;
  int b;
};

struct StructWithArray
{
  int arr[4];
  int* someNumber;
};

int main()
{
  TwoInts i2 = { };
  i2.a = 5;
  i2.b = 7;

  std::cout << i2.a << std::endl; // Вывод значения 5
  std::cout << i2.b << std::endl; // Вывод значения 7

  StructWithArray s = { };
  s.arr[0] = 10;

  StructWithArray s1 = { };
  s1.arr[0] = 15;

  StructWithArray* sPointer = &s;
  sPointer->arr[0] = 20;

  std::cout << s.arr[0] << std::endl; // Вывод значения 20
  s.arr[0] = 25;
  std::cout << s.arr[0] << std::endl; // Вывод значения 25
  sPointer->arr[0] = 30;
  std::cout << s.arr[0] << std::endl; // Вывод значения 30

  sPointer = &s1;
  sPointer->arr[0] = 35;
  std::cout << s.arr[0] << std::endl; // Вывод значения 35
  std::cout << s1.arr[0] << std::endl; // Вывод значения 35

  StructWithArray structArray[2] = { };
  structArray[0].arr[3] = 77;
  structArray[1].someNumber = &structArray[0].arr[3];

  sPointer = &s;
  int* pointer = &sPointer->arr[3];
  s.arr[3] = 72;
  std::cout << *pointer; // Вывод значения 72

  StructWithArray memory;
  memset(&memory, 0, sizeof(StructWithArray));
  return 0;
}
// Первая часть кода - объявление и использование структуры. Структура содержит два поля типа int.
// Вторая часть кода - использование указателя на структуру. Указатель используется для изменения значения элемента массива структуры.
// Третья часть кода - использование массива структур. Массив используется для хранения двух экземпляров структуры.
