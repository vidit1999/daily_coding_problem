#include <bits/stdc++.h>
using namespace std;

/*
Write an algorithm to justify text. Given a sequence of words and an integer line length k,
return a list of strings which represents each line, fully justified.

More specifically, you should have as many words as possible in each line.
There should be at least one space between each word. Pad extra spaces when
necessary so that each line has exactly length k. Spaces should be
distributed as equally as possible, with the extra spaces, if any,
distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words
["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly

*/

string justifyHelper(vector<string> temp, int k){
	int word_count = temp.size(), total_len = 0;
	string min_spaces = "", ans = "";
	
	for(string s : temp) total_len += s.length();
	
	int min_space_count = k - total_len;
	
	// if word_count > 1
	if(word_count > 1){
		for(int i=0; i<min_space_count/(word_count-1); i++){
			min_spaces += " ";
		}
		
		min_space_count %= (word_count-1);
		vector<string> space_dist(word_count-1, min_spaces);
		
		for(int i=0; i<min_space_count; i++){
			space_dist[i] += " ";
		}
		
		int curr = 0;
		
		for(string s : temp){
			ans += s;
			if(curr < word_count-1)
				ans += space_dist[curr++];
		}
	}
	else{
		ans += temp[0];
		for(int i=0; i<min_space_count; i++){
			min_spaces += " ";
		}
		ans += min_spaces;
	}
	
	return ans;
}

vector<string> justifyText(vector<string> words, int k){
	vector<string> ans, temp;
	int curr_size = 0;
	
	for(string word : words){
		if(curr_size != 0){
			curr_size++; // for space
		}
		
		curr_size += word.length();
		
		if(curr_size > k){
			ans.push_back(justifyHelper(temp, k));
			curr_size = word.length();
			temp.clear();
		}
		
		temp.push_back(word);
	}
	
	if(temp.size() != 0){
		ans.push_back(justifyHelper(temp, k));
	}
	
	return ans;
}

void testFunc(vector<pair<vector<string>, int>> v){
    for(auto ip : v){
        for(string s : justifyText(ip.first, ip.second)){
            cout << "$" << s << "$\n";
        }
        cout << "\n";
    }
}

// main function
int main(){
    testFunc({
        {{"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}, 16},
        {{"This", "is", "an", "example", "of", "text", "justification."}, 16},
        {{"What","must","be","acknowledgment","shall","be"}, 16},
        {{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}, 20},
    });
	return 0;
}