#include <bits/stdc++.h>
using namespace std;

/*
The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
*/

double piEstimation(int interval){
	long squarePoints = 0, circlePoints = 0;
	double pi = 0;
	
	for(long i=0;i<interval*interval;i++){
		double x = double(rand()%(interval+1))/double(interval);
		double y = double(rand()%(interval+1))/double(interval);
		
		if(x*x + y*y <= 1)
			circlePoints++;
		squarePoints++;
		
		pi = double(4*circlePoints)/double(squarePoints);
		if(i % interval == 0)
			cout << "Estimate of pi : " << pi << "\n";
	}
	
	return pi;
}

// main function
int main(){
	cout << piEstimation(100) << "\n";
	return 0;
}