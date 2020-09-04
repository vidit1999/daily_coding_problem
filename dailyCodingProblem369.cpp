#include <bits/stdc++.h>
using namespace std;

/*
You’re tracking stock price at a given instance of time.
Implement an API with the following functions: add(), update(), remove(),
which adds/updates/removes a datapoint for the stock price you are tracking.
The data is given as (timestamp, price), where timestamp is specified in unix epoch time.

Also, provide max(), min(), and average() functions that give the max/min/average of all values seen thus far.
*/



class Tracker{
	unordered_map<string, int> data;
	int total = 0;
	
	public:
	
	void add(pair<string, int> point){
		if(data.find(point.first) != data.end()){
			int val = data[point.first];
			total -= val;
		}
		data[point.first] = point.second;
		total += point.second;
	}
	
	void show_data(){
		for(auto it : data){
			cout << it.first << ", " << it.second << "\n";
		}
	}
	
	void update(pair<string, int> point){
		if(data.find(point.first) != data.end()){
			int val = data[point.first];
			total -= val;
			data[point.first] = point.second;
			total += point.second;
		}
	}
	
	void remove(pair<string, int> point){
		if(data.find(point.first) != data.end()){
			total -= point.second;
			data.erase(point.first);
		}
	}
	
	int min(){
		int minVal = INT_MAX;
		for(auto it : data)
			minVal = (minVal < it.second)? minVal : it.second;
		return minVal;
	}
	
	int max(){
		int maxVal = INT_MIN;
		for(auto it : data)
			maxVal = (maxVal > it.second)? maxVal : it.second;
		return maxVal;
	}
	
	float average(){
		if(!data.empty()) return float(total)/data.size();
		return 0;
	}
};

// main function
int main(){
	vector<pair<string, int>> points = {
		{"1592240474", 10},
		{"1592237198", 20},
		{"1592236850", 30}
	};
	
	Tracker t;
	
	for(auto it : points) t.add(it);

	t.show_data();
	cout << "\n-------\n";
	cout << t.max() << ", " << t.min() << ", " << t.average() << "\n";
	cout << "\n-------\n";
	
	t.remove({"1592236850", 30});
	t.show_data();
	cout << "----------\n";
	
	t.add({"1592236851", 40});
	t.show_data();
	cout << "----------\n";
	cout << t.max() << ", " << t.min() << ", " << t.average() << "\n";
	cout << "\n-------\n";
	
	t.update({"1592240474", 50});
	t.show_data();
	cout << "----------\n";
	cout << t.max() << ", " << t.min() << ", " << t.average() << "\n";
	cout << "\n-------\n";
	
	return 0;
}