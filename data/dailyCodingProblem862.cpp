#include <bits/stdc++.h>
using namespace std;

/*
A bridge in a connected (undirected) graph is an edge that,
if removed, causes the graph to become disconnected.
Find all the bridges in a graph.
*/

void bridgeHelper(
    int u, int& count,
    unordered_set<int>& visited,
    unordered_map<int, int>& low,
    unordered_map<int, int>& disc,
    unordered_map<int, int>& parent,
    unordered_map<int, vector<int>>& graph
){
    visited.insert(u);
    disc[u] = low[u] = ++count;

    for(int v : graph[u]){
        if(visited.find(v) == visited.end()){
            parent[v] = u;
            bridgeHelper(v, count, visited, low, disc, parent, graph);

            low[u] = min(low[u], low[v]);

            if(low[v] > disc[u])
                cout << "(" << u << ", " << v << ") ";
        } else if((parent.find(u) != parent.end()) && (v != parent[u])){
            low[u] = min(low[u], disc[v]);
        }
    }
}

void bridges(unordered_map<int, vector<int>>& graph){
    int count = 0;
    unordered_map<int, int> low, disc, parent;
    unordered_set<int> visited;

    for(auto node : graph){
        if(visited.find(node.first) == visited.end()){
            bridgeHelper(node.first, count, visited, low, disc, parent, graph);
        }
    }
    cout << "\n";
}

void printBridges(vector<pair<int, int>> edges){
    unordered_map<int, vector<int>> graph;

    for(auto edge : edges){
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    bridges(graph);
}

// main function
int main(){
    printBridges({
        {1, 0},
        {0, 2},
        {2, 1},
        {0, 3},
        {3, 4},
    });

    printBridges({
        {0, 1},
        {1, 2},
        {2, 3},
    });

    printBridges({
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {1, 4},
        {1, 6},
        {3, 5},
        {4, 5},
    });

    return 0;
}