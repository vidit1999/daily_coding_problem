#include <bits/stdc++.h>
using namespace std;

/*
Find an efficient algorithm to find the smallest distance
(measured in number of words) between any two given words in a string.

For example, given words "hello", and "world" and a text content of
"dog cat hello cat dog dog hello cat world", return 1 because there's
only one word "cat" in between the two words.
*/

vector<string> splitStringSpace(string& s){
    vector<string> ans;

    string temp = "";

    for(char c : s){
        if(c == ' '){
            if(!temp.empty()) ans.push_back(temp);
            temp.clear();
        }
        else{
            temp.push_back(c);
        }
    }

    if(!temp.empty()) ans.push_back(temp);
    
    return ans;
}

int minDistanceWords(string word1, string word2, string s){
    auto split = splitStringSpace(s);
    
    int prev_index_word1 = -1;
    int prev_index_word2 = -1;
    int min_distance = INT_MAX;

    for(int i=0; i<split.size(); i++){
        if(split[i] == word1){
            if(prev_index_word2 != -1){
                min_distance = min(min_distance, i - prev_index_word2 - 1);
            }
            prev_index_word1 = i;
        }
        else if(split[i] == word2){
            if(prev_index_word1 != -1){
                min_distance = min(min_distance, i - prev_index_word1 - 1);
            }
            prev_index_word2 = i;
        }
    }

    return min_distance;
}

// main function
int main(){
    cout << minDistanceWords("hello", "world", "dog cat hello cat dog dog hello cat world") << "\n";
    return 0;
}