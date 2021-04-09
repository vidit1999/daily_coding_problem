#include <bits/stdc++.h>
using namespace std;

/*
You are given a starting state start, a list of transition probabilities for a Markov chain,
and a number of steps num_steps. Run the Markov chain starting from start for num_steps and
compute the number of times we visited each state.

For example, given the starting state a, number of steps 5000,
and the following transition probabilities:

[
  ('a', 'a', 0.9),
  ('a', 'b', 0.075),
  ('a', 'c', 0.025),
  ('b', 'a', 0.15),
  ('b', 'b', 0.8),
  ('b', 'c', 0.05),
  ('c', 'a', 0.25),
  ('c', 'b', 0.25),
  ('c', 'c', 0.5)
]

One instance of running this Markov chain might
produce { 'a': 3012, 'b': 1656, 'c': 332 }.
*/

char nextState(char curr_state, unordered_map<char, vector<pair<char, float>>>& graph){
	float num = float(rand())/float(RAND_MAX);
	
	for(auto it : graph[curr_state]){
		if(it.second >= num)
			return it.first;
		num -= it.second;
	}
	
	return curr_state; // this will never reach
}

void printMarkovChain(char start, int steps, vector<pair<char, pair<char, float>>> chain){
	unordered_map<char, vector<pair<char, float>>> graph;
	
	for(auto it : chain){
		graph[it.first].push_back(it.second);
	}

	unordered_map<char, int> state_visit_count;
	
	for(int i=0; i<steps; i++){
		char next_state = nextState(start, graph);
		state_visit_count[next_state]++;
		start = next_state;
	}
	
	for(auto it : state_visit_count){
		cout << it.first << ", " << it.second << "\n";
	}
}

// main function
int main(){
    srand(time(0));

	vector<pair<char, pair<char, float>>> chain = {
		{'a', {'a', 0.9}},
		{'a', {'b', 0.075}},
		{'a', {'c', 0.025}},
		{'b', {'a', 0.15}},
		{'b', {'b', 0.8}},
		{'b', {'c', 0.05}},
		{'c', {'a', 0.25}},
		{'c', {'b', 0.25}},
		{'c', {'c', 0.5}},
	};
	
	char start = 'a';
	int steps = 5000;
	
	printMarkovChain(start, steps, chain);
	
	return 0;
}