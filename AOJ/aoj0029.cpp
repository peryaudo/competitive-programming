#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	string s, max("");
	map<string, int> w;
	map<int, string> x;

	while(cin>>s){
		if(s.size() > max.size()) max = s;
		w[s]++;
	}

	for(map<string, int>::iterator it = w.begin(); it != w.end(); it++)
		x[(*it).second] = (*it).first;

	cout<<(*x.rbegin()).second<<" "<<max<<endl;
	return 0;
}
