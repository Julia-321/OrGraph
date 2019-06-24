//
// Created by Julia on 17-Jun-19.
//

#ifndef ORGRAPH_GRAPH_H
#define ORGRAPH_GRAPH_H

#include <vector>
#include <iostream>

class Graph {
private:
    int V, E;
    std::vector <std::vector<double> > matrix;
public:


    Graph();
    explicit Graph(int v);

    int getV() const;

    double edge(int from, int to) const;
    void set_edge(int from, int to, double w);
    void delete_edge(int from, int to);

    friend std::ostream &operator<<(std::ostream &os, const Graph &graph);
    friend std::istream &operator>>(std::istream &os, Graph &graph);

    void printMatrix(std::ostream &os = std::cout) const;
    void readMatrix(std::istream &os = std::cin);
};



#endif //ORGRAPH_GRAPH_H
