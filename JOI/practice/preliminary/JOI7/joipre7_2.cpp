#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	while(cin>>s){
		int icnt = 0, jcnt = 0;
		for(int i = 0; i < s.size(); i++){
			if(s.find("IOI", i) == i){
				icnt++;
			}else if(s.find("JOI", i) == i){
				jcnt++;
			}
		}
		cout<<jcnt<<endl<<icnt<<endl;
	}
	return 0;
}
