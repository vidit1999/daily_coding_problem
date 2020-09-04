#include <bits/stdc++.h>
using namespace std;

/*
Implement a 2D iterator class. It will be initialized with an array of arrays,
and should implement the following methods:

next(): returns the next element in the array of arrays. If there are no more elements,
raise an exception.
has_next(): returns whether or not the iterator still has elements left.
For example, given the input [[1, 2], [3], [], [4, 5, 6]],
calling next() repeatedly should output 1, 2, 3, 4, 5, 6.

Do not use flatten or otherwise clone the arrays.
Some of the arrays can be empty.
*/

class Iter2D{
	vector<vector<int>> arr;
	int inner = 0, outer = 0;
	
	public:
	Iter2D(vector<vector<int>> arry) : arr(arry){};
	int next();
	bool has_next();
};


int Iter2D::next(){
	if(has_next()){
		int ans = arr[outer][inner];
		inner++;
		if(inner == arr[outer].size()){
			inner = 0;
            outer++;
        }
        return ans;
	}
    return -1;
}

bool Iter2D::has_next(){
	if(
		outer == arr.size() ||
		(outer == arr.size()-1 && inner == arr[outer].size())
	)
		return false;
	if(arr[outer].empty()){
		outer++;
		inner = 0;
		return has_next();
	}
    return true;
}

// main function
int main(){
	Iter2D t({{1, 2}, {}, {3}, {4, 5, 6}});
    
    while(t.has_next())
        cout << t.next() << "\n";
    
    cout << t.next();
	return 0;
}