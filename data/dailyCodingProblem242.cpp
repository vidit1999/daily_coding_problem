#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of length 24, where each element represents the number of new
subscribers during the corresponding hour. Implement a data structure
that efficiently supports the following:

update(hour: int, value: int): Increment the element at index hour by value.
query(start: int, end: int): Retrieve the number of subscribers that have
signed up between start and end (inclusive).

You can assume that all values get cleared at the end of the day,
and that you will not be asked for start and end values that wrap around midnight.
*/

class SegmentTree{
	int n;
	int *st;
	int constructUtil(int arr[], int ss, int se, int si);
	void updateUtil(int i, int v, int ss, int se, int si);
	int queryUtil(int start, int end, int ss, int se, int si);
	
	public:
	SegmentTree(int arr[], int n);
	~SegmentTree();
	void update(int i, int v);
	int query(int start, int end);
};

int SegmentTree::constructUtil(int arr[], int ss, int se, int si){
	if(ss == se){
		st[ss] = arr[ss];
		return arr[ss];
	}
	int mid = (ss + se)/2;
	st[si] = constructUtil(arr, ss, mid, 2*si+1) + constructUtil(arr, mid+1, se, 2*si+2);
	return st[si];
}

SegmentTree::SegmentTree(int arr[], int n){
	this->n = n;
    int size = 2*(int)pow(2,(int)ceil(log2(n))) - 1;
	st = new int[size];
	constructUtil(arr, 0, n-1, 0);
}

SegmentTree::~SegmentTree(){ delete [] st; }

void SegmentTree::updateUtil(int i, int v, int ss, int se, int si){
	if(i < ss || i > se) return;
	
	st[si] = st[si] + v;
	
	if(si != se){
		int mid = (ss + se)/2;
		updateUtil(i, v, ss, mid, 2*si+1);
		updateUtil(i, v, mid+1, se, 2*si+2);
	}
}

void SegmentTree::update(int i, int v){
	if(i < 0 || i > n-1) return;
	updateUtil(i, v, 0, n-1, 0);
}

int SegmentTree::queryUtil(int start, int end, int ss, int se, int si){
	if(start <= ss && end >= se) return st[si];
	if(se < start || ss > end) return 0;
	
	int mid = (ss + se)/2;
	return queryUtil(start, end, ss, mid, 2*si+1) + queryUtil(start, end, mid+1, se, 2*si+2);
}

int SegmentTree::query(int start, int end){
	if(start < 0 || end > n-1 || start > end) return -1;
	return queryUtil(start, end, 0, n-1, 0);
}

// main function
int main(){
	int arr[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	SegmentTree st(arr, n);
	cout << st.query(1, 3) << "\n";
	st.update(1, 10);
	cout << st.query(1, 3) << "\n";
	return 0;
}