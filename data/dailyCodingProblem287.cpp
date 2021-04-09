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

Then a reasonable similarity metric would most likely conclude 
that a and e are the most similar, so your program should return [('a', 'e')].
*/

struct SimilarPair{
	pair<char, char> web_pair;
	int similarity;
};

class Compare{
	public:
	bool operator() (SimilarPair s1, SimilarPair s2){
		return s2.similarity > s1.similarity;
	}
};


int similarityScore(unordered_set<int> s1, unordered_set<int> s2){
	int similar = 0; // similarity => len(A intersection B)
	int disimilar = 0; // dissimilarity => len((A - B) + (B - A))
	
    for(int w1 : s1){
		if(s2.find(w1) != s2.end())
			similar++;
        else
            disimilar++; // (A - B)
	}

    for(int w2 : s2){
        if(s1.find(w2) == s1.end())
            disimilar++; // (B - A)
    }
	return similar - disimilar;
}

void mostSimilar(vector<pair<char, int>> webUsers, int k){
	unordered_map<char, unordered_set<int>> webToUsers;
	
	for(auto webUser : webUsers){
		webToUsers[webUser.first].insert(webUser.second);
	}
	
	set<pair<char, char>> alreadyConsidered;
	priority_queue<SimilarPair, vector<SimilarPair>, Compare> pq;
	
	for(auto webToUser1 : webToUsers){
		for(auto webToUser2 : webToUsers){
			if(
				(webToUser1.first != webToUser2.first) &&
				(alreadyConsidered.find({webToUser1.first , webToUser2.first}) == alreadyConsidered.end()) &&
				(alreadyConsidered.find({webToUser2.first , webToUser1.first}) == alreadyConsidered.end())
			){
				pq.push({
					{webToUser1.first , webToUser2.first},
					similarityScore(webToUser1.second , webToUser2.second)
				});
			}
		}
	}
	
	while(!pq.empty() && k > 0){
		auto t = pq.top();
		cout << "(" << t.web_pair.first << ", " << t.web_pair.second << ")\n";
		pq.pop();
        k--;
	}
}

// main function
int main(){
    mostSimilar({
        {'a', 1}, {'a', 3}, {'a', 5},
        {'b', 2}, {'b', 6},
        {'c', 1}, {'c', 2}, {'c', 3}, {'c', 4}, {'c', 5},
        {'d', 4}, {'d', 5}, {'d', 6}, {'d', 7},
        {'e', 1}, {'e', 3}, {'e', 5}, {'e', 6}
    }, 1);
	return 0;
}