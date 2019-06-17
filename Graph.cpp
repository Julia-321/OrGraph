//
// Created by Julia on 17-Jun-19.
//


#include <cmath>
#include <stdexcept>
#include "Graph.h"

Graph::Graph(int v) : V(v) {matrix = std::vector <std::vector <double> >(V, std::vector <double>(V,NAN)); E = 0;}

double Graph::edge(int from, int to) noexcept(false) {
    if (from < 0 || from >= V || to < 0 || to >= V)
        throw std::invalid_argument("Vertice doesn't exists!");
    return matrix[from][to];
}
