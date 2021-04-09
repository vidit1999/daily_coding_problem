#include <bits/stdc++.h>
using namespace std;

/*
You have access to ranked lists of songs for various users.
Each song is represented as an integer, and more preferred
songs appear earlier in each list. For example, the list
[4, 1, 7] indicates that a user likes song 4 the best,
followed by songs 1 and 7.

Given a set of these ranked lists, interleave them to
create a playlist that satisfies everyone's priorities.

For example, suppose your input is {[1, 7, 3], [2, 1, 6, 7, 9], [3, 9, 5]}.
In this case a satisfactory playlist could be [2, 1, 6, 7, 3, 9, 5].
*/

void topologicalSort(
    int u, vector<int>& v,
    unordered_map<int, vector<int>>& graph,
    unordered_set<int>& visited
){
    visited.insert(u);

    for(auto nei : graph[u]){
        if(visited.find(nei) == visited.end()){
            topologicalSort(nei, v, graph, visited);
        }
    }

    v.push_back(u);
}

vector<int> playlistGen(vector<vector<int>> ranks){
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    vector<int> ans;

    for(auto it : ranks){
        if(!it.empty())
            graph[it[0]] = {};

        for(int i=1; i<it.size(); i++){
            graph[it[i]].push_back(it[i-1]);
        }
    }

    for(auto it : graph){
        if(visited.find(it.first) == visited.end()){
            topologicalSort(it.first, ans, graph, visited);
        }
    }

    return ans;
}

// main function
int main(){
    vector<int> ans = playlistGen({
        {1, 7, 3},
        {2, 1, 6, 7, 9},
        {3, 9, 5},
    });

    for(int i : ans){
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}
