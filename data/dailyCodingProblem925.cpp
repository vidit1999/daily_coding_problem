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

struct Dictionary{
    map<string, int> normal;
    map<string, Dictionary> nested;
};

map<string, int> flatten(Dictionary d){
    map<string, int> flat = d.normal;

    for(auto it1 : d.nested){
        for(auto it2 : flatten(it1.second)){
            flat[it1.first + "." + it2.first] = it2.second;
        }
    }

    return flat;
}

// main function
int main(){
    Dictionary d = {
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

    for(auto it : flatten(d)){
        cout << it.first << " : " << it.second << "\n";
    }

    return 0;
}