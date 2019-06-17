//
// Created by Julia on 17-Jun-19.
//

#ifndef ORGRAPH_GRAPH_H
#define ORGRAPH_GRAPH_H

#include <vector>

class Graph {
private:
    int V, E;
    std::vector <std::vector<double> > matrix;
public:
    explicit Graph(int v);
    double edge(int from, int to);
};


#endif //ORGRAPH_GRAPH_H
