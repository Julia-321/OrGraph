//
// Created by Julia on 17-Jun-19.
//


#include <cmath>
#include <stdexcept>
#include <iomanip>
#include "Graph.h"

Graph::Graph(int v) : V(v) {matrix = std::vector <std::vector <double> >(V, std::vector <double>(V,NAN)); E = 0;}

Graph::Graph() {V = 0, E = 0, matrix.clear();}


double Graph::edge(int from, int to) const{
    if (from < 0 || from >= V || to < 0 || to >= V)
        throw std::invalid_argument("Vertice doesn't exists!");
    return matrix[from][to];
}

void Graph::set_edge(int from, int to, double w) {
    if (from < 0 || from >= V || to < 0 || to >= V)
        throw std::invalid_argument("Vertice doesn't exists!");
    if (!std::isnan(w))
        ++E;
    matrix[from][to] = w;
}

void Graph::delete_edge(int from, int to) {
    set_edge(from, to, NAN);
}



int Graph::getV() const{
    return V;
}


void Graph::printMatrix(std::ostream &os) const{
    os << V << "\n";

    os << std::setw(6) << "";     //print numbers of columns
    for (int i = 0; i < V; ++i)
        os << std::setw(6) << i;
    os << "\n";

    os << std::setw(6) << "";
    for (int i = 0; i < V; ++i)
        os << "------";
    os << "\n";


    for (int i = 0; i < V; ++i) {
        os << std::setw(5) << i << "|";   //print number of row
        for (int j = 0; j < V; ++j)
            if (std::isnan(edge(i,j)))
                os << std::setw(6) << "*";
            else
                os << std::setw(6) << edge(i, j);
        os << "\n";
    }
}

void Graph::readMatrix(std::istream &is) {
    int v;
    is >> v;
    *this = Graph(v);
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j){
            std::string s;
            is >> s;
            if (s == "*")
                set_edge(i, j, NAN);
            else
                set_edge(i, j, std::stod(s));
        }
}


std::ostream &operator<<(std::ostream &os, const Graph &graph){
    os << graph.V << " " << graph.E << "\n";
    for (int i = 0; i < graph.V; ++i)
        for (int j = 0; j < graph.V; ++j)
            if (!std::isnan(graph.edge(i,j)))
                os << i << " " << j << " " << graph.edge(i, j) << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Graph &graph) {
    int v, e;
    is >> v >> e;
    graph = Graph(v);
    for (int i = 0; i < e; ++i)
    {
        int from, to;
        double w;
        is >> from >> to >> w;
        graph.set_edge(from, to, w);
    }
    return is;
}

