#include <bits/stdc++.h>
using namespace std;

/*
A teacher must divide a class of students into two teams to play dodgeball.
Unfortunately, not all the kids get along, and several
refuse to be put on the same team as that of their enemies.

Given an adjacency list of students and their enemies,
write an algorithm that finds a satisfactory pair of teams,
or returns False if none exists.

For example, given the following enemy graph
you should return the teams {0, 1, 4, 5} and {2, 3}.

students = {
    0: [3],
    1: [2],
    2: [1, 4],
    3: [0, 4, 5],
    4: [2, 3],
    5: [3]
}

On the other hand, given the input below,
you should return False.

students = {
    0: [3],
    1: [2],
    2: [1, 3, 4],
    3: [0, 2, 4, 5],
    4: [2, 3],
    5: [3]
}
*/

bool checkSafeSet(
	int student,
	unordered_set<int>& uset,
	vector<unordered_set<int>>& students
){
	for(auto it : students[student]){
		if(uset.find(it) != uset.end()){
			return false;
		}
	}
	return true;
}

bool friendlyTeamsHelper(
	int student,
	unordered_set<int>& first_team,
	unordered_set<int>& second_team,
	pair<unordered_set<int>, unordered_set<int>>& ans,
	vector<unordered_set<int>>& students
){
	if(student == students.size()){
		ans = {first_team, second_team};
		return true;
	}

	// check if first team is safe
	if(checkSafeSet(student, first_team, students)){

		// insert into teams accordingly
		first_team.insert(student);
		for(int i : students[student]){
			second_team.insert(i);
		}

		if(friendlyTeamsHelper(student+1, first_team, second_team, ans, students)){
			return true;
		}

		// not work then backtrack
		first_team.erase(student);
		for(int i : students[student]){
			second_team.erase(i);
		}
	}


	// check if second team is safe
	if(checkSafeSet(student, second_team, students)){

		// insert into teams accordingly
		second_team.insert(student);
		for(int i : students[student]){
			first_team.insert(i);
		}

		if(friendlyTeamsHelper(student+1, first_team, second_team, ans, students)){
			return true;
		}

		// not work then backtrack
		second_team.erase(student);
		for(int i : students[student]){
			first_team.erase(i);
		}
	}

	return false;
}

pair<unordered_set<int>, unordered_set<int>> friendlyTeams(
	vector<unordered_set<int>>& students
){
	unordered_set<int> first_team, second_team;
	pair<unordered_set<int>, unordered_set<int>> ans;
	friendlyTeamsHelper(0, first_team, second_team, ans, students);
	return ans;
}


void testFunc(vector<vector<unordered_set<int>>> v){
	for(auto students : v){
		auto ans = friendlyTeams(students);

		if(ans.first.empty() && ans.second.empty()){
			cout << "No team possible.";
		}
		else{
			cout << "First Team : ";
			for(int i : ans.first){
				cout << i << " ";
			}
			
			cout << "\nSecond Team : ";
			for(int i : ans.second){
				cout << i << " ";
			}

		}
		cout << "\n\n";
	}
}

// main function
int main(){
	testFunc({
		{
			{3},
			{2},
			{1, 3, 4},
			{0, 2, 4, 5},
			{2, 3},
			{3}
		},
		{
			{3},
			{2},
			{1, 4},
			{0, 4, 5},
			{2, 3},
			{3},
		}
	});

	return 0;
}