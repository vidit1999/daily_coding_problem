#include <bits/stdc++.h>
using namespace std;

#define N 3
#define K 3

/*
A builder is looking to build a row of N houses that can be of K different colors.
He has a goal of minimizing cost while ensuring that no two neighboring houses are
of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to
build the nth house with kth color, return the minimum cost which achieves this goal.
*/

void costCalculateHelper(int i, int cost, int& min_cost, int prev_color, int house_colors[N][K]){
    if(i == N){
        min_cost = min(min_cost, cost);
        return;
    }

    for(int c=0; c<K; c++){
        if(c != prev_color && cost < min_cost){
            costCalculateHelper(i+1, cost+house_colors[i][c], min_cost, c, house_colors);
        }
    }
}

int costCalculate(int house_colors[N][K]){
    int cost = 0, min_cost = INT_MAX;
    int prev_color = -1;

    costCalculateHelper(0, cost, min_cost, prev_color, house_colors);

    return min_cost;
}

// 6

// main function
int main(){
    int house_colors[N][K] = {
		{1, 3, 2},
		{2, 4, 5},
		{5, 2, 3}
	};

    cout << costCalculate(house_colors) << "\n";
    
    return 0;
}