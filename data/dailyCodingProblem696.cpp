#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of length 24, where each element represents
the number of new subscribers during the corresponding hour.
Implement a data structure that efficiently supports the following:

update(hour: int, value: int): Increment the element at index hour by value.
query(start: int, end: int): Retrieve the number of subscribers that
have signed up between start and end (inclusive).

You can assume that all values get cleared at the end of the day,
and that you will not be asked for start and end values that wrap around midnight.
*/

class SubQuery{
    int arr[24] = {0};

    public:

    void update(int hour, int value){
        arr[hour-1] += value;
    }

    int query(int start, int end){
        int num_sub = 0;

        for(int i=start-1; i<=end-1; i++){
            num_sub += arr[i];
        }

        return num_sub;
    }
};


// main function
int main(){
    SubQuery s;

    s.update(1, 10);
    s.update(2, 4);
    s.update(6, 7);

    cout << s.query(1, 6) << "\n";
    cout << s.query(1, 2) << "\n";
    cout << s.query(2, 6) << "\n";
    cout << s.query(3, 5) << "\n";
    cout << s.query(7, 2) << "\n";
    cout << s.query(8, 12) << "\n";

    return 0;
}