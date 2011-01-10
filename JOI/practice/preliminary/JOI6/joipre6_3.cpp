#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for(string::iterator it = s.begin(); it != s.end(); it++){
		char c = *it - 'D' + 'A';
		if(c < 'A') c = c - 'A' + 'Z' + 1;
		cout<<c;
	}
	cout<<endl;
	return 0;
}
