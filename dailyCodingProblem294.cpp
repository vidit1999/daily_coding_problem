#include <bits/stdc++.h>
using namespace std;

/*
A competitive runner would like to create a route that starts and ends at his house,
with the condition that the route goes entirely uphill at first, and then entirely downhill.

Given a dictionary of places of the form {location: elevation},
and a dictionary mapping paths between some of these locations
to their corresponding distances, find the length of the shortest
route satisfying the condition above. Assume the runner's home is location 0.

For example, suppose you are given the following input:

elevations = {0: 5, 1: 25, 2: 15, 3: 20, 4: 10}
paths = {
    (0, 1): 10,
    (0, 2): 8,
    (0, 3): 15,
    (1, 3): 12,
    (2, 4): 10,
    (3, 4): 5,
    (3, 0): 17,
    (4, 0): 10
}
In this case, the shortest valid path would
be 0 -> 2 -> 4 -> 0, with a distance of 28.
*/

unordered_map<int, int> path_to_zero_values;

unordered_map<int, vector<pair<int, int>>> preProcess(map<pair<int, int>, int> paths){
	unordered_map<int, vector<pair<int, int>>> neighbours;
	
	for(auto it : paths)
        neighbours[it.first.first].push_back({it.first.second, it.second});
	
	return neighbours;
}

int shortestPathHelper(
	unordered_map<int, int> elevations,
    unordered_map<int, vector<pair<int, int>>> paths_preprocessed,
	unordered_set<int> visited,
	bool ascending,
	int curr_pos,
	int curr_length
)
{
    cout << curr_pos << " -- ";
	// if we reach 0 then return curr_length
    int path_len_to_zero = INT_MAX;
	if(curr_pos == 0){
        cout << curr_length << "--> " << path_len_to_zero << "\n";;
		return curr_length;
    }
	
	// if(path_to_zero_values.find(curr_pos) != path_to_zero_values.end())
	// 	return path_to_zero_values[curr_pos];
	
	// make a copy of the visited set to pass it to next recurrence
	unordered_set<int> curr_visited(visited.begin(), visited.end());
	
	for(auto it : paths_preprocessed[curr_pos]){
		// still not visited and not zero
		if(curr_visited.find(it.first) == curr_visited.end()){
			curr_visited.insert(it.first);
			path_len_to_zero = min(
				path_len_to_zero,
				shortestPathHelper
				(
					elevations,
                    paths_preprocessed,
					curr_visited,
					ascending,
					it.first,
					curr_length + it.second
				)
			);
		}
	}
	
    cout << curr_length << " --> " << path_len_to_zero << "\n";
	// path_to_zero_values[curr_pos] = path_len_to_zero;
	return path_len_to_zero;
}

int shortestPath(unordered_map<int, int> elevations, unordered_map<int, vector<pair<int, int>>> paths_preprocessed){
	unordered_set<int> visited;
	
	bool ascending = true;
	int path_len_to_zero = INT_MAX;
	
    for(auto neighbour : paths_preprocessed[0]){
		path_len_to_zero = min(
			path_len_to_zero,
			shortestPathHelper(
				elevations,
                paths_preprocessed,
				visited,
				ascending,
				neighbour.first,
				neighbour.second
			)
		);
	}
	
	return path_len_to_zero;
}

// main function
int main(){
	unordered_map<int, int> elevations = {{0, 5}, {1, 25}, {2, 15}, {3, 20}, {4, 10}};
    map<pair<int, int>, int> paths = {
        {{0, 1}, 10},
        {{0, 2}, 12},
        {{0, 3}, 15},
        {{1, 3}, 12},
        {{2, 4}, 10},
        {{3, 4}, 5},
        {{3, 0}, 17},
        {{4, 0}, 10}
    };

    unordered_map<int, vector<pair<int, int>>> paths_preprocessed = preProcess(paths);

    cout << shortestPath(elevations, paths_preprocessed) << "\n";

    for(auto it : path_to_zero_values){
        cout << it.first << " --> " << it.second << "\n";
    }
	return 0;
}