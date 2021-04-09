#include <bits/stdc++.h>
using namespace std;

/*
Write a function to flatten a nested dictionary.
Namespace the keys with a period.

For example, given the following dictionary:

{
    "key": 3,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8
        }
    }
}
it should become:

{
    "key": 3,
    "foo.a": 5,
    "foo.bar.baz": 8
}

You can assume keys do not contain dots in them,
i.e. no clobbering will occur.
*/

struct Dict{
	vector<pair<string, int>> normal;
	vector<pair<string, Dict>> nested;
};


vector<pair<string, int>> flattenDict(Dict& d){
	vector<pair<string, int>> ans = d.normal;

	for(auto& it : d.nested){
		for(auto& i : flattenDict(it.second)){
			ans.push_back({it.first + "." + i.first, i.second});
		}
	}

	return ans;
}

// main function
int main(){
	Dict d = {
		{{"key", 3}},
	    {{"foo",
	    	{
	        	{{"a", 5}},
	        	{{"bar",
	        		{
	        			{{"baz", 8}}
	        		}
	        	}}
	        }
	    }}
	};

	for(auto it : flattenDict(d)){
		cout << it.first << " --> " << it.second << "\n";
	}
	return 0;
}