#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
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

Then a reasonable similarity metric would most likely conclude that a and e are
the most similar, so your program should return [('a', 'e')].
*/

struct SmilarSite{
    int count;
    pair<char, char> site_pair;
};


class Compare{
    public:
    bool operator () (SmilarSite s1, SmilarSite s2){
        return s1.count > s2.count;
    }
};

int countSimilarity(unordered_set<int>& uset1, unordered_set<int>& uset2){
    unordered_set<int> temp;

    for(int i : uset1) temp.insert(i);
    for(int i : uset2) temp.insert(i);

    // similarity = uset1.size() + uset2.size() - temp.size()
    // dissimilarity = 2*temp.size() - uset1.size() - uset2.size()
    // score = similarity - dissimilarity

    return 2*(uset1.size() + uset2.size()) - 3*temp.size();
}

vector<pair<char, char>> printKSimilar(vector<pair<char, int>> arr, int k){
    unordered_map<char, unordered_set<int>> site_user_map;
    set<pair<char, char>> visited;

    for(auto it : arr){
        site_user_map[it.first].insert(it.second);
    }

    priority_queue<SmilarSite, vector<SmilarSite>, Compare> pq;

    for(auto it1 : site_user_map){
        for(auto it2 : site_user_map){
            string find_string1 = "" + it1.first;
            if(
                it1.first != it2.first &&
                visited.find({it1.first, it2.first}) == visited.end() &&
                visited.find({it2.first, it1.first}) == visited.end()
            ){
                visited.insert({it1.first, it2.first});
                pq.push({countSimilarity(it1.second, it2.second), {it1.first, it2.first}});
                if(pq.size() > k) pq.pop();
            }
        }
    }

    vector<pair<char, char>> ans;

    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        ans.push_back(t.site_pair);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    vector<pair<char, int>> arr = {
        {'a', 1}, {'a', 3}, {'a', 5},
        {'b', 2}, {'b', 6},
        {'c', 1}, {'c', 2}, {'c', 3}, {'c', 4}, {'c', 5},
        {'d', 4}, {'d', 5}, {'d', 6}, {'d', 7},
        {'e', 1}, {'e', 3}, {'e', 5}, {'e', 6}
    };
    int k = 3;
    auto ans = printKSimilar(arr, k);

    for(auto p : ans){
        cout << p.first << ", " << p.second << "\n";
    }
    
    return 0;
}