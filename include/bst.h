#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>
template <typename T>
class BST {
public:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };
private:
    Node* root;
    Node* addNode(Node*, T);
    int depthTree(Node*);
    int searchNode(Node*, T);
public:
    BST();
    void add(T);
    int depth();
    int search(T);
};
template <typename T>
BST <T>::BST() : root(nullptr) {}
template <typename T>
typename BST <T>::Node* BST <T>::addNode(Node* currentNode, T value) {
    if (currentNode == nullptr) {
        currentNode = new Node;
        currentNode->value = value;
        currentNode->count = 1;
        currentNode->left = currentNode->right = nullptr;
    }
    else if (currentNode->value > value) {
        currentNode->left = addNode(currentNode->left, value);
    }
    else if (currentNode->value < value) {
        currentNode->right = addNode(currentNode->right, value);
    }
    else {
        currentNode->count++;
    }
    return currentNode;
}
template <typename T>
void BST <T>::add(T value) {
    root = addNode(root, value);
}
template <typename T>
int BST<T>::depthTree(Node* currentNode) {
    if (currentNode == nullptr) {
        return 0;
    }
    else {
        int leftDepth = depthTree(currentNode->left);
        int rightDepth = depthTree(currentNode->right);
        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        }
        else {
            return rightDepth + 1;
        }
    }
}
template <typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}
BST<std::string> makeTree(const char* filename);
template <typename T>
int BST<T>::searchNode(Node* currentNode, T val) {
    if (currentNode == nullptr)
        return 0;
    else if (currentNode->value == val)
        return currentNode->count;
    else if (currentNode->value > val)
        return searchNode(currentNode->left, val);
    else
        return searchNode(currentNode->right, val);
}
template <typename T>
int BST<T>::search(T v) {
    return searchNode(root, v);
}

#endif  // INCLUDE_BST_H_