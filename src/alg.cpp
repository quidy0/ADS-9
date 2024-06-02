// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"


BetterBST<std::string> constructTree(const char* filename) {
  // поместите сюда свой код
 BetterBST<std::string> tree;
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
 tree.insert(word);
    }

 file.close();
    return tree;
}
