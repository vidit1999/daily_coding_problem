#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

/*
Given an integer k and a string s, find the length
of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest
substring with k distinct characters is "bcb".
*/

bool isValid(int count[], int k){
    int ch_count = 0;

    for(int i=0; i<ALPHABET_SIZE; i++){
        if(count[i] > 0){
            ch_count++;
        }
    }

    return ch_count <= k;
}

string longestSubstrDistinct(string s, int k){
    int count[ALPHABET_SIZE];
    memset(count, 0, sizeof(count));

    int start = 0, size = 0;
    int curr_start = 0, curr_end = 0;

    for(int i=0; i<s.length(); i++){
        count[s[i]-'a']++;
        curr_end++;

        while(!isValid(count, k)){
            count[s[curr_start]-'a']--;
            curr_start++;
        }

        if(curr_end - curr_start > size){
            start = curr_start;
            size = curr_end - curr_start;
        }
    }

    return s.substr(start, size);
}

// main function
int main(){
    cout << longestSubstrDistinct("abcba", 2) << "\n";
    cout << longestSubstrDistinct("abcba", 3) << "\n";
    cout << longestSubstrDistinct("abcba", 4) << "\n";
    return 0;
}
