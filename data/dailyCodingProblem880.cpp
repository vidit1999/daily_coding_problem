#include <bits/stdc++.h>
using namespace std;

/*
Given a string, split it into as few strings as possible
such that each string is a palindrome.

For example, given the input string racecarannakayak,
return ["racecar", "anna", "kayak"].

Given the input string abc, return ["a", "b", "c"].
*/

bool isPalindrome(string& s){
    int i = 0, j = s.length()-1;
    while(i < j){
        if(s[i++] != s[j--]){
            return false;
        }
    }
    return true;
}

bool palindromeCheckHelper(string& s, unordered_map<string, bool>& palindrome_map){
	if(palindrome_map.find(s) == palindrome_map.end()){
		palindrome_map[s] = isPalindrome(s);
	}
	
	return palindrome_map[s];
}

void minSplitPalindromeHelper(
    string& s, int start,
    vector<string>& v,
    vector<string>& ans,
	unordered_map<string, bool>& palindrome_map
){
	string check_all = s.substr(start);
	
    if(palindromeCheckHelper(check_all, palindrome_map)){
        v.push_back(check_all);
        if(ans.empty() || v.size() < ans.size()){
            ans = v;
        }
        v.pop_back();
        return;
    }
    
	for(int i=start+1; i<s.length(); i++){
	    string check_first = s.substr(start, i-start);
	    if(palindromeCheckHelper(check_first, palindrome_map)){
	        v.push_back(check_first);
	        minSplitPalindromeHelper(s, i, v, ans, palindrome_map);
	        v.pop_back();
	    }
	}
}

vector<string> minSplitPalindrome(string s){
    vector<string> ans, v;
	unordered_map<string, bool> palindrome_map;
    minSplitPalindromeHelper(s, 0, v, ans, palindrome_map);
    return ans;
}

// main function
int main(){
    auto ans = minSplitPalindrome("racecarannakayak");
    for(string s : ans){
        cout << s << "\n";
    }
	return 0;
}