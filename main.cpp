#include <iostream>
#include "Graph.h"


int main() {
    try {
        Graph g(3);
        std::cout << g.edge(1, 5) << "\n";
        std::cout << g.edge(1, 2) << "\n";
    }
    catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }
    return 0;
}