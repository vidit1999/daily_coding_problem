#include <bits/stdc++.h>
using namespace std;

#define PI 3.141

/*
The area of a circle is defined as πr^2.
Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
*/

double piEstimator(){
    long total_point = 0, inside_arc = 0;
    double pi;

    while(true){
        total_point++;

        double x = double(rand())/double(RAND_MAX);
        double y = double(rand())/double(RAND_MAX);

        if(x*x + y*y <= 1){
            inside_arc++;
        }

        pi = double(4* total_point) / double(inside_arc);

        if(abs(PI - pi) < 0.001){
            cout << "Total no. of points : " << total_point << "\n";
            cout << "No. of points inside arc : " << inside_arc << "\n";
            cout << "Value of PI : " << pi << "\n";
            cout << "Error : " << (PI - pi) << "\n";
            break;
        }
    }

    return pi;
}

// main function
int main(){
    srand(time(0));
    cout << piEstimator() << "\n";
    return 0;
}
