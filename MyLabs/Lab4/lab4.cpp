#include <cassert>
#include <stdexcept>
#include <span>

template <typename T>
struct DynamicArray {
    T* data = nullptr;
    size_t capacity = 0;
    size_t length = 0;

    static DynamicArray createDynamicArrayWithCapacity(size_t capacity) {
        DynamicArray arr;
        arr.capacity = capacity;
        arr.data = new T[capacity];
        return arr;
    }

    static DynamicArray createDynamicArray() {
        return createDynamicArrayWithCapacity(4);
    }

    void addElement(T element) {
        if (length == capacity) {
            capacity *= 2;
            T* newData = new T[capacity];
            for (size_t i = 0; i < length; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }

        data[length++] = element;
    }

    T getElementAtIndex(size_t index) {
        assert(index < length);
        return data[index];
    }

    std::span<T> getCurrentSpan() {
        return std::span(data, length);
    }

    ~DynamicArray() {
        if (data != nullptr) {
            delete[] data;
        }
    }
};

void test1() {
    DynamicArray arr = DynamicArray::createDynamicArrayWithCapacity(10);
    assert(arr.capacity == 10);
}

void test2() {
    DynamicArray arr = DynamicArray::createDynamicArray();
    assert(arr.length == 0);
    arr.addElement(5);
    assert(arr.length == 1);
}

void test3() {
    DynamicArray arr = DynamicArray::createDynamicArrayWithCapacity(1);
    arr.addElement(5);
    assert(arr.capacity == 1);
    arr.addElement(10);
    assert(arr.capacity == 2);
    arr.addElement(20);
    assert(arr.capacity == 4);
}

void test4() {
    DynamicArray arr = DynamicArray::createDynamicArray();
    arr.addElement(5);
    int el = arr.getElementAtIndex(0);
    assert(el == 5);
}

void test5() {
    DynamicArray arr{};
    arr.addElement(5);
    arr.addElement(6);
    arr.addElement(7);

    std::span<int> span = arr.getCurrentSpan();

    assert(span.size() == 3);
    assert(span[0] == 5);
    assert(span[1] == 6);
    assert(span[2] == 7);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();

    // Дополнительный тест

    DynamicArray arr = DynamicArray::createDynamicArrayWithCapacity(1);
    arr.addElement(5);
    arr.addElement(6);

    // Попытка получить элемент за пределами массива
    try {
        int el = arr.getElementAtIndex(2);
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}