#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted list of integers of length N, determine if an element x is in the list
without performing any multiplication, division, or bit-shift operations.

Do this in O(log N) time.
*/

int divBy2(int num){
	string st = "0" + to_string(num);
	string ans = "";
	
	for(int i=0; i<st.length()-1; i++){
		int first_digit = st[i]-'0', second_digit = st[i+1]-'0';
		
		if(first_digit%2 == 0){
			switch(second_digit){
				case 0:
				case 1: {
					ans += "0";
					break;
				}
				case 2:
				case 3: {
					ans += "1";
					break;
				}
				case 4:
				case 5: {
					ans += "2";
					break;
				}
				case 6:
				case 7: {
					ans += "3";
					break;
				}
				case 8:
				case 9: {
					ans += "4";
					break;
				}
			}
		}
		else{
			switch(second_digit){
				case 0:
				case 1: {
					ans += "5";
					break;
				}
				case 2:
				case 3: {
					ans += "6";
					break;
				}
				case 4:
				case 5: {
					ans += "7";
					break;
				}
				case 6:
				case 7: {
					ans += "8";
					break;
				}
				case 8:
				case 9: {
					ans += "9";
					break;
				}
			}
		}
	}
	
	return stoi(ans);
}

bool searchNum(int arr[], int n, int x){
	int low = 0, high = n-1;
	
	while(low <= high){
		int mid = divBy2(low+high);
		if(arr[mid] == x) return true;
		else if(arr[mid] > x) high = mid-1;
		else low = mid+1;
	}
	
	return false;
}

// main function
int main(){
	int arr[] = {2, 3, 4, 10, 40};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << searchNum(arr, n, 10) << "\n";
	cout << searchNum(arr, n, 3) << "\n";
	cout << searchNum(arr, n, 45) << "\n";
	
	return 0;
}