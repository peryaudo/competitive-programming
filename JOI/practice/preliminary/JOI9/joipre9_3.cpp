#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int main()
{
	int n, m;
	while(scanf("%d\n%d\n", &n, &m), n || m){
		vector<vector<int> > v(n);
		set<int> se;
		for(int i = 0; i < m; i++){
			int a, b;
			scanf("%d %d\n", &a, &b);
			a--;b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i = 0; i < v[0].size(); i++){
			se.insert(v[0][i]);
			for(int j = 0; j < v[v[0][i]].size(); j++){
				se.insert(v[v[0][i]][j]);
			}
		}
		se.erase(0);
		printf("%d\n", se.size());
	}
	return 0;
}
