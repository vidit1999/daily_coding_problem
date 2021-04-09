#include <bits/stdc++.h>
using namespace std;

/*
Implement a function that converts a hex string to base64.

For example, the string: deadbeef
should produce: 3q2+7w==
*/

unordered_map<char, string> hex_map = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'a', "1010"},
    {'b', "1011"},
    {'c', "1100"},
    {'d', "1101"},
    {'e', "1110"},
    {'f', "1111"}
};

string b64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


int bin2dec(string bin){
    int ans = 0;

    for(char c : bin){
        ans *= 2;
        ans += (c - '0');
    }

    return ans;
}

string base64Convert(string s){
    string ans = "";

    for(int i=0; i<s.length(); i += 6){
        string sub_6 = s.substr(i, 6);
        while(sub_6.length() < 6){
            sub_6 += "0";
        }
        ans += b64_chars[bin2dec(sub_6)];
    }

    return ans;
}

string hex2Base64(string hex){
    if(hex.length() % 2 != 0) return "";

    string bin_str = "", ans = "";

    for(char c : hex){
        bin_str += hex_map[c];
    }


    for(int i=0; i<bin_str.length(); i += 24){
        string part_b64 = base64Convert(bin_str.substr(i, 24));
        while(part_b64.length() < 4){
            part_b64 += "=";
        }
        ans += part_b64;
    }

    return ans;
}


// main function
int main(){
    cout << hex2Base64("deadbeef") << "\n";
    return 0;
}
