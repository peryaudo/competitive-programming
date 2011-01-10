#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	while(scanf("%d %d\n", &n, &m), n || m){
		map<int, int> ma;
		for(int i = 0; i < n; i++){
			for(int j = 0, x; j < m; j++){
				scanf("%d", &x);
				ma[j + 1] += x;
			}
		}
		map<int, set<int> > mi;
		for(map<int, int>::iterator it = ma.begin(); it != ma.end(); it++){
			mi[(*it).second].insert((*it).first);
		}
		vector<int> v;
		for(map<int, set<int> >::reverse_iterator rit = mi.rbegin(); rit != mi.rend(); rit++){
			for(set<int>::iterator it = (*rit).second.begin(); it != (*rit).second.end(); it++){
				v.push_back(*it);
			}
		}
		for(int i = 0; i < v.size() - 1; i++){
			printf("%d ", v[i]);
		}
		printf("%d\n", v[v.size() - 1]);
	}

	return 0;
}
