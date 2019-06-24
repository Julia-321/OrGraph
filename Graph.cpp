//
// Created by Julia on 17-Jun-19.
//


#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include "Graph.h"
#include "DSU.h"


Graph::Graph(int v) : V(v) {g = std::vector <std::vector <Edge> >(V); E = 0;}

Graph::Graph() {V = 0, E = 0, g.clear();}



void Graph::add_edge(int from, int to, double w) {
    if (from < 0 || from >= V || to < 0 || to >= V)
        throw std::invalid_argument("Vertice doesn't exists!");
    ++E;
    g[from].push_back(Edge(from, to, w));
}


int Graph::getV() const{
    return V;
}


void Graph::printMatrix(std::ostream &os) const{

    Matrix matr = getMatrix();

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
            if (std::isnan(matr[i][j]))
                os << std::setw(6) << "*";
            else
                os << std::setw(6) << matr[i][j];
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
            if (s != "*")
                add_edge(i, j, std::stod(s));
        }
}


std::ostream &operator<<(std::ostream &os, const Graph &graph){
    os << graph.V << " " << graph.E << "\n";
    for (int i = 0; i < graph.V; ++i)
        for (Edge e : graph.g[i])
            os << e.from << " " << e.to << " " << e.w << "\n";
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
        graph.add_edge(from, to, w);
    }
    return is;
}



Graph Graph::MinSpanTree() const {
    Graph tree(V);
    std::vector <Edge> edges = getEdges();
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    int ind = 0, cnt = 0;
    for (; cnt < V-1 && ind < E; ++cnt) {
        for (; ind < E && !dsu.unite(edges[ind].from, edges[ind].to); ind++);
        if (ind < E)
            tree.add_edge(edges[ind]);
    }
    return tree;
}

Matrix Graph::getMatrix() const {
    Matrix matr(V, std::vector<double>(V, NAN));
    for (int i = 0; i < V; ++i)
        for (Edge e : g[i])
            matr[e.from][e.to] = e.w;
    return matr;
}

std::vector<Edge> Graph::getEdges() const {
    std::vector <Edge> edges;
    for (int i = 0; i < V; ++i)
        edges.insert(edges.end(), g[i].begin(), g[i].end());
    return edges;
}

void Graph::add_edge(Edge e) {
    add_edge(e.from, e.to, e.w);
}


