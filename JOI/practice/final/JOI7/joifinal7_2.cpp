#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s, t;
	while(cin>>s>>t){
		int dst = 0;
		if(s.size() < t.size()) swap(s, t);

		for(int i = t.size() - 1; 0 < i; i--)
			for(int j = i, k = 0, f = 0; j < t.size(); j++, k++)
				if(t[j] == s[k]) dst = max(dst, ++f); else f = 0;
		
		for(int i = 0; i < s.size() - t.size(); i++)
			for(int j = 0, k = i, f = 0; j < t.size(); j++, k++)
				if(t[j] == s[k]) dst = max(dst, ++f); else f = 0;

		for(int i = t.size() - 1; 0 < i; i--)
			for(int j = 0, k = s.size() - i, f = 0; j < i; j++, k++)
				if(t[j] == s[k]) dst = max(dst, ++f); else f = 0;

		cout<<dst<<endl;
	}
	return 0;
}
