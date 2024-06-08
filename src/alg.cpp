#include "bst.h"
#include <fstream>
#include <sstream>
#include <algorithm>

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string w;
        while (file >> w) {
            std::transform(w.begin(), w.end(), w.begin(), ::tolower);
            w.erase(std::remove_if(w.begin(), w.end(), ispunct), w.end());
            tree.insert(w);
        }
        file.close();
    }
    return tree;
}
