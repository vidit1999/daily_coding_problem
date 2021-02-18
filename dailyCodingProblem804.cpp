#include <bits/stdc++.h>
using namespace std;

/*
You are given a huge list of airline ticket prices between different cities
around the world on a given day. These are all direct flights.
Each element in the list has the format (source_city, destination, price).

Consider a user who is willing to take up to k connections from
their origin city A to their destination B. Find the cheapest fare
possible for this journey and print the itinerary for that journey.

For example, our traveler wants to go
from JFK to LAX with up to 3 connections,
and our input flights are as follows:

[
    ('JFK', 'ATL', 150),
    ('ATL', 'SFO', 400),
    ('ORD', 'LAX', 200),
    ('LAX', 'DFW', 80),
    ('JFK', 'HKG', 800),
    ('ATL', 'ORD', 90),
    ('JFK', 'LAX', 500),
]

Due to some improbably low flight prices, the cheapest itinerary
would be JFK -> ATL -> ORD -> LAX, costing $440.
*/

void minimumCostFlightHelper(
    int count,
    int& k,
    int cost,
    int& min_cost,
    string& curr,
    string& end,
    vector<string>& ans,
    vector<string>& flights,
    unordered_set<string>& visited,
    unordered_map<string, vector<pair<string, int>>>& graph
){
    if(count > k) return;
    
    if(curr == end || cost >= min_cost){
        flights.push_back(curr);
        
        if(min_cost > cost){
            min_cost = cost;
            ans = flights;
        }
        
        flights.pop_back();
        return;
    }
    
    flights.push_back(curr);
    visited.insert(curr);
    
    for(auto it : graph[curr]){
        if(visited.find(it.first) == visited.end()){
            minimumCostFlightHelper(
                count+1, k,
                cost+it.second, min_cost,
                it.first, end,
                ans, flights,
                visited, graph
            );
        }
    }
    
    visited.erase(curr);
    flights.pop_back();
}

pair<int, vector<string>> minimumCostFlight(
    int k, string start, string end,
    vector<pair<pair<string, string>, int>>& iternaries
){
    unordered_map<string, vector<pair<string, int>>> graph;
    
    for(auto it : iternaries){
        graph[it.first.first].push_back({it.first.second, it.second});
        // graph[it.first.second].push_back({it.first.first, it.second}); // bi directional flights
    }
    
    int count = 0, cost = 0, min_cost = INT_MAX;
    vector<string> ans, flights;
    unordered_set<string> visited;
    
    minimumCostFlightHelper(count, k, cost, min_cost, start, end, ans, flights, visited, graph);
    
    return {(min_cost == INT_MAX) ? -1 : min_cost, ans};
}

// main function
int main(){
    vector<pair<pair<string, string>, int>> iternaries = {
		{{"JFK", "ATL"}, 150},
		{{"ATL", "SFO"}, 400},
		{{"ORD", "LAX"}, 200},
		{{"LAX", "DFW"}, 80},
		{{"JFK", "HKG"}, 800},
		{{"ATL", "ORD"}, 90},
		{{"JFK", "LAX"}, 900},
	};
    string start = "JFK", end = "LAX";
    int k = 3;
    
    auto ans = minimumCostFlight(k, start, end, iternaries);
    
    cout << ans.first << "\n";
    
    for(auto s : ans.second){
        cout << s << " ";
    }
    cout << "\n";
    
    return 0;
}