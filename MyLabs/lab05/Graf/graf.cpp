#include <iostream>
#include <vector>

using namespace std;

// Структура нода графа
struct Node {
    int value;
    vector<Node*> neighbors;
};

// Функция создания нового узла графа
Node* create_node(int value) {
    Node* node = new Node();
    node->value = value;
    return node;
}

// Функция добавления соседа к узлу графа
void add_neighbor(Node* node, Node* neighbor) {
    node->neighbors.push_back(neighbor);
}

// Функция обхода графа в глубину
void depth_first_traversal(Node* node) {
    if (node == nullptr) {
        return;
    }

    cout << node->value << " ";

    for (Node* neighbor : node->neighbors) {
        depth_first_traversal(neighbor);
    }
}

int main() {
    // Создание узлов графа
    Node* node1 = create_node(1);
    Node* node2 = create_node(2);
    Node* node3 = create_node(3);
    Node* node4 = create_node(4);

    // Добавление соседей
    add_neighbor(node1, node2);
    add_neighbor(node1, node3);
    add_neighbor(node2, node4);

    // Обход графа в глубину
    depth_first_traversal(node1);

    return 0;
}