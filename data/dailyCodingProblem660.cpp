#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

/*
You come across a dictionary of sorted words in a language you've never seen before.
Write a program that returns the correct order of letters in this language.

For example, given ['xww', 'wxyz', 'wxyw', 'ywx', 'ywz'],
you should return ['x', 'z', 'w', 'y'].
*/

class Graph{
	int V;
	vector<int>* adj;
	void topologicalSortHelper(int u, bool visited[], stack<int>& s);
	
	public:
	
	Graph(int V);
	~Graph();
	void addEdge(int u, int v);
	vector<char> topologicalSort();
};

Graph::Graph(int V){
	this->V = V;
	adj = new vector<int>[V];
}

Graph::~Graph(){ delete [] adj; }

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::topologicalSortHelper(int u, bool visited[], stack<int>& s){
	visited[u] = true;
	
	for(int v : adj[u]){
		if(!visited[v]){
			topologicalSortHelper(v, visited, s);
		}
	}
	
	s.push(u);
}

vector<char> Graph::topologicalSort(){
	bool *visited = new bool[V]();
	stack<int> s;
	
	for(int i=0; i<V; i++){
		if(!visited[i])
			topologicalSortHelper(i, visited, s);
	}
	
	vector<char> ans;
	
	while(!s.empty()){
		ans.push_back(s.top()+'a');
		s.pop();
	}
	
    reverse(ans.begin(), ans.end());
    
	return ans;
}

vector<char> orderLetters(vector<string> words){
	Graph g(ALPHABET_SIZE);
	
	for(int i=0; i<words.size()-1; i++){
		string w1 = words[i], w2 = words[i+1];
		
		for(int k=0; k<min(w1.length(), w2.length()); k++){
			if(w1[k] != w2[k]){
				g.addEdge(w1[k]-'a', w2[k]-'a');
			}
		}
	}
	
	return g.topologicalSort();
}

// main function
int main(){
	vector<string> words = {"xww", "wxyz", "wxyw", "ywx", "ywz"};
	for(char c : orderLetters(words)){
		cout << c << "\n";
	}
	return 0;
}