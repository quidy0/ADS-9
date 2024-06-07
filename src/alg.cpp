// Copyright 2021 NNTU-CS
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> Tree;
    std::ifstream file(filename);
    std::string strr = "";
    if (!file) {
        std::cout << "opening error" << std::endl;
        return Tree;
    }
    while (!file.eof()) {
        char sym = file.get();
        strr += sym;
    }
    for (char& c : strr) {
        c = tolower(c);
    }
    int len = strr.length();
    bool inWord = false;
    std::string tempStrr = "";
    for (int i = 0; i < len; i++) {
        if (strr[i] >= 'a' && strr[i] <= 'z') {
            inWord = true;
        } else {
            inWord = false;
        }
        if (inWord) {
            tempStrr += strr[i];
        } else {
            Tree.add(tempStrr);
            tempStrr = "";
        }
    }
    file.close();
    return Tree;
}