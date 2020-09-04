#include <bits/stdc++.h>
using namespace std;

/*
Compute the running median of a sequence of numbers.
That is, given a stream of numbers, print out the median
of the list so far on each new element.

Recall that the median of an even-numbered list is
the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5],
your algorithm should print out:

2
1.5
2
3.5
2
2
2
*/

void printMedian(float arr[], int n){
	priority_queue<float, vector<float>, greater<float>> greaterPq;
	priority_queue<float> smallerPq;
	float med = arr[0];
	smallerPq.push(arr[0]);
	
	cout << med << "\n";
	
	for(int i=1; i<n; i++){
		int num = arr[i];
		if(smallerPq.size() > greaterPq.size()){
			if(med > num){
				greaterPq.push(smallerPq.top());
				smallerPq.pop();
				smallerPq.push(num);
			}
			else{
				greaterPq.push(num);
			}
			med = (smallerPq.top() + greaterPq.top())/2;
		}
		else if(smallerPq.size() < greaterPq.size()){
			if(med < num){
				smallerPq.push(greaterPq.top());
				greaterPq.pop();
				greaterPq.push(num);
			}
			else{
				smallerPq.push(num);
			}
			med = (smallerPq.top() + greaterPq.top())/2;
		}
		else{
			if(num < med){
				smallerPq.push(num);
				med = smallerPq.top();
			}
			else{
				greaterPq.push(num);
				med = greaterPq.top();
			}
		}
		
		cout << med << "\n";
	}
}

// main function
int main(){
	float arr[] = {2, 1, 5, 7, 2, 0, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printMedian(arr, n);
	return 0;
}