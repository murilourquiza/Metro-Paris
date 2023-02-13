//
//  graph.hpp
//  problem2
//
//  Created by Cristopher Freitas on 7/29/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <iostream>
#include <vector>
#include "node.hpp"

using namespace std;

class Graph {

private:
    vector<vector<int>> distances;
    vector<vector<int>> adj;
    vector<vector<int>> lines;
    int t; // target
    Node * node;
    
protected:
    float calcTime(int distance);
    bool verify(Node * current, int target);
    void changeLine(Node * node, int line);
    vector<int> getLines(int source, int target);
    vector<Node *> getNext(Node * node);
    Node * move(vector<Node *> nexts);
public:
    Graph();
    int travel(int s, int t);
};

#endif /* graph_hpp */
