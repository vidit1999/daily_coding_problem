#include <bits/stdc++.h>
using namespace std;

/*
First, recall that any integer must be either even or odd, a quality known as its parity.
Now suppose we have three integers (a, b, c), representing the number of Quxes of each color.
For any given configuration there will be four cases:

(a) These numbers are all even
(b) These numbers are all odd
(c) Two are even, and one is odd
(d) Two are odd, and one is even

The cases fall into two groups: either the parity of all the integers will be the same (a and b),
or the parity will break down into two numbers on one side, and one on the other (c and d).

Now note that for any transformation, we reduce the count of two colors by one,
and increase the value of the other by one. For example, in the change (R, G) -> B,
we decrement the number of red and green Quxes and increment the number of blue ones.
Crucially, this does not change which of the two above groups the line falls into.
In other words, a Qux line will always be alternating between cases a and b, or between c and d, but never both.

What, then, is the best possible outcome for each group? For the first group,
this will be either (2, 0, 0), (0, 2, 0), or (0, 0, 2). That is, once we reach a point
where we have two Quxes of one color and none of any other color, no new transformations are possible.
And since it is impossible to remove all Quxes from the line, these are the equal-parity formations with the lowest sum.

Analogously, the best outcome for a split-parity group will be (1, 0, 0), (0, 1, 0), or (0, 0, 1).

With some care we can show that as long as our initial line does not consist of all Quxes of the same color,
we can continually apply transformations to get to one of these base cases.
As a result, our solution will simply be the following:

If all Quxes begin as the same color, return the length of the line.
If the parities of each color are equal, return 2.
If the parities of each color are split, return 1.

*/

int lowestQux(vector<char> quxes){
    int red=0,green=0,blue=0;
    for(char c : quxes){
        if(c == 'R')
            red++;
        else if(c == 'G')
            green++;
        else
            blue++;
    }
    if(red == quxes.size() || green == quxes.size() || blue == quxes.size())
        return quxes.size();
    if(red%2 == green%2 && red%2 == blue%2)
        return 2;
    return 1;
}

// main function
int main(){
    cout << lowestQux({'R', 'G', 'B', 'G', 'B'}) << "\n";
    cout << lowestQux({'B', 'B', 'B'}) << "\n";
    return 0;
}