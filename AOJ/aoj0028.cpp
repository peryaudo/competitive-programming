#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	map <int, int> m;
	map <int, vector<int> > l;
	int n;
	while(~scanf("%d\n", &n)) m[n]++;
	for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		l[(*it).second].push_back((*it).first);
	sort((*l.rbegin()).second.begin(), (*l.rbegin()).second.end());
	for(int i = 0; i < (*l.rbegin()).second.size(); i++)
		printf("%d\n", (*l.rbegin()).second[i]);
	return 0;
}
