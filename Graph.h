//
// Created by Julia on 17-Jun-19.
//

#ifndef ORGRAPH_GRAPH_H
#define ORGRAPH_GRAPH_H

#include <vector>
#include <iostream>
#include "Edge.h"

typedef  std::vector<std::vector<double>> Matrix;



class Graph {
private:
    int V, E;
    std::vector <std::vector<Edge> > g;
    Matrix getMatrix() const;
    std::vector <Edge> getEdges() const;
public:
    Graph();
    explicit Graph(int v);

    int getV() const;

    void add_edge(int from, int to, double w);
    void add_edge(Edge e);


    friend std::ostream &operator<<(std::ostream &os, const Graph &graph);
    friend std::istream &operator>>(std::istream &os, Graph &graph);

    void printMatrix(std::ostream &os = std::cout) const;
    void readMatrix(std::istream &os = std::cin);

    Graph MinSpanTree() const;
};



#endif //ORGRAPH_GRAPH_H
