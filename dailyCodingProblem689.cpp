#include <bits/stdc++.h>
using namespace std;

/*
The United States uses the imperial system of weights and measures,
which means that there are many different, seemingly arbitrary units
to measure distance. There are 12 inches in a foot, 3 feet in a yard,
22 yards in a chain, and so on.

Create a data structure that can efficiently convert a certain quantity
of one unit to the correct amount of any other unit. You should also allow
for additional units to be added to the system.
*/

class UnitConverter{
	unordered_map<string, double> unit_to_feet; // 1 unit => ? feet
	
	public:
	void addUnit(string unit, double feet); // 1 unit is how much feet
	double convert(pair<string, double> unit1, string unit2); // k unit1 => ? unit2
};

void UnitConverter::addUnit(string unit, double feet){
	unit_to_feet[unit] = feet;
}

double UnitConverter::convert(pair<string, double> unit1, string unit2){
	return unit1.second * unit_to_feet[unit1.first] / unit_to_feet[unit2];
}

// main function
int main(){
	UnitConverter uc;
	vector<pair<string, double>> units = {
		{"inch", double(1.0/12)},
		{"foot", 1},
		{"yard", 3}
	};
	
	for(auto it : units)
		uc.addUnit(it.first, it.second);
	
	cout << uc.convert({"yard", 6}, "inch") << "\n";
	return 0;
}