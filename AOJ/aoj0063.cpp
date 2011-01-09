#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s, t;
	int cnt = 0;
	while(cin>>s){
		t = s;
		reverse(t.begin(), t.end());
		cnt += s == t;
	}
	cout<<cnt<<endl;
	return 0;
}
