#include <iostream>
#include <string>
using namespace std;
int main()
{
	string needle;
	cin>>needle;
	int N;
	cin>>N;
	int cnt = 0;
	for(int i = 0; i < N; i++){
		string haystack;
		cin>>haystack;
		string s = haystack + haystack + haystack;
		if(s.find(needle) != string::npos){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
