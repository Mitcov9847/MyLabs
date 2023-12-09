#include <iostream>
#include <cassert>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

struct LinkedList {
    Node* first;
    Node* last;

    LinkedList() : first(nullptr), last(nullptr) {}
};

Node* insertAfter(LinkedList* list, Node* node, int value) {
    Node* newNode = new Node(value);

    if (!node) {
        // ������� � ������
        if (!list->first) {
            list->last = newNode;
        }
        else {
            list->first->prev = newNode;
            newNode->next = list->first;
        }
        list->first = newNode;
    }
    else {
        // ������� ����� ���������� ����
        newNode->next = node->next;
        newNode->prev = node;
        if (node->next) {
            node->next->prev = newNode;
        }
        else {
            // ���� ��������� ����� ���������� ����, ��������� last
            list->last = newNode;
        }
        node->next = newNode;
    }

    return newNode;
}

Node* insertBefore(LinkedList* list, Node* node, int value) {
    Node* newNode = new Node(value);

    if (!node) {
        // ������� � �����
        if (!list->last) {
            list->first = newNode;
        }
        else {
            list->last->next = newNode;
            newNode->prev = list->last;
        }
        list->last = newNode;
    }
    else {
        // ������� ����� ��������� �����
        newNode->prev = node->prev;
        newNode->next = node;
        if (node->prev) {
            node->prev->next = newNode;
        }
        else {
            // ���� ��������� ����� ������ �����, ��������� first
            list->first = newNode;
        }
        node->prev = newNode;
    }

    return newNode;
}

Node* find(LinkedList* list, int value) {
    Node* current = list->first;

    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

void remove(LinkedList* list, Node* node) {
    if (!node) {
        return;
    }

    if (node->prev) {
        node->prev->next = node->next;
    }
    else {
        // ���� ������� ������ ����, ��������� first
        list->first = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    }
    else {
        // ���� ������� ��������� ����, ��������� last
        list->last = node->prev;
    }

    delete node;
}

void assertNoCycles(LinkedList* list) {
    Node* current = list->first;

    while (current) {
        assert(current->prev != nullptr || current == list->first);
        assert(current->next != nullptr || current == list->last);
        current = current->next;
    }
}

int main() {
    LinkedList list;

    insertAfter(&list, nullptr, 1);
    insertAfter(&list, list.first, 2);
    insertBefore(&list, list.first, 3);
    insertAfter(&list, list.last, 4);

    assertNoCycles(&list);

    Node* foundNode = find(&list, 2);
    if (foundNode) {
        cout << "�������: " << foundNode->data << endl;
    }
    else {
        cout << "�� �������" << endl;
    }

    remove(&list, foundNode);
    assertNoCycles(&list);

    return 0;
}
