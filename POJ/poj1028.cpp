#include <stack>
#include <string>
#include <iostream>
using namespace std;
int main(){
	string s, c ("http://www.acm.org/");
	stack<string> f,b;

	while(1){
		cin>>s;
		if(s == "QUIT") break;
		if(s == "BACK"){
			if(b.empty()){
				cout<<"Ignored\n";
				continue;
			}
			f.push(c);
			c = b.top();
			b.pop();
		}else if(s == "FORWARD"){
			if(f.empty()){
				cout<<"Ignored\n";
				continue;
			}
			b.push(c);
			c = f.top();
			f.pop();
		}else if(s == "VISIT"){
			b.push(c);
			while(!f.empty()) f.pop();
			cin>>c;
		}
		cout<<c<<endl;
	}
	return 0;
}
