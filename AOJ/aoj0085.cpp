#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	while(scanf("%d %d\n", &n, &m), n && m){
		vector<int> v;
		for(int i = 1; i <= n; i++) v.push_back(i); 
		vector<int>::iterator it = v.begin();
		while(1 < v.size()){
			for(int i = 1; it = it == v.end() ? v.begin() : it, i < m; i++)
				it++;
			it = v.erase(it);
		}
		printf("%d\n", v[0]);
	}
	return 0;
}
