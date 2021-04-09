#include <bits/stdc++.h>
using namespace std;

/*
You are given an array X of floating-point numbers x1, x2, ... xn.
These can be rounded up or down to create a corresponding array Y of integers y1, y2, ... yn.

Write an algorithm that finds an appropriate Y array with the following properties:

The rounded sums of both arrays should be equal.
The absolute pairwise difference between elements is minimized.
In other words, |x1- y1| + |x2- y2| + ... + |xn- yn| should be as small as possible.
For example, suppose your input is [1.3, 2.3, 4.4]. In this case you cannot do better than [1, 2, 5],
which has an absolute difference of |1.3 - 1| + |2.3 - 2| + |4.4 - 5| = 1.
*/


struct Element{
	int index, value;
	float diff;
};

bool sortByDiff(Element e1, Element e2){
	return e1.diff > e2.diff;
}

bool sortByIndex(Element e1, Element e2){
	return e1.index < e2.index;
}


vector<int> roundThem(vector<float> arr){
	vector<Element> elemArr;
	int running_sum = 0;
	float sum = 0;
	
	for(int i=0; i<arr.size(); i++){
		int floorNum = floor(arr[i]);
		sum += arr[i];
		running_sum += floorNum;
		elemArr.push_back({
			i,
			floorNum,
			arr[i] - float(floorNum)
		});
	}
	
	int sum_diff = sum - running_sum;
	sort(elemArr.begin(), elemArr.end(), sortByDiff);
	
	for(int i=0;i<elemArr.size();i++){
		if(sum_diff == 0) break;
		elemArr[i].value++;
		sum_diff--;
	}

	sort(elemArr.begin(), elemArr.end(), sortByIndex);
	
	vector<int> ans;
	
	for(auto e : elemArr){
		ans.push_back(e.value);
	}
	
	
	return ans;
}

// main function
int main(){
	vector<float> arr1 = {
		13.626332,
		47.989636,
		9.596008,
		28.788024
	};
	
	vector<float> arr2 = {1.3, 2.3, 4.4};
	
	for(int i :roundThem(arr2))
		cout << i << "\n";
	return 0;
}