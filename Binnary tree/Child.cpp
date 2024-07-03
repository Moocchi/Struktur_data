#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void displayTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";
    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    Node* root = nullptr;
    int data;
    std::cout << "Enter the data for the root node: ";
    std::cin >> data;
    root = createNode(data);

    std::cout << "Enter the data for the left child of the root node (-1 for no child): ";
    std::cin >> data;
    if (data != -1) {
        root->left = createNode(data);
    }

    std::cout << "Enter the data for the right child of the root node (-1 for no child): ";
    std::cin >> data;
    if (data != -1) {
        root->right = createNode(data);
    }

    std::cout << "Binary tree: ";
    displayTree(root);
    std::cout << std::endl;

    return 0;
}
