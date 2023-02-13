//
//  graph.cpp
//  problem2
//
//  Created by Cristopher Freitas on 7/29/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#include "graph.hpp"

Graph::Graph(){
    distances.push_back({0,11,20,27,40,43,39,28,18,10,18,30,30,32});
    distances.push_back({11,0,9,16,29,32,28,19,11,4,17,23,21,24});
    distances.push_back({20,9,0,7,20,22,19,15,10,11,21,21,13,18});
    distances.push_back({27,16,7,0,13,16,12,13,13,18,26,21,11,17});
    distances.push_back({40,29,20,13,0,3,2,21,25,31,38,27,16,20});
    distances.push_back({43, 32, 22, 16, 3, 0, 4, 23, 28, 33, 41, 30, 17, 20});
    distances.push_back({39, 28, 19, 12, 2, 4, 0, 22, 25, 29, 38, 28, 13, 17});
    distances.push_back({28, 19, 15, 13, 21, 23, 22, 0, 9, 22, 18, 7, 25, 30});
    distances.push_back({18, 11, 10, 13, 25, 28, 25, 9, 0, 13, 12, 12, 23, 28});
    distances.push_back({10, 4, 11, 18, 31, 33, 29, 22, 13, 0, 20, 27, 20, 23});
    distances.push_back({18, 17, 21, 26, 38, 41, 28, 18, 12, 20, 0, 15, 35, 39});
    distances.push_back({30, 23, 21, 21, 27, 30, 28, 7, 12, 27, 15, 0, 31, 37});
    distances.push_back({30, 21, 13, 11, 16, 17, 13, 25, 23, 20, 35, 31, 0, 5});
    distances.push_back({32, 24, 18, 17, 20, 20, 17, 30, 28, 23, 39, 37, 5, 0});
    
    adj.push_back({0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    adj.push_back({1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0});
    adj.push_back({0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0});
    adj.push_back({0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0});
    adj.push_back({0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0});
    adj.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    adj.push_back({0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    adj.push_back({0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0});
    adj.push_back({0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0});
    adj.push_back({0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    adj.push_back({0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0});
    adj.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    adj.push_back({0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1});
    adj.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0});
    
    // red
    lines.push_back({3, 9, 11, 14});
    // blue
    lines.push_back({1, 2, 3, 4, 5, 6});
    // yellow
    lines.push_back({2, 5, 7, 8, 9, 10});
    // green
    lines.push_back({4, 8, 12, 13, 14});
}

// calculate time according to the approx distance given.
float Graph::calcTime(int distance){
    return (float(distance)/float(30))*60 ;
}

// get the possible lines for such station.
vector<int> Graph::getLines(int source, int target){
    vector<int> _lines;
    bool s = 0;
    bool t = 0;
    for(int i = 0; i < lines.size(); i++){
        for(int j = 0; j < lines[i].size(); j++){
            if(lines[i][j] == source){
                s = 1;
            } else if(lines[i][j] == target){
                t = 1;
            }
        }
        if(s && t){
            _lines.push_back(i);
        }
        s = 0;
        t = 0;
    }
    return _lines;
}


// change line between stations.
void Graph::changeLine(Node *node, int line){
    node->setLine(line);
    node->addCost(4);
}

// generate next possible childs.
vector<Node *> Graph::getNext(Node *node){
    vector<Node *> childs;
    // get the adjacent stations
    int station = node->getStation()-1;
    for(int i = 0; i < distances.size(); i++){
        if(adj[station][i] == 1){
            // check the lines for each stations
            vector<int> lines = getLines(station+1, i+1);
            vector<int> :: iterator itl = lines.begin();
            while(itl != lines.end()){
                // avoiding repetitions
                Node * prev = node->getParent();
                bool flag = false;
                if(prev != NULL){
                    if(prev->getStation() != i+1){
                        flag = false;
                    } else {
                        flag = true;
                    }
                }
                if(!flag){
                    // create the future possible nodes with costs.
                    Node * n = new Node(i+1,*itl+1);
                    n->setParent(node);
                    n->addCost(node->getCost());
                    n->addCost(calcTime(distances[station][i]));
                    // setting the expected cost from the point i to t;
                    n->g = calcTime(distances[i][this->t-1]);
                    // if there is a change of line, add this to the cost.
                    if(n->getLine() != node->getLine()){
                        n->addCost(4);
                    }
                    childs.push_back(n);
                }
                itl++;
            }
            
        }
    }
    return childs;
}

Node * Graph::move(vector<Node *> nodes){
    vector<Node *>::iterator itn = nodes.begin();
    Node * node = NULL;
    while(itn != nodes.end()){
        if((*itn)->isVisited() == false){
            if(node == NULL){
                node = *itn;
            } else {
                if(node->h() > (*itn)->h()){
                    (*itn)->visit();
                    node = *itn;
                }
            }
        }
        itn++;
    }
    return node;
}

// verify the actual state.
bool Graph::verify(Node *current, int target){
    if(current->getStation() == target){
        return true;
    } else {
        return false;
    }
}

// execute the travel between stations.
int Graph::travel(int s, int t){
    this->t = t;
    node = new Node(s, 0);
    node->setParent(NULL);
    cout << node->toString() << endl;
    
    while(!verify(node, t)){
        node = move(getNext(node));
        if(node == NULL){
            cout << "Solution not found" << endl;
            break;
        }
        cout << node->toString() << endl;;
    }
    
    return 0;
}