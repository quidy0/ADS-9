#include "bst.h"
#include <fstream>
#include <sstream>
#include <algorithm>

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string wr;
        while (file >> wr) {
            std::transform(wr.begin(), wr.end(), wr.begin(), ::tolower);
            wr.erase(std::remove_if(wr.begin(), wr.end(), ispunct), wr.end());
            tree.insert(wr);
        }
        file.close();
    }
    return tree;
}
