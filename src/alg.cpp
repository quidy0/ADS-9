#include "bst.h"
#include <fstream>
#include <sstream>
#include <algorithm>

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string word;
        while (file >> word) {
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
            tree.insert(word);
        }
        file.close();
    }
    return tree;
}
