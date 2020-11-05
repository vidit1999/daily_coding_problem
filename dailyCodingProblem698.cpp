#include <bits/stdc++.h>
using namespace std;

/*
You are given a 2-d matrix where each cell consists of either /, \, or an empty space.
Write an algorithm that determines into how many regions the slashes divide the space.

For example, suppose the input for a three-by-six grid is the following:

\    /
 \  /
  \/
Considering the edges of the matrix as boundaries, this divides the grid
into three triangles, so you should return 3.
*/


void dfs(vector<string>& mat, int i, int j){
	if(
		i < 0 ||
		i >= mat.size() ||
		j < 0 ||
		j >= mat[0].length() ||
		mat[i][j] != ' '
	)
		return;

	mat[i][j] = '$';

	dfs(mat, i+1, j);
	dfs(mat, i, j+1);
	dfs(mat, i, j-1);
	dfs(mat, i-1, j);
}

int countRegions(vector<string>& mat){
	int count = 0;

	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[0].length(); j++){
			if(mat[i][j] == ' '){
				count++;
				dfs(mat, i, j);
			}
		}
	}

	return count;
}

// main function
int main(){
	vector<string> mat = {
		"\\    /",
		" \\  / ",
		"  \\/  ",
	};

	cout << countRegions(mat) << "\n";
	return 0;
}