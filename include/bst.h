// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <fstream>
#include <iostream>

template <class T>
class MyBSTNode {
public:
    T data;
    int frequency;
    MyBSTNode* left;
    MyBSTNode* right;

    MyBSTNode(T value) : data(value), frequency(1), left(nullptr), right(nullptr) {}
};

template <class T>
class MyBST {
private:
    MyBSTNode<T>* root;

    void insertNode(MyBSTNode<T>*& node, const T& value);

    void inorderTraversal(MyBSTNode<T>* node) const;

public:
    MyBST();

    ~MyBST();

    void addElement(const T& value);

    void displayInorder() const;
};

#endif  // INCLUDE_BST_H_

src/alg.cpp

#include "bst.h"

MyBST<std::string> buildTree(const char* filename) {
    MyBST<std::string> tree;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return tree;
    }

    std::string word;
    while (file >> word) {
        for (char& c : word) {
            c = std::tolower(c);
            if (!isalpha(c)) {
                c = ' ';
            }
        }
        tree.addElement(word);
    }

    file.close();
    return tree;
}
#endif  // INCLUDE_BST_H_
