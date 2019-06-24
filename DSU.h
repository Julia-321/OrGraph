//
// Created by Julia on 24-Jun-19.
//

#ifndef ORGRAPH_DSU_H
#define ORGRAPH_DSU_H

#include <vector>

class DSU {
private:
    std::vector <int> size, parent;
    int n;
public:
    explicit DSU(int n);
    int getPaternt(int v);
    bool unite(int v, int u);
};



#endif //ORGRAPH_DSU_H
