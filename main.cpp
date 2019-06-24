#include <iostream>
#include "Graph.h"

#include <SFML/Window.hpp>


int main(){
    Graph g;
    std::cin >> g;
    std::cout << g << g.MinSpanTree();
    return 0;
}