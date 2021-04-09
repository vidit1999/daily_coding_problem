#include <bits/stdc++.h>
using namespace std;

/*
You are given a set of synonyms, such as (big, large) and (eat, consume).
Using this set, determine if two sentences with the same number of words are equivalent.

For example, the following two sentences are equivalent:

"He wants to eat food."
"He wants to consume food."
Note that the synonyms (a, b) and (a, c)
do not necessarily imply (b, c):
consider the case of (coach, bus) and (coach, teacher).

Follow-up: what if we can assume that (a, b) and (a, c) do in fact imply (b, c)?
*/

class WordSimilar{
    unordered_map<string, unordered_set<string>> umap;

    vector<string> splited(string& s){
        vector<string> ans;
        string temp = "";

        for(char c : s){
            if(c == ' '){
                if(!temp.empty()) ans.push_back(temp);
                temp = "";
            }
            else{
                temp += c;
            }
        }

        if(!temp.empty()) ans.push_back(temp);

        return ans;
    }

    public:
    void get_words(vector<pair<string, string>>& v){
        for(auto& it : v){
            // for the second problem
            for(auto s : umap[it.first]){
                umap[it.second].insert(s);
            }
            umap[it.first].insert(it.second);
        }
    }

    bool checkSimilarity(string s1, string s2){
        auto sp1 = splited(s1), sp2 = splited(s2);

        if(sp1.size() != sp2.size()) return false;

        for(int i=0; i<sp1.size(); i++){
            if(sp1[i] != sp2[i]){
                if(
                    (umap[sp1[i]].find(sp2[i]) == umap[sp1[i]].end()) &&
                    (umap[sp2[i]].find(sp1[i]) == umap[sp2[i]].end())
                ){
                    return false;
                }
            }
        }

        return true;
    }
};

// main function
int main(){
	vector<pair<string, string>> v = {{"big", "large"}, {"eat", "consume"}};
    WordSimilar ws;
    ws.get_words(v);
    cout << ws.checkSimilarity("He wants to eat food.", "He wants to eat food.") << "\n";
	return 0;
}