//
// Created by Julia on 24-Jun-19.
//

#include <regex>
#include "DSU.h"

DSU::DSU(int n) : n(n) {
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; ++i)
        size[i] = 1, parent[i] = i;
}

int DSU::getPaternt(int v) {
    return (v == parent[v]) ? v : parent[v] = getPaternt(parent[v]);
}

bool DSU::unite(int v, int u) {
    int p1 = getPaternt(v), p2 = getPaternt(u);
    if (p1 == p2)
        return false;
    if (size[p1] < size[p2])
        std::swap(p1, p2);
    parent[p2] = p1;
    size[p1] += size[p2];
    return true;
}

