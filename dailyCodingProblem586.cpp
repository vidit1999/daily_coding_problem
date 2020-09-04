#include <bits/stdc++.h>
using namespace std;

/*
You are given a list of (website, user) pairs that represent users visiting websites.
Come up with a program that identifies the top k pairs of websites with the greatest similarity.

For example, suppose k = 1, and the list of tuples is:

[('a', 1), ('a', 3), ('a', 5),
 ('b', 2), ('b', 6),
 ('c', 1), ('c', 2), ('c', 3), ('c', 4), ('c', 5)
 ('d', 4), ('d', 5), ('d', 6), ('d', 7),
 ('e', 1), ('e', 3), ('e': 5), ('e', 6)]

Then a reasonable similarity metric would most likely conclude that a and e are the most similar,
so your program should return [('a', 'e')].
*/

struct SimilarPair{
	pair<char, char> web_pair;
	int similarity_score;
};

class Compare{
	public:
	bool operator () (SimilarPair s1, SimilarPair s2){
		return s2.similarity_score > s1.similarity_score;
	}
};

int countSimilarity(unordered_set<int> s1, unordered_set<int> s2){
	int similar = 0, disimilar = 0;
	
	for(int w : s1){
		if(s2.find(w) != s2.end())
			similar++;
		else
			disimilar++;
	}
	
	for(int w : s2){
		if(s1.find(w) == s1.end())
			disimilar++;
	}
	
	return similar - disimilar;
}

void printKSimilar(vector<pair<char, int>> siteVisits, int k){
	unordered_map<char, unordered_set<int>> siteToVisiter;
	
	for(auto it : siteVisits)
		siteToVisiter[it.first].insert(it.second);
	
	set<pair<int, int>> alreadyConsidered;
	priority_queue<SimilarPair, vector<SimilarPair>, Compare> pq;
	
	for(auto it1 : siteToVisiter){
		for(auto it2 : siteToVisiter){
			if(
				(it1 != it2) &&
				(alreadyConsidered.find({it1.first, it2.first}) == alreadyConsidered.end()) &&
				(alreadyConsidered.find({it2.first, it1.first}) == alreadyConsidered.end())
			){
				pq.push({
					{it1.first, it2.first},
					countSimilarity(it1.second, it2.second)
				});
				alreadyConsidered.insert({it1.first, it2.first});
			}
		}
	}
	
	while(!pq.empty() && k > 0){
		auto similarPair = pq.top().web_pair;
		cout << similarPair.first << ", " << similarPair.second << "\n";
		pq.pop();
		k--;
	}
}

// main function
int main(){
	printKSimilar({
        {'a', 1}, {'a', 3}, {'a', 5},
        {'b', 2}, {'b', 6},
        {'c', 1}, {'c', 2}, {'c', 3}, {'c', 4}, {'c', 5},
        {'d', 4}, {'d', 5}, {'d', 6}, {'d', 7},
        {'e', 1}, {'e', 3}, {'e', 5}, {'e', 6}
    }, 3);
	return 0;
}