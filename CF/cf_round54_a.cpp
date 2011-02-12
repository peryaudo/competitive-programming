#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s, t("hello");
	cin>>s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(cnt >= t.size()) break;
		if(s[i] == t[cnt]){
			cnt++;
		}
	}
	cout<<(cnt >= t.size() ? "YES" : "NO")<<endl;
	
	return 0;
}
