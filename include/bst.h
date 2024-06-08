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
        T data;
        Node* leftBranch, * rightBranch;
        int occurrences;
    };

    Node* root;
    Node* addNode(Node* root, T data) {
        if (root == nullptr) {
            root = new Node;
            root->data = data;
            root->occurrences = 1;
            root->leftBranch = root->rightBranch = nullptr;
        } else if (root->data > data) {
            root->leftBranch = addNode(root->leftBranch, data);
        } else if (root->data < data) {
            root->rightBranch = addNode(root->rightBranch, data);
        } else {
            root->occurrences++;
        }
        return root;
    }
    int Depth(Node* root) {
        int hl, hr;
        if (root == nullptr) {
            return 0;
        }
        hl = Depth(root->leftBranch);
        hr = Depth(root->rightBranch);
        return std::max(hl, hr) + 1;
    }
    int Search(Node* root, T data) {
        if (root == nullptr) {
            return 0;
        } else if (data < root->data) {
            return Search(root->leftBranch, data);
        } else if (data > root->data) {
            return Search(root->rightBranch, data);
        } else {
            return root->occurrences;
        }
    }
    void Del(Node* root) {
        if (root == nullptr)
            return;
        Del(root->leftBranch);
        Del(root->rightBranch);
        delete root;
        root = nullptr;
    }

 public:
    BST() : root(nullptr) {}
    void addNew(T data) {
        root = addNode(root, data);
    }

    int depth() {
        return Depth(root) - 1;
    }

    int search(T data) {
        return Search(root, data);
    }
};

#endif  // INCLUDE_BST_H_
