#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class strange_greater {
public:
	bool operator () (const pair<string, int>& p, const pair<string, int>& q) const {
		const string s = p.first, t = q.first;
		if(s.size() < t.size()){
			return true;
		}else if(s.size() > t.size()){
			return false;
		}else{
			return s < t;
		}
	}
};

int main()
{
	int n;
	scanf("%d\n", &n);
	map<string, int> m;
	for(int i = 0; i < n; i++){
		char c[6];
		int l;
		scanf("%s %d\n", c, &l);
		string s(c);
		m[s] += l;
	}
	vector<pair<string, int> > v;
	strange_greater sg;
	for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
		v.push_back(make_pair((*it).first, (*it).second));
	sort(v.begin(), v.end(), sg);
	for(int i = 0; i < v.size(); i++)
		printf("%s %d\n", v[i].first.c_str(), v[i].second);
	return 0;
}
