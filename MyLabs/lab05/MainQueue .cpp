#include <iostream>
#include <cassert>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

struct Queue {
    Node* front;
    Node* rear;

    Queue() : front(nullptr), rear(nullptr) {}
};

void enqueue(Queue* queue, int value) {
    Node* newNode = new Node(value);

    if (!queue->front) {
        // ���� ������� �����, ����� ���� ���������� � ������, � ���������
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        // ����� ��������� ����� ���� � ����� �������
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (!queue->front) {
        // ������� �����
        cerr << "������� �����. ���������� ��������� dequeue." << endl;
        assert(false);
    }

    int value = queue->front->data;
    Node* temp = queue->front;

    if (queue->front == queue->rear) {
        // ������� �������� ������ ���� �������
        queue->front = nullptr;
        queue->rear = nullptr;
    }
    else {
        // ����� ������� ������ �������
        queue->front = queue->front->next;
    }

    delete temp;
    return value;
}

bool isEmpty(Queue* queue) {
    return queue->front == nullptr;
}

int main() {
    Queue myQueue;

    enqueue(&myQueue, 1);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 3);

    while (!isEmpty(&myQueue)) {
        cout << "Dequeued: " << dequeue(&myQueue) << endl;
    }

    return 0;
}
