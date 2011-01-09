#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin>>N;
	string s;
	for(int i = 0; i < N; i++){
		char c;
		cin>>c;s += c;
	}

	string t, u;
	while(!s.empty()){
		u = s;
		reverse(u.begin(), u.end());
		if(u > s){
			t += s[0];
			s = s.substr(1);
		}else{
			t += s[s.size() - 1];
			s = s.substr(0, s.size() - 1);
		}
	}
	cout<<t.substr(0, 80)<<endl;
	while(80 <= t.size()){
		t = t.substr(80);
		cout<<t.substr(0, 80)<<endl;
	}
	return 0;
}