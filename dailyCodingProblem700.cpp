#include <bits/stdc++.h>
using namespace std;

/*
You are given a huge list of airline ticket prices between different
cities around the world on a given day. These are all direct flights.
Each element in the list has the format (source_city, destination, price).

Consider a user who is willing to take up to k connections from their
origin city A to their destination B. Find the cheapest fare possible
for this journey and print the itinerary for that journey.

For example, our traveler wants to go from
JFK to LAX with up to 3 connections,
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

Due to some improbably low flight prices, the cheapest
itinerary would be JFK -> ATL -> ORD -> LAX, costing $440.
*/

void minFareJourneyHelper(
	unordered_map<string, vector<pair<string, int>>>& graph,
	vector<string>& itinerary, vector<string>& ans,
	string start, string& end, unordered_set<string>& visited,
	int cost, int& min_cost, int& k, int count
){

	if(count > k){
		return;
	}

	if(start == end || cost >= min_cost){
		itinerary.push_back(start);
		
		if(min_cost > cost){
			ans = itinerary;
			min_cost = cost;
		}

		itinerary.pop_back();
		return;
	}

	itinerary.push_back(start);
	visited.insert(start);

	for(auto nei : graph[start]){
		if(visited.find(nei.first) == visited.end()){
			minFareJourneyHelper(
				graph, itinerary, ans, nei.first,
				end, visited, cost+nei.second,
				min_cost, k, count
			);
		}
	}

	visited.erase(start);
	itinerary.pop_back();
}

pair<int, vector<string>> minFareJourney(
	vector<pair<pair<string, string>, int>>& flights,
	string start, string end, int k
){
	unordered_map<string, vector<pair<string, int>>> graph;

	for(auto flight : flights){
		graph[flight.first.first].push_back({flight.first.second, flight.second});
	}

	vector<string> itinerary, ans;
	unordered_set<string> visited;
	int min_cost = INT_MAX;

	minFareJourneyHelper(
		graph, itinerary, ans,
		start, end, visited,
		0, min_cost, k, 0
	);

	return {min_cost, ans};
}

// main function
int main(){
	vector<pair<pair<string, string>, int>> flights = {
		{{"JFK", "ATL"}, 150},
		{{"ATL", "SFO"}, 400},
		{{"ORD", "LAX"}, 200},
		{{"LAX", "DFW"}, 80},
		{{"JFK", "HKG"}, 800},
		{{"ATL", "ORD"}, 90},
		{{"JFK", "LAX"}, 500},
	};

	auto ans = minFareJourney(flights, "JFK", "LAX", 3);

	cout << ans.first << "\n";

	for(auto s : ans.second){
		cout << s << "\n";
	}

	return 0;
}