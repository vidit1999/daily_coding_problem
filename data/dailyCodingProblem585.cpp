#include <bits/stdc++.h>
#define M 4
#define N 4
using namespace std;

/*
Given an N by M matrix consisting only of 1's and 0's,
find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]
Return 4.
*/

int maxAreaHist(int row[]){
	stack<int> s;
	int t, max_area = 0, area_with_top = 0, i = 0;
	
	while(i < N){
		if(s.empty() || row[s.top()] <= row[i])
			s.push(i++);
		else{
			int t = s.top();
			s.pop();
			area_with_top = row[t] * ((s.empty())? i : (i - s.top() - 1));
			max_area = max(max_area, area_with_top);
		}
	}
	
	while(!s.empty()){
		int t = s.top();
		s.pop();
		area_with_top = row[t] * ((s.empty())? i : (i - s.top() - 1));
		max_area = max(max_area, area_with_top);
	}
	
	return max_area;
}

int maxAreaRect(int mat[M][N]){
	int res = maxAreaHist(mat[0]);
	
	for(int i=1;i<M;i++){
		for(int j=0;j<N;j++){
			if(mat[i][j])
				mat[i][j] += mat[i-1][j];
			res = max(res, maxAreaHist(mat[i]));
		}
	}
	
	return res;
}

// main function
int main(){
	int mat[M][N] = {
		{1, 0, 0, 0},
		{1, 0, 1, 1},
		{1, 0, 1, 1},
		{0, 1, 0, 0}
	};
	
	cout << maxAreaRect(mat) << "\n";
	return 0;
}