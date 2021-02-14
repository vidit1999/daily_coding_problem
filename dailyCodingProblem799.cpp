#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

/*
Implement a PrefixMapSum class with the following methods:

insert(key: str, value: int): Set a given key's value in the map.
If the key already exists, overwrite the value.

sum(prefix: str): Return the sum of all values of keys that begin with a given prefix.
For example, you should be able to run the following code:

mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5
*/

struct Trie{
    string eow;
    Trie* childern[ALPHABET_SIZE];
};

Trie* newNode(){
    auto root = new Trie;
    root->eow = "$";
    for(int i=0; i<ALPHABET_SIZE; i++){
        root->childern[i] = nullptr;
    }
    return root;
}

class PrefixMapSum{
    Trie* root;
    int sumUtil(Trie* root);
    
    public:
    PrefixMapSum();
    void insert(string key, int value);
    int sum(string prefix);
};

int PrefixMapSum::sumUtil(Trie* curr){
    int ans = 0;
    
    if(!curr) return ans;
    
    if(curr->eow != "$") ans += stoi(curr->eow);
    
    for(int i=0; i<ALPHABET_SIZE; i++){
        ans += sumUtil(curr->childern[i]);
    }
    
    return ans;
}

PrefixMapSum::PrefixMapSum(){
    root = newNode();
}

void PrefixMapSum::insert(string key, int value){
    auto curr = root;
    
    for(char c : key){
        int index = c - 'a';
        if(!curr->childern[index]){
            curr->childern[index] = newNode();
        }
        curr = curr->childern[index];
    }
    
    curr->eow = to_string(value);
}

int PrefixMapSum::sum(string prefix){
    Trie* curr = root;
    
    for(char c : prefix){
        int index = c - 'a';
        if(!curr->childern[index]) return 0;
        curr = curr->childern[index];
    }
    
    return sumUtil(curr);
}

// main function
int main(){
    PrefixMapSum mapsum;
    
    mapsum.insert("columnar", 3);
    cout << mapsum.sum("col") << "\n";

    mapsum.insert("column", 2);
    cout << mapsum.sum("col") << "\n";
    
    mapsum.insert("colour", 7);
    cout << mapsum.sum("col") << "\n";
    
    return 0;
}