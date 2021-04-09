#include <bits/stdc++.h>
using namespace std;

/*
You run an e-commerce website and want to record the last N order ids in a log.
Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.

You should be as efficient with time and space as possible.
*/

class LogOrder{
	int n, curr_index, *logs;
	
	public:
	LogOrder(int n);
	~LogOrder(){ delete [] logs; }
	void record(int order_id);
	int get_last(int i);
};

LogOrder::LogOrder(int n){
	this->n = n;
	this->curr_index = 0;
	this->logs = new int[n];
}

void LogOrder::record(int order_id){
	logs[curr_index] = order_id;
	curr_index = (curr_index + 1)%n;
}

int LogOrder::get_last(int i){
	return logs[(i - 1 + n)%n];
}

// main function
int main(){
	LogOrder l(5);
	l.record(17);
	l.record(18);
	cout << l.get_last(1) << "\n";
	return 0;
}