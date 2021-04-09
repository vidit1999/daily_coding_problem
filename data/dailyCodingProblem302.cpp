#include <bits/stdc++.h>
#define M 3
#define N 6
using namespace std;

/*
You are given a 2-d matrix where each cell consists of either /, \, or an empty space.
Write an algorithm that determines into how many regions the slashes divide the space.

For example, suppose the input for a three-by-six grid is the following:

\    /
 \  /
  \/
Considering the edges of the matrix as boundaries,
this divides the grid into three triangles,
so you should return 3.
*/

bool isValid(int x, int y, vector<string> mat){
	return x >= 0 && x < M && y >= 0 && y < N && mat[x][y] != '\\' && mat[x][y] != '/';
}

void dfsUtil(int x, int y, bool visited[M][N], vector<string> mat){
	visited[x][y] = true;
	for(int i=-1; i<=1; i++){
		for(int j=-1; j <= 1; j++){
            if(abs(i) != abs(j))
                if(isValid(x+i, y+j, mat) && !visited[x+i][y+j])
                    dfsUtil(x+i, y+j, visited, mat);
		}
	}
}

int countSpaces(vector<string> mat){
	int count = 0;
	
	bool visited[M][N];
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			visited[i][j] = false;
		}
	}
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j] && mat[i][j] != '\\' && mat[i][j] != '/'){
				count++;
				dfsUtil(i, j, visited, mat);
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
		"  \\/  "
	};
	cout << countSpaces(mat) << "\n";
	return 0;
}