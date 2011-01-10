#include <iostream>
#include <string>
#include <sstream>
using namespace std;
inline string func(string s){
	ostringstream ss;
	char a = 0;
	int r = 1;
	for(string::iterator it = s.begin(); it != s.end(); it++){
		if(a != *it){
			if(a) ss<<r<<(char)a;
			a = *it;
			r = 1;
		}else{
			r++;
		}
	}
	if(a) ss<<r<<(char)a;
	return ss.str();
}

int main()
{
	int n;
	while(cin>>n, n){
		string s;
		cin>>s;
		for(int i = 0; i < n; i++){
			s = func(s);
		}
		cout<<s<<endl;
	}
	return 0;
}
