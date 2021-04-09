#include <bits/stdc++.h>
using namespace std;

/*
A step word is formed by taking a given word, adding a letter,
and anagramming the result. For example, starting with the
word "APPLE", you can add an "A" and anagram to get "APPEAL".

Given a dictionary of words and an input word, create a
function that returns all valid step words.
*/

bool checkStepWord(unordered_map<char, int> char_count, string& word){
    for(char c : word){
        char_count[c]--;
    }
    
    int one = 0;
    
    for(auto it : char_count){
        if(it.second == -1){
            one++;
        }
        else if(it.second != 0){
            return false;
        }
    }
    
    return (one == 1);
}

vector<string> stepWords(vector<string> dictionary, string word){
    unordered_map<char, int> char_count;
    
    for(char c : word){
        char_count[c]++;
    }
    
    vector<string> ans;
    
    for(string w : dictionary){
        if(checkStepWord(char_count, w)){
            ans.push_back(w);
        }
    }
    
    return ans;
}

// main function
int main(){
    vector<string> dictionary = {"APPEAL", "APPLAE", "APPLAA", "ALLPP", "ALPPAE"};
    string word = "APPLE";
    
    for(string w : stepWords(dictionary, word)){
        cout << w << "\n";
    }
    
    return 0;
}