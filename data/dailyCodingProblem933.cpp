#include <bits/stdc++.h>
using namespace std;

/*
The sequence [0, 1, ..., N] has been jumbled,
and the only clue you have for its order is an array
representing whether each number is larger or smaller than the last.

Given this information, reconstruct an array that is consistent with it.
For example, given [None, +, +, -, +], you could return [1, 2, 3, 0, 4].
*/

vector<int> arrayReconstruct(vector<char> sym_arr){
    vector<int> arr(sym_arr.size(), 0);
    int max_elem = 0, min_elem = 0;

    for(int i=1; i<sym_arr.size(); i++){
        if(sym_arr[i] == '+') arr[i] = ++max_elem;
        else arr[i] = --min_elem;
    }

    for(int& i : arr) {i += (-min_elem);}
    
    return arr;
}

template<typename T>
void printVector(vector<T> arr){
    cout << " { ";
    for(auto e : arr){
        cout << e << " ";
    }
    cout << "} ";
}

void testFunc(int length, int test_count){
    vector<int> v(length-1);
    vector<char> sym_arr(v.size(), '$');
    
    iota(v.begin(), v.end(), 0);

    while(test_count--){
        random_shuffle(v.begin(), v.end());
        
        for(int i=1; i<sym_arr.size(); i++){
            sym_arr[i] = (v[i] > v[i-1]) ? '+' : '-';
        }

        printVector(sym_arr);
        printVector(arrayReconstruct(sym_arr));

        cout << "\n";
    }
}

// main function
int main(){
    srand(time(0));
    testFunc(6, 5);
    return 0;
}