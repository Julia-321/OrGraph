#include <iostream>
#include "Graph.h"

#include <SFML/Window.hpp>


int main(int argc, char** argv){
    sf::Window window(sf::VideoMode(800, 600), "My window");
    Graph g;
    std::cin >> g;
    std::cout << g;
    return 0;
}