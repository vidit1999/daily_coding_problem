#include <bits/stdc++.h>
using namespace std;

/*
Given a dictionary of words and a string made up of those words (no spaces),
return the original sentence in a list. If there is more than one possible
reconstruction, return any of them. If there is no possible reconstruction,
then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox',
and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond',
and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond]
or ['bedbath', 'and', 'beyond'].
*/


void sentenceReconsHelper(
    int i,
    string word,
    string& sentence,
    vector<string>& ans,
    vector<string>& words,
    unordered_set<string>& dictionary
){
    if(i == sentence.length()){
        if(word.empty()) ans = words;
        return;
    }

    word.push_back(sentence[i]);

    if(dictionary.find(word) != dictionary.end()){
        words.push_back(word);
        sentenceReconsHelper(i+1, "", sentence, ans, words, dictionary);
        words.pop_back();
    }

    sentenceReconsHelper(i+1, word, sentence, ans, words, dictionary);
}

vector<string> sentenceRecons(string sentence, unordered_set<string> dictionary){
    vector<string> ans, words;
    sentenceReconsHelper(0, "", sentence, ans, words, dictionary);
    return ans;
}

void testFunc(string sentence, unordered_set<string> dictionary){
    for(string word : sentenceRecons(sentence, dictionary)){
        cout << word << ", ";
    }
    cout << "\n";
}

// main function
int main(){
    testFunc("thequickbrownfox", {"quick", "brown", "the", "fox"});
    testFunc("bedbathandbeyond", {"bed", "bath", "bedbath", "and", "beyond"});
    return 0;
}
