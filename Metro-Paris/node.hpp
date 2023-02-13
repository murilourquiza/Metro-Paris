//
//  node.hpp
//  problem2
//
//  Created by Cristopher Freitas on 7/29/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
    bool visited;
    float cost; // actual cost to get here.
    int line;
    int station;
    Node * prev;
    
public:
    Node(int station, int line);
    Node(const Node & other);
    // parent operations
    void setParent(Node * prev);
    Node * getParent();
    // cost operations
    void setCost(float cost);
    void addCost(float cost);
    float getCost();
    // station operations
    void setStation(int s);
    int getStation();
    // line operations
    void setLine(int l);
    int getLine();
    // printing the node to a format.
    string toString();
    // heuristic function.
    float h();
    // keeping track of the visited nodes.
    void visit();
    bool isVisited();
    float g; // heuristic estimation
};


#endif /* node_hpp */
