// Wrong Answer
#include <string>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	int n;
	string s;
	cin>>n;
	getline(cin, s);
	getline(cin, s);
	vector<int> v;
	cout<<"s = "<<s.size()<<endl;
	while(!s.empty()){
		int pos = INT_MAX, t = 0;
		if((t = s.find('.')) != string::npos) pos = min(t, pos);
		if((t = s.find('?')) != string::npos) pos = min(t, pos);
		if((t = s.find('!')) != string::npos) pos = min(t, pos);
		//if(pos == INT_MAX){cout<<"this is bug\n"<<endl;}
		v.push_back(pos + 1);
		if(pos + 1 < s.size()){
			if(s[pos + 1] == ' ') pos++;
		}
		s = s.substr(pos + 1);
	}
	int cur = 0, res = 0;
	for(int i = 0; i < v.size(); i++){
		if(v[i] > n){
			cout<<"Impossible\n";
			return 0;
		}else if(cur + v[i] > n){
			res++;
			cur = v[i];
		}else{
			cur += v[i];
		}
	}
	cout<<res<<endl;
	return 0;
}
