#include <bits/stdc++.h>
using namespace std;

/*
You are given a list of data entries that represent entries and exits
of groups of people into a building.

An entry looks like this:

{"timestamp": 1526579928, count: 3, "type": "enter"}
This means 3 people entered the building. An exit looks like this:

{"timestamp": 1526580382, count: 2, "type": "exit"}
This means that 2 people exited the building. timestamp is in Unix time.

Find the busiest period in the building, that is, the time with
the most people in the building. Return it as a pair of (start, end) timestamps.
You can assume the building always starts off and ends up empty, i.e. with 0 people inside.
*/

struct entry{
	long long timestamp;
	int count;
	bool type; // for ease of doing enter is true and exit is false
};

pair<long long, long long> mostBusy(vector<entry> entries){
	int start = 0;
	int peopleCount = 0, maxPeopleCount = 0;
	pair<long long, long long> busyStartEnd = {0, 0};
	for(auto ent : entries){
		if(ent.type == true){
			if(start == 0)
				start = ent.timestamp;
			peopleCount += ent.count;
		}
		else{
			if(peopleCount >= maxPeopleCount){
				busyStartEnd = {start, ent.timestamp};
				maxPeopleCount = peopleCount;
			}
			peopleCount -= ent.count;
			start = 0;
		}
	}
	return busyStartEnd;
}

// main function
int main(){
	vector<entry> v = {
        {1526579928, 3, true},
        {1526580382, 2, false},
        {1526579938, 6, true},
        {1526579943, 1, true},
        {1526579944, 0, true},
        {1526580345, 5, false},
        {1526580351, 3, false}
    };
	auto p = mostBusy(v);
	cout << p.first << " -- " << p.second << "\n";
	return 0;
}