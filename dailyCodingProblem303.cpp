#include <bits/stdc++.h>
using namespace std;

/*
Given a clock time in hh:mm format, determine, to the nearest degree,
the angle between the hour and the minute hands.

Bonus: When, during the course of a day, will the angle be zero?
*/

int angleBwHourMinute(int hh, int mm){
	if(hh < 0 || mm < 0 || hh > 12 || mm > 60)
		return -1;
	if(hh == 12) hh = 0;
	if(mm == 60){
		mm = 0;
		hh += 1;
		if(hh == 12) hh = 0;
	}
	
	int mm_angle = 6*mm;
	int hh_angle = 0.5*(60*hh + mm);
	
	int angle = abs(hh_angle - mm_angle);
	
	return min(angle, 360-angle);
}

// main function
int main(){
	cout << angleBwHourMinute(3, 30) << "\n";
	for(int hh=0;hh<=12;hh++){
		for(int mm=0;mm<=60;mm++)
			if(angleBwHourMinute(hh, mm) == 0)
				cout << hh << " -- " << mm << "\n";
	}
	return 0;
}