#include <iostream>
#include <vector>

using namespace std;

// ��������� ���� �����
struct Node {
    int value;
    vector<Node*> neighbors;
};

// ������� �������� ������ ���� �����
Node* create_node(int value) {
    Node* node = new Node();
    node->value = value;
    return node;
}

// ������� ���������� ������ � ���� �����
void add_neighbor(Node* node, Node* neighbor) {
    node->neighbors.push_back(neighbor);
}

// ������� ������ ����� � �������
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
    // �������� ����� �����
    Node* node1 = create_node(1);
    Node* node2 = create_node(2);
    Node* node3 = create_node(3);
    Node* node4 = create_node(4);

    // ���������� �������
    add_neighbor(node1, node2);
    add_neighbor(node1, node3);
    add_neighbor(node2, node4);

    // ����� ����� � �������
    depth_first_traversal(node1);

    return 0;
}