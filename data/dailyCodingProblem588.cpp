#include <bits/stdc++.h>
using namespace std;

/*
You have a large array with most of the elements as zero.

Use a more space-efficient data structure, SparseArray, that implements the same interface:

init(arr, size): initialize with the original large array and size.
set(i, val): updates index at i with val.
get(i): gets the value at index i.

*/

class SparseArray{
	int size;
	unordered_map<int, int> index_vals;
	
	public:
	void init(int arr[], int sz){
		size = sz;
		for(int i=0;i<size;i++)
			if(arr[i] != 0)
				index_vals[i] = arr[i];
	}
	
	void set(int i, int val){
		if(i >= 0 && i < size){
			index_vals[i] = val;
		}
	}
	
	int get(int i){
		return index_vals[i];
	}
};

// main function
int main(){
	srand(time(0));
	int arr[5];
	int size = 5;
	for(int i=0;i<size;i++){
		arr[i] = rand()%5;
		cout << i << "\t";
	}
	
	cout << "\n";
	
	for(int i=0;i<size;i++){
		cout << arr[i] << "\t";
	}
	
	cout << "\n\n";
	
	SparseArray sp;
	sp.init(arr, size);
	sp.set(1, 67);
	sp.set(4, -11);
	sp.set(10, 56);
	
	cout << sp.get(1) << "\n";
	cout << sp.get(4) << "\n";
	cout << sp.get(10) << "\n";
	cout << sp.get(5) << "\n";
	cout << sp.get(3) << "\n";
	cout << sp.get(0) << "\n";
	return 0;
}