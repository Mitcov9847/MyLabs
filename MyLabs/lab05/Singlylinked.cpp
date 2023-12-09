#include <iostream>
#include <cassert>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

struct FindNodeResult {
    Node* foundNode;
    Node* previousNode;
};

struct LinkedList {
    Node* first;
    Node* last;
    size_t length;

    LinkedList() : first(nullptr), last(nullptr), length(0) {}
};

Node* insertAfter(LinkedList* list, Node* node, int value) {
    Node* newNode = new Node(value);

    if (!node) {
        // Вставка в начало
        newNode->next = list->first;
        list->first = newNode;
        if (!list->last) {
            // Если список был пуст, обновляем last
            list->last = newNode;
        }
    }
    else {
        // Вставка после указанного узла
        newNode->next = node->next;
        node->next = newNode;
        if (node == list->last) {
            // Если вставляем после последнего узла, обновляем last
            list->last = newNode;
        }
    }

    list->length++;
    return newNode;
}

FindNodeResult find(LinkedList* list, int value) {
    FindNodeResult result;
    result.foundNode = nullptr;
    result.previousNode = nullptr;

    Node* current = list->first;
    while (current) {
        if (current->data == value) {
            result.foundNode = current;
            break;
        }
        result.previousNode = current;
        current = current->next;
    }

    return result;
}

void removeAfter(LinkedList* list, Node* node) {
    if (!node) {
        // Удаление первого узла
        if (list->first) {
            Node* toRemove = list->first;
            list->first = toRemove->next;
            if (toRemove == list->last) {
                // Если удаляем последний узел, обновляем last
                list->last = nullptr;
            }
            delete toRemove;
            list->length--;
        }
    }
    else {
        // Удаление узла после указанного узла
        if (node->next) {
            Node* toRemove = node->next;
            node->next = toRemove->next;
            if (toRemove == list->last) {
                // Если удаляем последний узел, обновляем last
                list->last = node;
            }
            delete toRemove;
            list->length--;
        }
    }
}

void assertNoCycles(LinkedList* list) {
    size_t count = 0;
    Node* current = list->first;

    while (current) {
        if (count > list->length) {
            // Обнаружен цикл
            assert(false);
        }
        count++;
        current = current->next;
    }
}

int main() {
    LinkedList list;

    insertAfter(&list, nullptr, 1);
    insertAfter(&list, nullptr, 2);
    insertAfter(&list, nullptr, 3);
    insertAfter(&list, list.first, 4);
    insertAfter(&list, list.last, 5);

    assertNoCycles(&list);

    FindNodeResult result = find(&list, 4);
    if (result.foundNode) {
        cout << "Найдено: " << result.foundNode->data << endl;
        if (result.previousNode) {
            cout << "Предыдущий: " << result.previousNode->data << endl;
        }
        else {
            cout << "Нет предыдущего узла (найденный узел - первый узел)" << endl;
        }
    }
    else {
        cout << "Не найдено" << endl;
    }

    removeAfter(&list, result.previousNode);
    assertNoCycles(&list);

    return 0;
}
