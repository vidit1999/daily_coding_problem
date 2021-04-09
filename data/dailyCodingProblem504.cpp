#include <bits/stdc++.h>
using namespace std;

/*
You run an e-commerce website and want to record the last N order ids in a log.
Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.

You should be as efficient with time and space as possible.
*/

class Orders{
	vector<int> orders;
	int last_index;
	
	public:
	Orders(){
		orders = {};
		last_index = 0;
	}
	
	void record(int order_id){
		orders.push_back(order_id);
		last_index++;
	}
	
	int get_last(int i){
		return orders[last_index-i];
	}
};

// main function
int main(){
	Orders ord;
	ord.record(100);
	ord.record(200);
	ord.record(300);
	
	cout << ord.get_last(3) << "\n";
	cout << ord.get_last(2) << "\n";
	cout << ord.get_last(1) << "\n";
	return 0;
}