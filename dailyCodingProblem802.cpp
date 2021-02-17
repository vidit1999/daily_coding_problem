#include <bits/stdc++.h>
using namespace std;

/*
You are given n numbers as well as n probabilities that sum up to 1.
Write a function to generate one of the numbers with its corresponding probability.

For example, given the numbers [1, 2, 3, 4] and probabilities
[0.1, 0.5, 0.2, 0.2], your function should return 1 10% of the time,
2 50% of the time, and 3 and 4 20% of the time.

You can generate random numbers between 0 and 1 uniformly.
*/

int probabilityIndex(vector<int>& numbers, vector<float>& probabilities){
    float r = float(rand())/float(RAND_MAX);

    for(int i=0; i<numbers.size(); i++){
        if(r <= probabilities[i]) return i;
        r -= probabilities[i];
    }

    return 0;
}

void testFunc(vector<int>& numbers, vector<float>& probabilities, int iter){
    vector<int> counts(numbers.size(), 0);

    while(iter--){
        int i = probabilityIndex(numbers, probabilities);
        counts[i]++;
    }

    for(int i=0; i<numbers.size(); i++){
        cout << numbers[i] << "\t" << counts[i] << "\n";
    }
}

// main function
int main(){
    srand(time(0));

    vector<int> numbers = {1, 2, 3, 4};
    vector<float> probabilities = {0.1, 0.5, 0.2, 0.2};

    testFunc(numbers, probabilities, 10000);

    return 0;
}
