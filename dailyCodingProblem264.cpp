#include <bits/stdc++.h>
using namespace std;

/*
Given a set of characters C and an integer k, a De Bruijn sequence is a cyclic
sequence in which every possible k-length string of characters in C occurs exactly once.

For example, suppose C = {0, 1} and k = 3. Then our sequence should
contain the substrings {'000', '001', '010', '011', '100', '101', '110', '111'},
and one possible solution would be 00010111.

Create an algorithm that finds a De Bruijn sequence.
*/

unordered_set<string> seen;
vector<int> edges;

void dfs(string startingSeq, int k, string C){
    for(int i=0; i<k; i++){
        string str = startingSeq + C[i];
        if(seen.find(str) == seen.end()){
            seen.insert(str);
            dfs(str.substr(1), k, C);
            edges.push_back(i);
        }
    }
}

string deBruijinSeq(int k, string C){
	int n = C.length();
	
	string startingSeq(k-1, C[0]);
    dfs(startingSeq, n, C);

    string S;

    int l = pow(n, k);

    for(int i=0;i<l;i++){
        S += C[edges[i]];
    }

    S += startingSeq;

    return S;
}

// main function
int main(){
    cout << deBruijinSeq(3, "01") << "\n";
	return 0;
}