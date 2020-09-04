#include <bits/stdc++.h>
using namespace std;

float squareRoot(int number, int precision){
    int start = 0, end = number;
    int mid;
    float ans;

    while(start <= end){
        mid = (start+end)/2;
        if(mid*mid == number){
            ans = mid;
            break;
        }
        else if(mid*mid < number){
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    float increment = 0.1;
    for(int i=1;i<=precision;i++){
        while(ans*ans <= number){
            ans += increment;
        }
        ans -= increment;
        increment /= 10;
    }
    return ans;
}

// main function
int main(){
    cout << squareRoot(9,3) << "\n";
    cout << squareRoot(18,3) << "\n";
    cout << squareRoot(25,3) << "\n";
    cout << squareRoot(30,3) << "\n";
    return 0;
}