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
        } else if (value < node->data) {
            insertHelper(node->left, value);
        } else if (value > node->data) {
            insertHelper(node->right, value);
        }
    }
 public:
    BST() : root(nullptr) {}
    void insert(const T& value) {
        insertHelper(root, value);
    }
};
#endif  // INCLUDE_BST_H_

