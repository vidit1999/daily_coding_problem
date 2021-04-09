#include <bits/stdc++.h>
using namespace std;

/*
You are the technical director of WSPT radio,
serving listeners nationwide. For simplicity's
sake we can consider each listener to live along
a horizontal line stretching from 0 (west) to 1000 (east).

Given a list of N listeners, and a list of M radio towers,
each placed at various locations along this line, determine
what the minimum broadcast range would have to be in order
for each listener's home to be covered.

For example, suppose listeners = [1, 5, 11, 20], and
towers = [4, 8, 15]. In this case the minimum range would be 5,
since that would be required for the tower at position 15 to
reach the listener at position 20.
*/

int minBrodcastRange(int listeners[], int towers[], int n, int m){
    int broadcast_range = 0;
    int left_tower = INT_MIN, right_tower = towers[0];
    int i = 0, j = 0;

    while(i < n){
        if(listeners[i] < right_tower){
            int left_distance = listeners[i] - left_tower;
            int right_distance = right_tower - listeners[i];
            broadcast_range = max(
                broadcast_range,
                min(left_distance, right_distance)
            );
            i++;
        }
        else{
            left_tower = towers[j];
            if(j < m-1){
                j++;
                right_tower = towers[j];
            }
            else{
                right_tower = INT_MAX;
            }
        }
    }

    return broadcast_range;
}

// main function
int main(){
    int listeners[] = {1, 5, 11, 20};
    int n = sizeof(listeners)/sizeof(listeners[0]);
    int towers[] = {4, 8, 15};
    int m = sizeof(towers)/sizeof(towers[0]);

    cout << minBrodcastRange(listeners, towers, n, m) << "\n";

    return 0;
}
