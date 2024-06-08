// Copyright 2021 NNTU-CS
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    // поместите сюда свой код
    std::string word;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
    }
    char symbol;
    BST<std::string> Tree;
    while (file.get(symbol)) {
        if (isalpha(symbol)) {
            word += tolower(symbol);
        } else {
            Tree.addNew(word);
            word.clear();
        }
    }
    file.close();
    return Tree;
}
