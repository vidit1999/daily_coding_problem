#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

/*
Given a list of words, return the shortest unique prefix of each word.
For example, given the list:

dog
cat
apple
apricot
fish

Return the list:

d
c
app
apr
f
*/

struct Trie{
    bool is_eow;
    bool is_unq;
    Trie* children[ALPHABET_SIZE];
};

Trie* newNode(){
    auto root = new Trie;
    root->is_eow = false;
    root->is_unq = true;
    for(int i=0; i<ALPHABET_SIZE; i++){
        root->children[i] = nullptr;
    }
    return root;
}

void insert(Trie* root, string word){
    auto curr = root;
    
    for(char c : word){
        int i = c - 'a';
        if(!curr->children[i]){
            curr->children[i] = newNode();
        }
        else{
            curr->children[i]->is_unq = false;
        }
        curr = curr->children[i];
    }
    
    curr->is_eow = true;
}

string getShortestPrefix(Trie* root, string word){
    string ans = "";
    auto curr = root;
    
    for(char c : word){
        int i = c - 'a';
        ans += c;
        if(curr->children[i] && curr->children[i]->is_unq){
            break;
        }
        curr = curr->children[i];
    }
    
    return (ans == word) ? "" : ans;
}

vector<string> shortestPrefices(vector<string> words){
    auto root = newNode();
    for(string word : words){
        insert(root, word);
    }
    
    vector<string> ans;
    
    for(string word : words){
        ans.push_back(getShortestPrefix(root, word));
    }
    
    return ans;
}

// main function
int main(){
    vector<string> words = {
        "dog",
        "cat",
        "apple",
        "apricot",
        "fish"
    };
    
    for(string s : shortestPrefices(words)){
        cout << s << "\n";
    }
    
    return 0;
}