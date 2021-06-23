#include <bits/stdc++.h>
using namespace std;

/*
Implement a data structure which carries out the
following operations without resizing the underlying
array:

add(value): Add a value to the set of values.
check(value): Check whether a value is in the set.

The check method may return occasional false positives
(in other words, incorrectly identifying an element as
part of the set), but should always correctly identify
a true element.
*/

class SpecialDS{
	vector<bool> arr;

public:
	SpecialDS(int size);
	void add(int value);
	bool check(int value);
};

SpecialDS::SpecialDS(int size){
	arr = vector<bool>(size, false);
}

void SpecialDS::add(int value){
	int index = hash<string>()(to_string(value))%arr.size();
	arr[index] = true;
}

bool SpecialDS::check(int value){
	int index = hash<string>()(to_string(value))%arr.size();
	return arr[index];
}

// main function
int main(){
	SpecialDS sp(10);

	for(int i=30; i<=40; i++){
		sp.add(i);
	}

	for(int i=35; i<=45; i++){
		cout << i << " --> " << sp.check(i) << "\n";
	}

	return 0;
}