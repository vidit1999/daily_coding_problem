#include <bits/stdc++.h>
using namespace std;

/*
The “active time” of a courier is the time between
the pickup and dropoff of a delivery.
Given a set of data formatted like the following:

(delivery id, timestamp, pickup/dropoff)

Calculate the total active time in seconds.
A courier can pick up multiple orders before
dropping them off. The timestamp is in unix epoch seconds.

For example, if the input is the following:

(1, 1573280047, 'pickup')
(1, 1570320725, 'dropoff')
(2, 1570321092, 'pickup')
(3, 1570321212, 'pickup')
(3, 1570322352, 'dropoff')
(2, 1570323012, 'dropoff')

The total active time would be 1260 seconds.
*/

struct Delivery{
	int id;
	long timestamp;
	string tag;
};

long totalActiveTime(vector<Delivery> deliveries){
	unordered_map<int, vector<long>> delivery_map;
	
	for(auto delivery : deliveries){
		if(delivery_map.find(delivery.id) == delivery_map.end()){
			delivery_map[delivery.id] = {-1, -1};
		}
		delivery_map[delivery.id][!(delivery.tag == "pickup")] = delivery.timestamp;
	}
	
	long total = 0;
	
	for(auto it : delivery_map){
		if(
			(it.second[0] >= 0) && (it.second[1] >= 0) &&
			(it.second[1] >= it.second[0])
		){
			total += (it.second[1] - it.second[0]);
		}
	}
	
	return total;
}

// main function
int main(){
	vector<Delivery> deliveries = {
		{1, 1573280047, "pickup"},
		{1, 1570320725, "dropoff"},
		{2, 1570321092, "pickup"},
		{3, 1570321212, "pickup"},
		{3, 1570322352, "dropoff"},
		{2, 1570323012, "dropoff"},
	};
	
	cout << totalActiveTime(deliveries) << "\n";
	
	return 0;
}