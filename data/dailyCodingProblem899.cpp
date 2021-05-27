#include <bits/stdc++.h>
using namespace std;

#define NUMBER 24
#define OP_NUM 4

/*
The 24 game is played as follows. You are given a list of four integers,
each between 1 and 9, in a fixed order. By placing the operators +, -, *, and /
between the numbers, and grouping them with parentheses, determine whether
it is possible to reach the value 24.

For example, given the input [5, 2, 7, 8], you should return True,
since (5 * 2 - 7) * 8 = 24.

Write a function that plays the 24 game.
*/

int perform(int num1, int num2, int op){
    if(
        num1 == INT_MAX ||
        num2 == INT_MAX ||
        (num2 == 0 && op == 3)
    )
        return INT_MAX;

    switch(op){
        case 0 : return (num1 + num2);
        case 1 : return (num1 - num2);
        case 2 : return (num1 * num2);
        case 3 : return (num1 / num2);
    }

    return -1;
}

bool checkArray(int arr[], int n, int op1, int op2, int op3){
    // (a op b op c op d)
    if(
        perform(
            perform(arr[0], arr[1], op1),
            perform(arr[2], arr[3], op3),
            op2
        ) == NUMBER
    ){
        return true;
    }

    // (a op (b op c)) op d
    if(
        perform(
            perform(
                arr[0],
                perform(arr[1], arr[2], op2),
                op1
            ),
            arr[3],
            op3
        ) == NUMBER
    ){
        return true;
    }

    // (((a op b) op c) op d)
    if(
        perform(
            perform(
                perform(
                    arr[0], arr[1], op1
                ),
                arr[2], op2
            ),
            arr[3], op3
        ) == NUMBER
    ){
        return true;
    }

    return false;
}

bool checkPermutation(int arr[], int n){
    for(int i=0; i<OP_NUM; i++){
        for(int j=0; j<OP_NUM; j++){
            for(int k=0; k<OP_NUM; k++){
                if(checkArray(arr, n, i, j, k))
                    return true;
            }
        }
    }
    return false;
}

bool solve(int arr[], int n, int low, int high){
    if(low == high){
        return checkPermutation(arr, n);
    }

    for(int i=low; i<=high; i++){
        swap(arr[i], arr[low]);
        if(solve(arr, n, low+1, high))
            return true;
        swap(arr[i], arr[low]);
    }

    return false;
}

// main function
int main(){
    int arr[] ={4, 1, 8, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << solve(arr, n, 0, n-1) << "\n";
    return 0;
}
