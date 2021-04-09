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

struct NestedDict{
    map<string, int> normal;
    map<string, NestedDict> nested;
};

void showNestedDict(NestedDict nd, int tab_count){
    for(auto it : nd.normal){
        for(int i=0; i<tab_count; i++) cout << "\t";
        cout << it.first << " -> " << it.second << "\n";
    }
    for(auto it : nd.nested){
        for(int i=0; i<tab_count; i++) cout << "\t";
        cout << it.first << "\n";
        showNestedDict(it.second, tab_count+1);
    }
}

map<string, int> flattenNestedDict(NestedDict nd){
    map<string, int> flat;
    
    for(auto it : nd.normal) flat[it.first] = it.second;

    for(auto it : nd.nested){
        for(auto nest : flattenNestedDict(it.second))
            flat[it.first + "." + nest.first] = nest.second;
    }

    return flat;
}


// main function
int main(){
    NestedDict nd = {
        {{ "key", 3 }},
        {{ "foo",
            {
                {{ "a", 5 }},
                {{ "bar",
                    {
                        {{ "baz", 8}}
                    }
                }}

            }
        }}
    };

    showNestedDict(nd, 0);
    cout << "\n----------------------\n";

    for(auto it : flattenNestedDict(nd))
        cout << it.first << " -> " << it.second << "\n";
	return 0;
}