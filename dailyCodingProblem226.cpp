#include <bits/stdc++.h>
using namespace std;

/*
You come across a dictionary of sorted words in a language you've never seen before.
Write a program that returns the correct order of letters in this language.

For example, given ['xww', 'wxyz', 'wxyw', 'ywx', 'ywz'],
you should return ['x', 'z', 'w', 'y'].
*/

class Graph{
	int V;
	list<int> *adj;
	void topologicalSortUtil(int u, bool visited[], stack<int>& s);
	
	public:
	Graph(int V);
	~Graph();
	void addEdge(int u, int v);
	stack<int> topologicalSort();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

Graph::~Graph(){
	delete [] adj;
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::topologicalSortUtil(int u, bool visited[], stack<int>& s){
	visited[u] = true;
	
	for(int neighbour : adj[u]){
		if(!visited[neighbour])
			topologicalSortUtil(neighbour, visited, s);
	}
	
	s.push(u);
}

stack<int> Graph::topologicalSort(){
	bool *visited = new bool[V]();
	stack<int> s;
	
	for(int i=0; i<V; i++){
		if(!visited[i])
			topologicalSortUtil(i, visited, s);
	}
	
	while(!s.empty()){
		ans.push_back(s.top() + 'a');
		s.pop();
	}
	
	return s;
}

vector<char> letterOrders(vector<string> v){
	unordered_set<int> uset;
    for(string s : v) uset.insert(s.begin(), s.end());

    Graph g(uset.size());


    for(int i=0; i<v.size()-1; i++){
        string w1 = v[i], w2 = v[i+1];
        for(int j=0; j<min(w1.length(),w2.length()); j++){
            if(w1[j] != w2[j]){
                g.addEdge(w1[j]-'a', w2[j]-'a');
                break;
            }
        }
    }

    stack<int> s = g.topologicalSort();

    vector<char> ans;

    while(!s.empty()){
        ans.push_back(s.top()+'a');
        s.pop();
    }

    return ans;
}

// main function
int main(){
	for(char c : letterOrders({"xww", "wxyz", "wxyw", "ywx", "ywz"}))
		cout << c << "\n";
	return 0;
}