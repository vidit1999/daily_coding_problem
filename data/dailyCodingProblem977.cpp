#include <bits/stdc++.h>
using namespace std;

#define MAX_URL_SIZE 6

/*
Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string,
such as zLg6wl.

restore(short), which expands the shortened string into the original url.
If no such shortened string exists, return null.

Hint: What if we enter the same URL twice?
*/

class Shortener{
    unordered_map<string, int> short_urls_to_url;
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";

    void padZeroBack(string& s, int num_zero);

    public:
    string shorten(int url);
    int restore(string shurl);
};

void Shortener::padZeroBack(string& s, int num_zero){
    int to_add = max(0, int(num_zero-s.length()));

    while(to_add--){
        s += '0';
    }
}

string Shortener::shorten(int url){
    string shurl = "";
    int original_url = url;

    while(url){
        shurl += chars[url%61];
        url /= 61;
    }

    padZeroBack(shurl, MAX_URL_SIZE);
    short_urls_to_url[shurl] = original_url;

    return shurl;
}

int Shortener::restore(string shurl){
    if(short_urls_to_url.find(shurl) == short_urls_to_url.end()){
        return -1;
    }

    return short_urls_to_url[shurl];
}

// main function
int main(){
    srand(time(0));

    Shortener sht;

    for(int i=0; i<10; i++){
        int url = rand();
        string sh = sht.shorten(url);
        int ori = sht.restore(sh);

        cout << url << " --> " << sh << " --> " << ori << "\n"; 
    }


    cout << sht.restore("zLg6wl") << "\n";

    return 0;
}