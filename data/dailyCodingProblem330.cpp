#include <bits/stdc++.h>
using namespace std;

/*
A Boolean formula can be said to be satisfiable if there is a way to assign
truth values to each variable such that the entire formula evaluates to true.

For example, suppose we have the following formula,
where the symbol ¬ is used to denote negation:

(¬c OR b) AND (b OR c) AND (¬b OR c) AND (¬c OR ¬a)

One way to satisfy this formula would be to
let a = False, b = True, and c = True.

This type of formula, with AND statements
joining tuples containing exactly one OR,
is known as 2-CNF.

Given a 2-CNF formula, find a way to assign
truth values to satisfy it, or return False
if this is impossible.
*/

bool isSatisfiable(unordered_map<int, bool>& num_bool_map, int first[], int second[], int num_clauses){
	for(int i=0; i<num_clauses; i++){
		bool val1 = num_bool_map[abs(first[i])];
		if(first[i] < 0) val1 = !val1;
		bool val2 = num_bool_map[abs(second[i])];
		if(second[i] < 0) val2 = !val2;
		
		if(!val1 && !val2) return false;
	}
	return true;
}

bool assignValueHelper(
	unordered_map<int, bool>& num_bool_map,
	int first[], int second[],
	int index, int num_expr, int num_clauses
){
	if(index == num_expr+1){
		if(isSatisfiable(num_bool_map, first, second, num_clauses)){
			return true;
		}
		return false;
	}
	
	num_bool_map[index] = true;
	if(assignValueHelper(num_bool_map, first, second, index+1, num_expr, num_clauses)){
		return true;
	}
	
	num_bool_map[index] = false;
	if(assignValueHelper(num_bool_map, first, second, index+1, num_expr, num_clauses)){
		return true;
	}
	
	return false;
}

void assignValue(int num_expr, int num_clauses, int first[], int second[]){
	unordered_map<int, bool> num_bool_map;
	
	if(assignValueHelper(num_bool_map, first, second, 1, num_expr, num_clauses)){
		for(auto it : num_bool_map){
			cout << it.first << " --> " << it.second << "\n";
		}
	}
	else{
		cout << "False\n";
	}
}


// main fuction
int main(){
	int num_expr = 5;
	int num_clauses = 7;
	int first[] = {1, -2, -1, 3, -3, -4, -3}; // {-3, 2, -2, -2};
	int second[] = {2, 3, -2, 4, 5, -5, 4}; // {2, 3, 3, -1};
	
	assignValue(num_expr, num_clauses, first, second);
	
	return 0;
}