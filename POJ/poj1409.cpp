#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n;
	const char *tbl[] = {"", "", "abc", "def", "ghi", "jkl",
	       	"mno", "pqrs", "tuv", "wxyz"};
	while(cin>>n, n){
		set<string> word;
		for(int i = 0; i < n; i++){
			string s;
			cin>>s;
			word.insert(s);
		}

		string res;
		string in;
		cin>>in;
		char c = 0; int cnt = 0;
		for(int i = 0; i < in.size(); i++){
			if(c == in[i]){
				cnt++;
			}else{
				cout<<"c = "<<(int)c<<endl;
				if(c) res += tbl[c - '0'][cnt];
				cout<<"["<<c - '0'<<"]["<<cnt<<"] = "<<tbl[c - '0'][cnt]<<endl;
				c = in[i];
				cnt = 0;
			}
		}
		res += tbl[c - '0'][cnt];


		cout<<res<<endl;
		cout<<"--"<<endl;
	}
	cout<<"--"<<endl;
	return 0;
}
