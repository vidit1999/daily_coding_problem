#include <bits/stdc++.h>
#include <functional>
using namespace std;

/*
Implement a data structure which carries out the following operations without resizing the underlying array:

add(value): Add a value to the set of values.
check(value): Check whether a value is in the set.

The check method may return occasional false positives (in other words,
incorrectly identifying an element as part of the set),
but should always correctly identify a true element.
*/

class BloomFilter{
	int size;
	bool *arr;
	
	public:
	BloomFilter(int size);
	~BloomFilter();
	void add(int value);
	bool check(int value);
};

BloomFilter::BloomFilter(int size){
	this->size = size;
	arr = new bool[size];
    memset(arr, false, size);
}

BloomFilter::~BloomFilter(){
	delete [] arr;
}

void BloomFilter::add(int value){
	int index = hash<int>{}(value);
    arr[index%size] = true;
}

bool BloomFilter::check(int value){
    int index = hash<int>{}(value);
    return arr[index%size];
}

// main function
int main(){
    BloomFilter b(11);
    for(int i=50;i<60;i++)
        b.add(i);
    
    for(int i=50;i<65;i++){
        cout << i << " -- " << b.check(i) << "\n";
    }

	return 0;
}