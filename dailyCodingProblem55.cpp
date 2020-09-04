#include <bits/stdc++.h>
using namespace std;

const string ALL_CHARS  = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

/*
Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.

restore(short), which expands the shortened string into the original url.
If no such shortened string exists, return null.

Hint: What if we enter the same URL twice?
*/

string shorten(int url){
	string short_url;
	
	while(url){
		short_url = ALL_CHARS[url%62] + short_url;
		url /= 62;
	}
	
	return short_url;
}

int restore(string short_url){
	int id = 0;
	
	for(char c : short_url){
		id *= 62;
		
		if('a' <= c && c <= 'z')
			id += (c - 'a');
		else if('A' <= c && c <= 'Z')
			id += (c - 'A' + 26);
		else
			id += (c - '0' + 52);
	}
	
	return id;
}

// main function
int main(){
	srand(time(0));
	
	for(int i=0; i<20; i++){
		int url = rand();
		string tiny = shorten(url);
        int res = restore(tiny);
		cout << boolalpha << url << ", " << tiny << ", " << res
             << ", " << (url == res)  << "\n";
	}
	
	return 0;
}