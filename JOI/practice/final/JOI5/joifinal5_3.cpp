#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > *lists;

int listup(int n, vector<int> v){
	for(int i = 1; i <= n; i++){
		int f = 0;
		for(int j = 0; j < v.size(); j++){
			if(v[j] > i){
				f = 1;
				break;
			}
		}
		if(f) continue;
		vector<int> w = v;
		w.push_back(i);
		if(n - i > 0){
			listup(n - i, w);
		}else{
			lists->push_back(w);
		}
	}
}
int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		vector<vector<int> > v;
		lists = &v;
		listup(n, vector<int>());
		for(int i = 0; i < v.size(); i++){
			reverse(v[i].begin(), v[i].end());
		}
		sort(v.begin(), v.end());
		for(int i = v.size() - 1; 0 <= i; i--){
			for(int j = 0; j < v[i].size(); j++){
				printf("%d%c", v[i][j], j != v[i].size() - 1 ? ' ' : '\n');
			}
		}
	}
	return 0;
}
