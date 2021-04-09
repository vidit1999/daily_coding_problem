#include <bits/stdc++.h>
using namespace std;

/*
Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a
sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2.
subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1.
subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute
path to a file within our file system. For example, in the second example above,
the longest absolute path is "dir/subdir2/subsubdir2/file2.ext",
and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format,
return the length of the longest absolute path to a file in the
abstracted file system. If there is no file in the system, return 0.

Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.
*/

vector<string> splitString(string s, char delim){
	vector<string> ans;
	
	string temp = "";
	
	for(char c : s){
		if(c == delim){
			if(!temp.empty()){
				ans.push_back(temp);
				temp = "";
			}
		}
		else{
			temp += c;
		}
	}
	
	if(!temp.empty()){
		ans.push_back(temp);
	}
	
	return ans;
}

string replaceChar(string s, char c1, string s1){
	string ans = "";

    for(char c : s){
        if(c == c1)
            ans += s1;
        else
            ans += c;
    }

    return ans;
}

int longestFileLength(string paths){
	int res = 0;
	int path_len[paths.length()+2];
	auto splited = splitString(paths, '\n');
	
	for(auto s : splited){
		string name = replaceChar(s, '\t', "");
		int height = s.length() - name.length();
		
        if(name.find('.') != string::npos){
			res = max(res, path_len[height] + int(name.length()));
		}
		else{
			path_len[height+1] = path_len[height] + name.length() + 1;
		}
	}
	
	return res;
}

// main function
int main(){
	string paths = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	cout << longestFileLength(paths) << "\n";
	return 0;
}