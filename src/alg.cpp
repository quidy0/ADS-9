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
    char chu;
    BST<std::string> Tree;
    while (file.get(chu)) {
        if (isalpha(chu)) {
            word += tolower(chu);
        }
        else {
            Tree.add2(word);
            word.clear();
        }
    }
    file.close();
    return Tree;
}