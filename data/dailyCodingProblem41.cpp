#include <bits/stdc++.h>
using namespace std;

/*
Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs,
and a starting airport, compute the person's itinerary. If no such itinerary exists, return null.
If there are multiple possible itineraries, return the lexicographically smallest one.
All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A',
you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C']
is also a valid itinerary. However, the first one is lexicographically smaller.
*/

vector<string> itineraries(vector<pair<string, string>> flights, string start){
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> flightMap;
    vector<string> ans = { start };

    for(auto it : flights) flightMap[it.first].push(it.second);

    while(true){
        if((flightMap.find(start) == flightMap.end()) || flightMap[start].empty()) break;
        auto nextDest = flightMap[start].top();
        flightMap[start].pop();
        ans.push_back(nextDest);
        start = nextDest;
    }
    if(ans.size() == flights.size()+1)
        return ans;
    return {""};
}

void testFunc(vector<pair<vector<pair<string, string>>, string>> v){
    for(auto it : v){
        auto ans = itineraries(it.first, it.second);
        for(auto it : ans)
            cout << it << " ";
        cout << "\n";
    }
}


// main function
int main(){
    testFunc({
    {{
        {"A", "B"},
        {"A", "C"},
        {"B", "C"},
        {"C", "A"}
    }, "A"},
    {{
        {"SFO", "COM"},
        {"COM", "YYZ"}
    }, "COM"},
    {{
        {"SFO", "HKO"},
        {"YYZ", "SFO"},
        {"YUL", "YYZ"},
        {"HKO", "ORD"}
    }, "YUL"}
    });
	
	return 0;
}