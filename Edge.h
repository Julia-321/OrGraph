//
// Created by Julia on 24-Jun-19.
//

#ifndef ORGRAPH_EDGE_H
#define ORGRAPH_EDGE_H


class Edge{
public:
    int from, to;
    double w;
    Edge(int from, int to, double w);
    bool operator<(Edge e);
};


#endif //ORGRAPH_EDGE_H
