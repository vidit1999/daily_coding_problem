#include <bits/stdc++.h>
using namespace std;

/*
An 8-puzzle is a game played on a 3 x 3 board of tiles, with the ninth tile missing.
The remaining tiles are labeled 1 through 8 but shuffled randomly.
Tiles may slide horizontally or vertically into an empty space,
but may not be removed from the board.

Design a class to represent the board, and find a series of
steps to bring the board to the state [[1, 2, 3], [4, 5, 6], [7, 8, None]].
*/

struct Node{
	Node* parent;
	vector<vector<int>> mat;
	pair<int, int> pos;
	int cost, level;
};

Node* newNode(vector<vector<int>>& mat, pair<int, int> pos, pair<int, int> new_pos, int level, Node* parent){
	Node* node = new Node;
	
	node->parent = parent;
	node->mat = mat;
	node->cost = INT_MAX;
	node->level = level;
	swap(node->mat[pos.first][pos.second], node->mat[new_pos.first][new_pos.second]);
	node->pos = new_pos;
	
	return node;
}

bool isSafe(int x, int y, int N){
	return (
		x >= 0 && x < N &&
		y >= 0 && y < N
	);
}

int calculateCost(vector<vector<int>>& mat, vector<vector<int>>& goal){
	int cost = 0;
	
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[0].size(); j++){
			if(mat[i][j] && mat[i][j] != goal[i][j]){
				cost++;
			}
		}
	}
	
	return cost;
}

void printPathParent(Node* root){
	if(root){
		printPathParent(root->parent);
		for(int i=0; i<root->mat.size(); i++){
			for(int j=0; j<root->mat[0].size(); j++){
				cout << root->mat[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

struct Compare{
	bool operator() (Node* n1, Node* n2){
		return (n1->cost+n1->level) > (n2->cost+n2->level);
	}
};

void solve(vector<vector<int>>& initial, vector<vector<int>>& goal, pair<int, int> pos){
	Node* root = newNode(initial, pos, pos, 0, nullptr);
	root->cost = calculateCost(root->mat, goal);
	
	priority_queue<Node*, vector<Node*>, Compare> pq;
	pq.push(root);
	
	int dx[] = {0, 0, 1, -1};
	int dy[] = {-1, 1, 0, 0};
	int N = initial.size();
	
	while(!pq.empty()){
		auto t = pq.top(); pq.pop();
		
		if(t->cost == 0){
			printPathParent(t);
			return;
		}
		
		for(int i=0; i<4; i++){
			if(isSafe(t->pos.first + dx[i], t->pos.second + dy[i], N)){
				auto next_node = newNode(
					t->mat, t->pos,
					{t->pos.first + dx[i], t->pos.second + dy[i]},
					t->level+1, t
				);
				next_node->cost = calculateCost(next_node->mat, goal);
				pq.push(next_node);
			}
		}
	}
}

// main function
int main(){
	vector<vector<int>> initial = {
		{1, 2, 3},
		{5, 6, 0},
		{7, 8, 4}
	};
	
	vector<vector<int>> goal = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 0}
	};
	
	solve(initial, goal, {1, 2});
	
	return 0;
}