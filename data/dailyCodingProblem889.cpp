#include <bits/stdc++.h>
using namespace std;

/*
Run-length encoding is a fast and simple method of encoding strings.
The basic idea is to represent repeated successive characters as a
single count and character. For example, the string "AAAABBBCCDAA"
would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string
to be encoded have no digits and consists solely of alphabetic characters.
You can assume the string to be decoded is valid.
*/

string runLengthEncoding(string s){
    string enc = "";

    int i=0;

    while(i < s.length()){
        int count = 1;

        while(i+1 < s.length() && s[i+1] == s[i] && count < 9){
            count++;
            i++;
        }

        enc += (to_string(count) + s[i]);

        i++;
    }

    return enc;
}

string runLengthDecoding(string enc){
    string dec = "";

    for(int i=0; i<enc.length(); i+=2){
        int count = enc[i] - '0';
        int c = enc[i+1];

        while(count--){
            dec += c;
        }
    }

    return dec;
}

// main function
int main(){
    string s = "AAAAAAAAAABBBBBBBBBBBBBCCDAA";
    string enc = runLengthEncoding(s);
    string dec = runLengthDecoding(enc);
    cout << s << "\n";
    cout << enc << "\n";
    cout << dec << "\n";
    return 0;
}
