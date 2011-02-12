#include <iostream>
#include <string>
using namespace std;

inline bool hit(string& src){
	if(src.find("that") != string::npos) return true;
	if(src.find("this") != string::npos) return true;
	if(src.find("the") != string::npos) return true;
	return false;
}
inline bool ignore(char c){
	if(c == ' ') return true;
	if(c == '.') return true;
	if(c == '\n') return true;
	return false;
}
string caesar(string& src, int offset){
	string dst = src;
	for(int i = 0; i < dst.size(); i++){
		if(ignore(dst[i])) continue;
		dst[i] = ((dst[i] - 'a') + offset) % 26 + 'a';
	}
	return dst;
}

int main()
{
	string s;
	while(getline(cin, s)){
		for(int i = 1; i < 26; i++){
			string t = caesar(s, i);
			if(hit(t)){
				cout<<t<<endl;
				break;
			}
		}
	}
	return 0;
}
