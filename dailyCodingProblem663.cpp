#include <bits/stdc++.h>
using namespace std;

/*
Design and implement a HitCounter class that keeps track of requests (or hits).
It should support the following operations:

record(timestamp): records a hit that happened at timestamp
total(): returns the total number of hits recorded
range(lower, upper): returns the number of hits that occurred between timestamps lower and upper (inclusive)

Follow-up: What if our system has limited memory?
*/

class HitCounter{
	vector<int> hits;
	unordered_map<int, int> time_index;
	
	public:
	
    void record(int timestamp);
	int total();
	int range(int lower, int upper);
};

void HitCounter::record(int timestamp){
	hits.push_back(1);
	time_index[timestamp] = hits.size()-1;
}

int HitCounter::total(){
	return hits.size();
}

int HitCounter::range(int lower, int upper){
	int start = time_index[lower], end = time_index[upper], count = 0;
	for(int i=start; i<=end; i++){
		count += hits[i];
	}
	
	return count;
}


// main function
int main(){
	HitCounter hc;
    
	hc.record(1);
    hc.record(3);
    hc.record(5);
    hc.record(10);
    hc.record(16);
    
	cout << hc.total() << "\n";

	hc.record(25);
    
	cout << hc.total() << "\n\n";

	cout << hc.range(1, 25) << "\n";
    cout << hc.range(1, 3) << "\n";
    cout << hc.range(3, 10) << "\n";
    cout << hc.range(5, 25) << "\n";
	return 0;
}