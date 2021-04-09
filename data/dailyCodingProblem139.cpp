#include <bits/stdc++.h>
using namespace std;

/*
Given an iterator with methods next() and hasNext(), create a wrapper iterator,
PeekableInterface, which also implements peek(). peek shows the next
element that would be returned on next().

Here is the interface:

class PeekableInterface(object):
    def __init__(self, iterator):
        pass

    def peek(self):
        pass

    def next(self):
        pass

    def hasNext(self):
        pass
*/

class PeekableInterface{
	Iterator it;
	int cache;
	
	public:
	
	PeekableInterface(vector<int>& v){
		it = Iterator(v);
		cache = 0;
	}
	
	int peek(){
		if(cache != 0)
			return cache;
		if(it.hasNext()){
			cache = it.next();
			return cache;
		}
		return -1;
	}
	
	int next(){
		if(cache != 0){
			int ans = cache;
			cache = 0;
			return ans;
		}
		
		return it.next();
	}
	
	bool hasNext(){
		if(cache != 0)
			return true;
		return it.hasNext();
	}
};

// main function
int main(){
	vector<int> v = {1, 2, 3};
	PeekableInterface pk(v);
	
	cout << pk.hasNext() << "\n";
	cout << pk.next() << "\n";
	cout << pk.peek() << "\n";
	cout << pk.peek() << "\n";
	cout << pk.next() << "\n";
	cout << pk.hasNext() << "\n";
	cout << pk.next() << "\n";
	cout << pk.peek() << "\n";
	cout << pk.hasNext() << "\n";
	cout << pk.next() << "\n";
	cout << pk.hasNext() << "\n";
	cout << pk.peek() << "\n";
	
	return 0;
}