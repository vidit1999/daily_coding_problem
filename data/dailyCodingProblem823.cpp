#include <bits/stdc++.h>
using namespace std;

/*
Implement a bit array.

A bit array is a space efficient array that holds a value of 1 or 0 at each index.

init(size): initialize the array with size
set(i, val): updates index at i with val where val is either 1 or 0.
get(i): gets the value at index i.
*/

class BitArray{
    int sz;
    unsigned long number;

    public:
    void init(int size);
    void set(int i, int val);
    int get(int i);
};

void BitArray::init(int size){
    sz = max(min(size, 0), 63);
    number = 0;
}

void BitArray::set(int i, int val){
    if(i >= 0 && i < sz){
        if(val == 1)
            number |= (1l << i);
        else
            number &= ~(1l << i);
    }
}

int BitArray::get(int i){
    if(i >= 0 && i < sz)
        return bool(number & (1l << i));
    return -1;
}

// main function
int main(){
    BitArray b;
    b.init(30);

    for(int i=0;i<10;i++)
        cout << b.get(i) << " ";
    cout << "\n";

    for(int i=0;i<10;i++)
        b.set(i,(i%3 == 0));

    for(int i=0;i<10;i++)
        cout << b.get(i) << " ";
    cout << "\n";

    for(int i=0;i<5;i++)
        b.set(i,!(i%3 == 0));

    for(int i=0;i<10;i++)
        cout << b.get(i) << " ";
    cout << "\n";

    return 0;
}
