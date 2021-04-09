#include <bits/stdc++.h>
using namespace std;

/*
Implement a key value store, where keys and values are integers, with the following methods:

update(key, vl): updates the value at key to val, or sets it if doesn't exist
get(key): returns the value with key, or None if no such value exists
max_key(val): returns the largest key with value val, or None if no key with that value exists

For example, if we ran the following calls:

kv.update(1, 1)
kv.update(2, 1)

And then called kv.max_key(1), it should return 2, since it's the largest key with value 1.
*/

class KeyValue{
	unordered_map<int, int> m;
	
	public:
	
	void update	(int key, int val);
	int get(int key);
	int max_key(int val);
};

void KeyValue::update(int key, int val){
	m[key] = val;
}

int KeyValue::get(int key){
	if(m.find(key) != m.end())
		return m[key];
	return -1;
}

int KeyValue::max_key(int val){
	int key = INT_MIN;
	for(auto it : m)
		if(it.second == val)
			key = max(key, it.first);
	return (key == INT_MIN)? -1 : key;
}

// main function
int main(){
	KeyValue kv;
	kv.update(1, 1);
	kv.update(2, 1);
	cout << kv.get(2) << " -- " << kv.get(3) << "\n";
	cout << kv.max_key(1) << " -- " << kv.max_key(2) << "\n";
	return 0;
}