#include <bits/stdc++.h>
using namespace std;

/*
Assume you have access to a function toss_biased()
which returns 0 or 1 with a probability that's not
50-50 (but also not 0-100 or 100-0).
You do not know the bias of the coin.

Write a function to simulate an unbiased coin toss.
*/

int toss_biased(){
	float num = float(rand())/float(RAND_MAX);
	if(num > 0.7) return 1;
	return 0;
}

int toss_unbiased(){
	int num1 = toss_biased(), num2 = toss_biased();
	
	if(num1 == 0 && num2 == 1)
		return 0;
	else if(num1 == 1 && num2 == 0)
		return 1;
	else
		return toss_unbiased();
}

// main function
int main(){
	srand(time(0));
	int test_iter = 100000;
	int arr[2] = {0};
	
	for(int i=0; i<test_iter; i++)
		arr[toss_biased()]++;
	
	cout << arr[0] << ", " << arr[1] << "\n";
	
	int arr1[2] = {0};
	
	for(int i=0; i<test_iter; i++)
		arr1[toss_unbiased()]++;
	
	cout << arr1[0] << ", " << arr1[1] << "\n";
	
	return 0;
}