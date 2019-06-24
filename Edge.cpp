//
// Created by Julia on 24-Jun-19.
//

#include "Edge.h"

Edge::Edge(int from, int to, double w) : from(from), to(to), w(w) {}

bool Edge::operator<(Edge e) {
    return w<e.w;
}