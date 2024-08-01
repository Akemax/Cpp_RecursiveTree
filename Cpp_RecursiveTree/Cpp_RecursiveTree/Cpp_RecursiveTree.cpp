#include <iostream>

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* createNode(int value) 
{
    return new Node(value);
}

bool RecursiveBinarySearchTree(Node* node, int min, int max) 
{
    if (node == nullptr)
    {
        return true;
    }

    if (node->data < min || node->data > max)
    {
        return false;
    }

    return RecursiveBinarySearchTree(node->left, min, node->data - 1) &&
        RecursiveBinarySearchTree(node->right, node->data + 1, max);
}

bool isBinarySearchTree(Node* root)
{
    return RecursiveBinarySearchTree(root, INT_MIN, INT_MAX);
}

int main() 
{
    Node* root = createNode(50);
    root->left = createNode(20);
    root->right = createNode(60);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->right = createNode(7);
    root->left->left->left = createNode(0);

    if (isBinarySearchTree(root))
        std::cout << "Is a binary search tree." << std::endl;
    else
        std::cout << "Is not a binary search tree." << std::endl;

    return 0;
}