#include <bits/stdc++.h>
using namespace std;

/*
You are given a set of synonyms, such as (big, large) and (eat, consume).
Using this set, determine if two sentences with the same number of words are equivalent.

For example, the following two sentences are equivalent:

"He wants to eat food."
"He wants to consume food."
Note that the synonyms (a, b) and (a, c) do not necessarily imply (b, c):
consider the case of (coach, bus) and (coach, teacher).

Follow-up: what if we can assume that (a, b) and (a, c) do in fact imply (b, c)?
*/

class WordSimilarity{
    unordered_map<string, unordered_set<string>> umap;
    vector<string> splitWords(string& s);
    bool dfs(string& s, string& f, unordered_set<string>& visited);
    
    public:
    void get_words(vector<pair<string, string>> word_pairs);
    bool checkSimilarity(string s1, string s2);
    bool checkSimilarityTransitive(string s1, string s2);
};

vector<string> WordSimilarity::splitWords(string& s){
    vector<string> split;
    string temp = "";
    
    for(char c : s){
        if(c == ' '){
            if(!temp.empty()) split.push_back(temp);
            temp.clear();
        }
        else{
            temp += c;
        }
    }
    
    if(!temp.empty()) split.push_back(temp);
    
    return split;
}

bool WordSimilarity::dfs(string& s, string& f, unordered_set<string>& visited){
    visited.insert(s);
    if(s == f) return true;
    
    for(auto nei : umap[s]){
        if(visited.find(nei) == visited.end()){
            if(dfs(nei, f, visited)){
                return true;
            }
        }
    }
    
    return false;
}

void WordSimilarity::get_words(vector<pair<string, string>> word_pairs){
    for(auto it : word_pairs){
        umap[it.first].insert(it.second);
        umap[it.second].insert(it.first);
    }
}

bool WordSimilarity::checkSimilarity(string s1, string s2){
    auto sp1 = splitWords(s1), sp2 = splitWords(s2);
    if(sp1.size() != sp2.size()) return false;
    
    for(int i=0; i<sp1.size(); i++){
        if(sp1[i] != sp2[i]){
            if(umap[sp1[i]].find(sp2[i]) == umap[sp1[i]].end())
                return false;
        }
    }
    
    return true;
}

bool WordSimilarity::checkSimilarityTransitive(string s1, string s2){
    auto sp1 = splitWords(s1), sp2 = splitWords(s2);
    if(sp1.size() != sp2.size()) return false;
    
    for(int i=0; i<sp1.size(); i++){
        if(sp1[i] != sp2[i]){
            unordered_set<string> visited;
            if(!dfs(sp1[i], sp2[i], visited)){
                return false;
            }
        }
    }
    
    return true;
}

// main function
int main(){
    WordSimilarity ws;
    ws.get_words({{"big", "large"}, {"eat", "consume"}, {"consume", "take"}});
    
    cout << ws.checkSimilarity("He wants to eat food.", "He wants to eat food.") << "\n";
    cout << ws.checkSimilarity("He wants to eat food.", "He wants to take food.") << "\n";
    cout << ws.checkSimilarityTransitive("He wants to eat food.", "He wants to take food.") << "\n";
    
    return 0;
}