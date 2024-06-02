// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

#include <fstream>
#include <cctype>

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
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
        tree.add(word);
    }

    file.close();
    return tree;
}