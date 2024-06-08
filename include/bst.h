// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

template<typename T>

class BST {
 private:
    struct Node {
        T value;
        Node* l, * r;
        int z;
    };

    Node* root;
    Node* add(Node* root, T value) {
        if (root == nullptr) {
            root = new Node;
            root->value = value;
            root->z = 1;
            root->l = root->r = nullptr;
        } else if (root->value > value) {
            root->l = add(root->l, value);
        } else if (root->value < value) {
            root->r = add(root->r, value);
        } else {
            root->z++;
        }
        return root;
    }
    int depth(Node* root) {
        int ll, rr;
        if (root == nullptr) {
            return 0;
        }
        ll = depth(root->l);
        rr = depth(root->r);
        return std::max(ll, rr) + 1;
    }
    int search(Node* root, T value) {
        if (root == nullptr) {
            return 0;
        } else if (value < root->value) {
            return search(root->l, value);
        } else if (value > root->value) {
            return search(root->r, value);
        } else {
            return root->z;
        }
    }
    void Del(Node* root) {
        if (root == nullptr)
            return;
        Del(root->l);
        Del(root->r);
        delete root;
        root = nullptr;
    }

 public:
    BST() : root(nullptr) {}
    void add2(T value) {
        root = add(root, value);
    }

    int depth2() {
        return depth(root) - 1;
    }

    int search2(T value) {
        return search(root, value);
    }
};

#endif  // INCLUDE_BST_H_