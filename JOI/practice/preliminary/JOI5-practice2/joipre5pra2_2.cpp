#include <iostream>
#include <sstream>
using namespace std;
inline int calc(int l, char c, int r){
	switch(c){
	case '+': return l + r;
	case '-': return l - r;
	case '*': return l * r;
	case '/': return l / r;
	}
}
int main()
{
	string s;
	int l = 0, r = 0;
	char c = 0;
	while(cin>>s){
		switch(s[0]){
		case '+':
		case '-':
		case '*':
		case '/':
			c = s[0];
			break;
		case '=':
			cout<<l<<endl;
		default:
			stringstream ss(s);
			if(!c){
				ss>>l;
			}else{
				ss>>r;
				l = calc(l, c, r);
				c = 0;
			}
			break;
		}

	}
	return 0;
}
