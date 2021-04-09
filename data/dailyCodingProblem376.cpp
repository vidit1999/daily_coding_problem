#include <bits/stdc++.h>
using namespace std;

/*
You are writing an AI for a 2D map game. You are somewhere in a 2D grid,
and there are coins strewn about over the map.

Given the position of all the coins and your current position,
find the closest coin to you in terms of Manhattan distance.
That is, you can move around up, down, left, and right, but not diagonally.
If there are multiple possible closest coins, return any of them.

For example, given the following map, where you are x, coins are o,
and empty spaces are . (top left is 0, 0):

---------------------
| . | . | x | . | o |
---------------------
| o | . | . | . | . |
---------------------
| o | . | . | . | o |
---------------------
| . | . | o | . | . |
---------------------
return (0, 4), since that coin is closest. This map would be represented in our question as:

Our position: (0, 2)
Coins: [(0, 4), (1, 0), (2, 0), (3, 2)]
*/

pair<int, int> closestCoin(pair<int, int> ourPos, vector<pair<int, int>> coins){
	int distance = INT_MAX;
	pair<int, int> ans;
	
	for(auto coin : coins){
		int coin_distance = abs(ourPos.first - coin.first) + abs(ourPos.second - coin.second);
		if(coin_distance < distance){
			distance = coin_distance;
			ans = coin;
		}
	}
	
	return ans;
}

// main function
int main(){
	auto ans = closestCoin({0, 2}, {{0, 4}, {1, 0}, {2, 0}, {3, 2}});
	cout << ans.first << ", " << ans.second << "\n";
	return 0;
}