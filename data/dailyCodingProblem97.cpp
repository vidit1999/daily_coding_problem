#include <bits/stdc++.h>
using namespace std;

/*
Write a map implementation with a get
function that lets you retrieve
the value of a key at a particular time.

It should contain the following methods:

set(key, value, time): sets key to value for t = time.
get(key, time): gets the key at t = time.
T
he map should work like this. If we set a key at a particular time,
it will maintain that value forever or until it gets set at a later
time. In other words, when we get a key at a time, it should return
the value that was set for that key set at the most recent time.

Consider the following examples:

d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 2) # set key 1 to value 2 at time 2
d.get(1, 1) # get key 1 at time 1 should be 1
d.get(1, 3) # get key 1 at time 3 should be 2
d.set(1, 1, 5) # set key 1 to value 1 at time 5
d.get(1, 0) # get key 1 at time 0 should be null
d.get(1, 10) # get key 1 at time 10 should be 1
d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 0) # set key 1 to value 2 at time 0
d.get(1, 0) # get key 1 at time 0 should be 2
*/

class MapTime{
	// maps key to {-time, value}
	unordered_map<int, map<int, int>> umap;

public:
	void set(int key, int value, int time){
		umap[key][-time] = value;
	}

	int get(int key, int time){
		if(umap[key].empty()) return -1;
		
		auto it = umap[key].lower_bound(-time);
		
		if(it == umap[key].end()){
			return -1;
		}
		
		return it->second;
	}
};

// main function
int main(){
	MapTime d;

	d.set(1, 1, 0);
	d.set(1, 2, 2);
	cout << d.get(1, 1) << "\n";
	cout << d.get(1, 3) << "\n";
	d.set(1, 1, 5);
	cout << d.get(1, 0) << "\n";
	cout << d.get(1, 10) << "\n";
	d.set(1, 1, 0);
	d.set(1, 2, 0);
	cout << d.get(1, 0) << "\n";

	return 0;
}