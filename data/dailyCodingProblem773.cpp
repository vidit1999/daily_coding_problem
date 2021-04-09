#include <bits/stdc++.h>
using namespace std;

/*
We can determine how "out of order" an array A is
by counting the number of inversions it has.
Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j.
That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has.
Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions.
The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3).
The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
*/

int merge(int arr[], int temp[], int left, int mid, int right){
    int inversion = 0, i = left, j = mid, k = left;

    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            inversion += (mid - i);
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid-1){
        temp[k++] = arr[i++];
    }

    while(j <= right){
        temp[k++] = arr[j++];
    }

    for(i=left; i<=right; i++){
        arr[i] = temp[i];
    };

    return inversion;
}

int mergeSort(int arr[], int temp[], int left, int right){
    int inversion = 0;

    if(right > left){
        int mid = (left + right)/2;
        inversion += mergeSort(arr, temp, left, mid);
        inversion += mergeSort(arr, temp, mid+1, right);
        inversion += merge(arr, temp, left, mid+1, right);
    }

    return inversion;
}

int countInrevsion(int arr[], int n){
    int temp[n];
    return mergeSort(arr, temp, 0, n-1);
}

// main function
int main(){
    int arr[] = {5, 4, 3, 2, 1};// {2, 4, 1, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countInrevsion(arr, n) << "\n";
    return 0;
}
