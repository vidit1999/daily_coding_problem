#include <bits/stdc++.h>
using namespace std;

/*
Given a clock time in hh:mm format, determine, to the nearest degree,
the angle between the hour and the minute hands.

Bonus: When, during the course of a day, will the angle be zero?
*/

float calculateAngle(int hh, int mm){
	if(hh == 12) hh = 0;
	
	float mmDiff = 6*mm;
	float hhDiff = 0.5*(60*hh+mm);
	float absDiff = abs(mmDiff-hhDiff);
	
	return min(absDiff,360-absDiff);
}

// main function
int main(){
	cout << calculateAngle(3, 30) << "\n";
	for(int i=0;i<=12;i++){
		for(int j=0;j<60;j++){
			if(calculateAngle(i, j) == 0)
				cout << i << " : " << j << "\n";
		}
	}
	return 0;
}