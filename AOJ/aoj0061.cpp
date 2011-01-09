#include <map>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	int n, m;
	map<int, vector<int> > l;
	vector<vector<int> > v;
	while(~scanf("%d,%d\n", &n, &m)){
		if(!n && !m) break;
		l[m].push_back(n);
	}

	for(map<int, vector<int> >::reverse_iterator rit = l.rbegin(); rit != l.rend(); rit++)
		v.push_back((*rit).second);

	while(~scanf("%d\n", &n))
		for(int i = 0; i < v.size(); i++)
			for(int j = 0; j < v[i].size(); j++)
				if(v[i][j] == n){
					printf("%d\n", i + 1);
					break;
				}
	
	return 0;
}
