#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
You are given an array of length n + 1 whose elements belong to the set {1, 2, ..., n}.
By the pigeonhole principle, there must be a duplicate. Find it in linear time and space.
*/

// a duplicate number can appear more than two times
// For example : [1,2,3,4,3,5,3]
// soring method is valid but will take O(nlogn) time


// set method will take O(n) time and O(n) space
int duplicateElement(vector<int> array){
	unordered_set<int> uset;
	for(int i : array){
		if(uset.find(i) != uset.end())
			return i;
		uset.insert(i);
	}
	cout << "No duplicate element found.\n";
	return 0;
}

// duplicare number can be detected using O(n) time and in O(1) space
// using floyd tortoise hare algorithm
int duplicateElementFloyd(vector<int> array){
	int tortoise = array[0];
	int hare = array[0];
	
	do{
		tortoise = array[tortoise];
		hare = array[array[hare]];
	}while(tortoise != hare);
	
	int ptr1 = array[0];
	int ptr2 = tortoise;
	
	while(ptr1 != ptr2){
		ptr1 = array[ptr1];
		ptr2 = array[ptr2];
	}
	return ptr1;
}

// main function
int main(){
	cout << duplicateElementFloyd({1,2,3,4,3,5,3}) << "\n";
	return 0;
}