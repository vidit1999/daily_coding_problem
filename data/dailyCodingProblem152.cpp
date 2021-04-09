#include <bits/stdc++.h>
using namespace std;

/*
You are given n numbers as well as n probabilities that sum up to 1.
Write a function to generate one of the numbers with its corresponding probability.

For example, given the numbers [1, 2, 3, 4] and probabilities
[0.1, 0.5, 0.2, 0.2], your function should return 1 10% of the time,
2 50% of the time, and 3 and 4 20% of the time.

You can generate random numbers between 0 and 1 uniformly.
*/

int genNumWithProb(vector<int> arr, vector<float> prob){
	float rand_num = float(rand())/float(RAND_MAX);

	for(int i=0; i<prob.size(); i++){
		if(rand_num <= prob[i])
			return arr[i];
		rand_num -= prob[i];
	}
	
	return arr[0];
}

// main function
int main(){
	srand(time(0));
	
	vector<int> arr = {1, 2, 3, 4};
	vector<float> prob = {0.1, 0.5, 0.2, 0.2};
	unordered_map<int, int> occur_count;
	
	for(int i=0; i<1000; i++){
		occur_count[genNumWithProb(arr, prob)]++;
	}
	
	for(auto it : occur_count){
		cout << it.first << ", " << it.second << "\n";
	}
	
	return 0;
}