// Copyright 2021 NNTU-CS

#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

template <typename T>
class BSTNode {
 public:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;

    BSTNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
 private:
    BSTNode<T>* root;

    void insertHelper(BSTNode<T>*& node, const T& value) {
        if (node == nullptr) {
            node = new BSTNode<T>(value);
        }
        else if (value < node->data) {
            insertHelper(node->left, value);
        }
        else if (value > node->data) {
            insertHelper(node->right, value);
        }
    }

    int depthHelper(BSTNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = depthHelper(node->left);
        int rightDepth = depthHelper(node->right);
        return std::max(leftDepth, rightDepth) + 1;
    }

    BSTNode<T>* searchHelper(BSTNode<T>* node, const T& value) {
        if (node == nullptr || node->data == value) {
            return node;
        } else if (value < node->data) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }

    BSTNode<T>* findMin(BSTNode<T>* node) {
        if (node->left == nullptr) {
            return node;
        }
        return findMin(node->left);
    }

    BSTNode<T>* removeHelper(BSTNode<T>*& node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        } else if (value < node->data) {
            node->left = removeHelper(node->left, value);
        } else if (value > node->data) {
            node->right = removeHelper(node->right, value);
        } else {
            if (node->left == nullptr) {
                BSTNode<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTNode<T>* temp = node->left;
                delete node;
                return temp;
            } else {
                BSTNode<T>* temp = findMin(node->right);
                node->data = temp->data;
                node->right = removeHelper(node->right, temp->data);
            }
        }
        return node;
    }

 public:
    BST() : root(nullptr) {}

    void insert(const T& value) {
        insertHelper(root, value);
    }

    int depth() {
        return depthHelper(root);
    }

    bool search(const T& value) {
        return searchHelper(root, value) != nullptr;
    }

    void remove(const T& value) {
        removeHelper(root, value);
    }
};
#endif  // INCLUDE_BST_H_

