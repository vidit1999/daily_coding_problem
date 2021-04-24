#include <bits/stdc++.h>
using namespace std;

/*
A group of houses is connected to the main water plant by means of a set of pipes.
A house can either be connected by a set of pipes extending directly to the plant,
or indirectly by a pipe to a nearby house which is otherwise connected.

For example, here is a possible configuration, where A, B, and C are houses, and arrows represent pipes:

A <--> B <--> C <--> plant
Each pipe has an associated cost, which the utility company would like to minimize.
Given an undirected graph of pipe connections, return the lowest
cost configuration of pipes such that each house has access to water.

In the following setup, for example, we can remove all but the pipes from plant to A,
plant to B, and B to C, for a total cost of 16.

pipes = {
    'plant': {'A': 1, 'B': 5, 'C': 20},
    'A': {'C': 15},
    'B': {'C': 10},
    'C': {}
}
*/

string minKeyValue(unordered_set<string> mstSet, unordered_map<string, int> keyValue){
	int min = INT_MAX;
	string minValue;
	
	for(auto it : keyValue){
		if(
			mstSet.find(it.first) == mstSet.end() &&
			it.second < min
		){
			min = it.second;
			minValue = it.first;
		}
	}
	
	return minValue;
}

int minSpanningTreeSum(unordered_map<string, vector<pair<string, int>>> pipes){
	unordered_set<string> mstSet;
	unordered_map<string, int> keyValue;
	unordered_map<string, pair<string, int>> parent;
	
	for(auto it : pipes) keyValue[it.first] = INT_MAX;
	keyValue["plant"] = 0;
	
	while(mstSet.size() != pipes.size()){
		auto minKey = minKeyValue(mstSet, keyValue);
		mstSet.insert(minKey);
		
		for(auto neighbour : pipes[minKey]){
			if(
				mstSet.find(neighbour.first) == mstSet.end() &&
				keyValue[neighbour.first] > neighbour.second
			){
				parent[neighbour.first] = {minKey, neighbour.second};
				keyValue[neighbour.first] = neighbour.second;
			}
		}
	}
	
	int totalCost = 0;
	
	for(auto it : parent){
		totalCost += it.second.second;
		cout << it.first << " to " << it.second.first << " , cost = " << it.second.second << "\n";
	}
		
	return totalCost;
}

// main function
int main(){
	cout << minSpanningTreeSum({
		{"plant", {{"A", 1}, {"B", 5}, {"C", 20}}},
		{"A", {{"C", 15}}},
		{"B", {{"C", 10}}},
		{"C", {}}
	}) << "\n";
	return 0;
}