#include <bits/stdc++.h>
using namespace std;

/*
Given a string of words delimited by spaces, reverse the words in string.
For example, given "hello world here", return "here world hello"

Follow-up: given a mutable string representation,
can you perform this operation in-place?
*/

string reverseString(string s){
	vector<string> splited;
	string temp = "";
	
	for(char c : s){
		if(c == ' '){
			if(!temp.empty()){
				splited.push_back(temp);
				temp = "";
			}
		}
        else
            temp += c;
	}
	
	if(!temp.empty()){
		splited.push_back(temp);
		temp = "";
	}
	
	reverse(splited.begin(), splited.end());
	
	string ans = "";
	
	for(int i=0; i<splited.size(); i++){
		ans += splited[i];
		if(i != splited.size()-1) ans += ' ';
	}
	
	return ans;
}

void reverseInplace(string& s, int start, int end){
    while(start <= end){
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

void reverseStringInplace(string& s){
    int n = s.length();
    reverseInplace(s, 0, n-1);

    int start = 0, i;

    for(i=0; i<n; i++){
        if(s[i] == ' '){
            reverseInplace(s, start, i-1);
            start = i+1;
        }
    }

    reverseInplace(s, start, i-1);
}

// main function
int main(){
    string s = "hello world here";
    cout << "$" << s << "$\n";

    reverseStringInplace(s);
    cout << "$" << s << "$\n";
	
    cout << "$" << reverseString(s) << "$\n";
    
	return 0;
}