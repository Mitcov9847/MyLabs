//fльзования РЭЯ для автоматического удаления памяти 
#include <cassert>
#include <stdexcept>
#include <span>

template <typename T>
class DynamicArray {
private:
    T* data = nullptr;
    size_t capacity = 0;
    size_t length = 0;

public:
    DynamicArray() noexcept : data(nullptr), capacity(0), length(0) {}

    DynamicArray(size_t capacity) noexcept : data(new T[capacity]), capacity(capacity), length(0) {}

    DynamicArray(const DynamicArray& other) noexcept : data(new T[other.capacity]), capacity(other.capacity), length(other.length) {
        for (size_t i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }

    DynamicArray(DynamicArray&& other) noexcept : data(other.data), capacity(other.capacity), length(other.length) {
        other.data = nullptr;
        other.capacity = 0;
        other.length = 0;
    }

    // Деструктор освобождает память, выделенную для массива data.
    ~DynamicArray() {
        if (data != nullptr) {
            delete[] data;
        }
    }

    // Конструктор копирования копирует данные из другого объекта класса DynamicArray.
    DynamicArray(const DynamicArray& other) noexcept : data(new T[other.capacity]), capacity(other.capacity), length(other.length) {
        for (size_t i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }

    // Оператор присваивания копирует данные из другого объекта класса DynamicArray.
    DynamicArray& operator=(const DynamicArray& other) noexcept {
        if (this != &other) {
            if (data != nullptr) {
                delete[] data;
            }

            data = new T[other.capacity];
            capacity = other.capacity;
            length = other.length;

            for (size_t i = 0; i < length; i++) {
                data[i] = other.data[i];
            }
        }

        return *this;
    }

    // Конструктор перемещения перемещает данные из другого объекта класса DynamicArray.
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), capacity(other.capacity), length(other.length) {
        other.data = nullptr;
        other.capacity = 0;
        other.length = 0;
    }

    // Оператор перемещения перемещает данные из другого объекта класса DynamicArray.
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            if (data != nullptr) {
                delete[] data;
            }

            data = other.data;
            capacity = other.capacity;
            length = other.length;

            other.data = nullptr;
            other.capacity = 0;
            other.length = 0;
        }

        return *this;
    }

    // Метод add() увеличивает размер массива, если он заполнен.
    void add(T element) {
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
};

int main() {
    DynamicArray<int> arr;
    assert(arr.size() == 0);
    assert(arr.capacity() == 4);

    arr.add(5);
    assert(arr.size() == 1);
    assert(arr.capacity() == 4);

    arr.add(10);
    assert(arr.size() == 2);
    assert(arr.capacity() == 4);

    int el = arr[0];
    assert(el == 5);

    el = arr[1];
    assert(el == 10);

    // Копирование
    DynamicArray<int> arr2(arr);
    assert(arr2.size() == 2);
    assert(arr2.capacity() == 4);

    // Перемещение
    DynamicArray<int> arr3(std::move(arr2));
    assert(arr3.size() == 2);
    assert(arr3.capacity() == 4);

    return 0;
}