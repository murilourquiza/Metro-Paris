//
//  main.cpp
//  problem2
//
//  Created by Cristopher Freitas on 7/29/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#include <iostream>
#include "graph.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // initializing the map
    Graph * map = new Graph();
    
    // travelling from point s to t. 
    map->travel(1,11);
    return 0;
}
