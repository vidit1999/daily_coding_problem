#include <bits/stdc++.h>
using namespace std;

/*
Use a more space-efficient data structure, SparseArray, that implements the same interface:

init(arr, size): initialize with the original large array and size.
set(i, val): updates index at i with val.
get(i): gets the value at index i
*/

class SparseArray{
	unordered_map<int, int> array_map;
	int size;
	
	public:
	
	void init(int arr[], int size);
	void set(int i, int val);
	int get(int i);
};

void SparseArray::init(int arr[], int size){
	array_map.clear();
	this->size = size;
	
	for(int i=0; i<size; i++){
		if(arr[i] != 0){
			array_map[i] = arr[i];
		}
	}
}

void SparseArray::set(int i, int val){
	if(i >= 0 && i < size){
		array_map[i] = val;
	}
}

int SparseArray::get(int i){
	if(i >= 0 && i < size) return array_map[i];
	return -1;
}

// main function
int main(){
	srand(time(0));
	
	int size = 20;
	int arr[size];
	for(int i=0; i<size; i++){
		int rand_num = rand()%10;
		arr[i] = (rand_num < 7)? 0 : rand_num;
	}
	
	for(int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << "\n";
	
	SparseArray sa;
	sa.init(arr, size);
	
	for(int i=0; i<size; i++)
		cout << sa.get(i) << " ";
	cout << "\n";
	
	for(int i=0; i<5; i++){
		int index = rand()%size;
		sa.set(index, rand()%1000);
	}
	
	for(int i=0; i<size; i++)
		cout << sa.get(i) << " ";
	cout << "\n";
	
	return 0;
}