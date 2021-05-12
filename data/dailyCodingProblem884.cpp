#include <bits/stdc++.h>
using namespace std;

/*
Using a function rand7() that returns an integer from 1 to 7(inclusive)
with uniform probability, implement a function rand5() that returns an
integer from 1 to 5 (inclusive).
*/

int rand7(){
    return 1 + rand()%7;
}

int rand5(){
    int num = -1;

    do{
        num = rand7();
    }while(num > 5);

    return num;
}

 // main function
int main(){
    srand(time(0));

    unordered_map<int, int> umap;

    for(int i=0; i<100000; i++){
        umap[rand5()]++;
    }

    for(auto it : umap){
        cout << it.first << " -> " << it.second << "\n";
    }
    return 0;
}
