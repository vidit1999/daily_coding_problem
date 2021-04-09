#include <bits/stdc++.h>
using namespace std;

/*
You are given n numbers as well as n probabilities that sum up to 1.
Write a function to generate one of the numbers with its corresponding probability.

For example, given the numbers [1, 2, 3, 4] and probabilities [0.1, 0.5, 0.2, 0.2],
your function should return 1 10% of the time, 2 50% of the time, and 3 and 4 20% of the time.

You can generate random numbers between 0 and 1 uniformly.
*/

// returns true with probability p and false with probability (1-p)
bool getRandom(float p){
	float randomFloat = float(rand())/float(RAND_MAX); // will give a random float bw [0,1]
	return randomFloat <= p;
}

// will return an element arr[i] with probability probs[i] for i in 0 to n-1
int randomSelectArray(int arr[], float probs[], int n){
	// if arr[i] is selected with probability probs[i] then return arr[i]
	// else check for the next element
	// if all fails (which is theoritically impossible) then return last element of arr
	for(int i=0;i<n-1;i++){
		if(getRandom(probs[i]))
			return arr[i];
	}
	return arr[n-1];
}

// main function
int main(){
	int arr[] = {1, 2, 3, 4};
	float probs[] = {0.1, 0.5, 0.2, 0.2};
	srand(time(0)); // seed the random numbers with current time
	int n = 4;
	for(int i=0;i<10;i++)
		cout << randomSelectArray(arr, probs, n) << "\n";
	return 0;
}