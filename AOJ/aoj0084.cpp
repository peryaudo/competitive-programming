#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> v,w;
	string s("");
	char c;
	while(c = getchar(), ~c){
		switch(c){
			case ' ':
			case ',':
			case '.':
				if(s != "") v.push_back(s);
				s = c;
				v.push_back(s);
				s = "";
				break;
			default:
				s += c;
				break;
		}
	}
	if(s != "") v.push_back(s);
	for(int i = 0, l, t; t = i < v.size(), l = v[t?i:0].size(), t; i++)
		if(3 <= l && l <= 6) w.push_back(v[i]);
	for(int i = 0; i < w.size(); i++)
		printf("%s%c", w[i].c_str(), (i != w.size() - 1)?' ':'\n');
	return 0;
}
