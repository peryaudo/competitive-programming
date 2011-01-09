#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
inline void maketable(map<char, string>& enc, map<string, char>& dec){
	const char *abc[] = {
		".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
		".-..","--","-.","---", ".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	for(int i = 0; i < 26; i++){
		enc[i + 'A'] = abc[i];
	}
	enc['_'] = string("..--");
	enc['.'] = string("---.");
	enc[','] = string(".-.-");
	enc['?'] = string("----");
	for(map<char, string>::iterator it = enc.begin(); it != enc.end(); it++)
		dec[(*it).second] = (*it).first;
	return;
}

pair<string, string> encode(string s, map<char, string>& enc){
	string a, b;
	for(int i = 0; i < s.size(); i++){
		a += enc[s[i]];
		b += enc[s[i]].size() + '0';
	}
	return pair<string, string>(a, b);
}

string decode(pair<string, string> p, map<string, char>& dec){
	string dst;
	for(int i = 0, j = 0; i < p.second.size(); i++){
		int curlen = p.second[i] - '0';
		dst += dec[p.first.substr(j, curlen)];
		j += curlen;
	}
	return dst;
}

int main()
{
	map<char, string> enc;map<string, char> dec;
	maketable(enc, dec);
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		string s;
		cin>>s;
		pair<string, string> p =  encode(s, enc);
		reverse(p.second.begin(), p.second.end());
		cout<<i + 1<<": "<<decode(p, dec)<<endl;
	}
	
	return 0;
}