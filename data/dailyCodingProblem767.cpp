#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 256


/*
Given a word W and a string S, find
all starting indices in S which are anagrams of W.

For example, given that W is "ab",
and S is "abxaba", return 0, 3, and 4.
*/

bool checkSameArray(int arr1[ALPHABET_SIZE], int arr2[ALPHABET_SIZE]){
    for(int i=0; i<ALPHABET_SIZE; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}

vector<int> startingIndices(string w, string s){
    vector<int> ans;
    int arr1[ALPHABET_SIZE] = {0}, arr2[ALPHABET_SIZE] = {0};
    int i = 0;

    for(; i<w.length(); i++){
        arr1[w[i]]++;
        arr2[s[i]]++;
    }

    if(checkSameArray(arr1, arr2)){
        ans.push_back(0);
    }

    for(; i<s.length(); i++){
        arr1[s[i-w.length()]]--;
        arr1[s[i]]++;
        if(checkSameArray(arr1, arr2)){
            ans.push_back(i-w.length()+1);
        }
    }

    return ans;
}

// main function
int main(){
    auto ans = startingIndices("ab", "abxaba");

    for(int i : ans){
        cout << i << "\n";
    }

    return 0;
}
