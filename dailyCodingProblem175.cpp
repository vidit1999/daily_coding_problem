#include <bits/stdc++.h>
using namespace std;

/*
You are given a starting state start, a list of transition probabilities for
a Markov chain, and a number of steps num_steps. Run the Markov chain
starting from start for num_steps and compute the number of times we visited each state.

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

One instance of running this Markov chain might produce
{ 'a': 3012, 'b': 1656, 'c': 332 }.
*/

char getNextState(char curr, unordered_map<char, float> next_prob){
    float rand_num = float(rand())/float(RAND_MAX);
    char default_ret;

    for(auto it : next_prob){
        if(rand_num <= it.second)
            return it.first;
        rand_num -= it.second;
        default_ret = it.first;
    }

    return default_ret;
}


map<char, int> markovMap(char start, int steps, vector<tuple<char, char, float>> transition){
    unordered_map<char, unordered_map<char, float>> markov_map;

    for(auto it : transition) markov_map[get<0>(it)][get<1>(it)] = get<2>(it);

    map<char, int> visit_count;

    for(int i=0; i<steps; i++){
        char next_state = getNextState(start, markov_map[start]);
        visit_count[next_state]++;
        start = next_state;
    }

    return visit_count;
}
// main function
int main(){
    srand(time(0));
    
    vector<tuple<char, char, float>> transition = {
        make_tuple('a', 'a', 0.9),
        make_tuple('a', 'b', 0.075),
        make_tuple('a', 'c', 0.025),
        make_tuple('b', 'a', 0.15),
        make_tuple('b', 'b', 0.8),
        make_tuple('b', 'c', 0.05),
        make_tuple('c', 'a', 0.25),
        make_tuple('c', 'b', 0.25),
        make_tuple('c', 'c', 0.5)
    };

    for(int i=0; i<20; i++){
        for(auto it : markovMap('a', 5000, transition))
            cout << it.first << " ---> " << it.second << " ";
        
        cout << "\n----------------------------------\n";
    }

	return 0;
}