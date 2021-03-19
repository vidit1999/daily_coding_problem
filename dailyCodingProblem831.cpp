#include <bits/stdc++.h>
using namespace std;

/*
Given a string s and a list of words words, where each word
is the same length, find all starting indices of substrings
in s that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"],
return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"],
return [] since there are no substrings composed of "dog" and "cat" in s.

The order of the indices does not matter.
*/

vector<int> startingIndices(string s, vector<string> words){
    vector<int> ans;
    int word_len = words[0].length();
    int word_count = words.size();
    int total_len = word_count * word_len;

    unordered_map<string, int> umap;

    for(string word : words){
        umap[word]++;
    }

    for(int i=0; i<=s.length() - total_len; i++){
        unordered_map<string, int> temp(umap);
        int j = i, count = 0;

        while(j < i + total_len){
            string sub = s.substr(j, word_len);

            if(umap.find(sub) == umap.end() || temp[sub] == 0){
                break;
            }
            else{
                temp[sub]--;
                count++;
            }

            j += word_len;
        }

        if(count == word_count){
            ans.push_back(i);
        }
    }

    return ans;
}

// main function
int main(){
    string s = "dogcatcatcodecatdog";
    vector<string> words = {"cat", "dog"};

    for(int i : startingIndices(s, words)){
        cout << i << "\n";
    }

    return 0;
}
