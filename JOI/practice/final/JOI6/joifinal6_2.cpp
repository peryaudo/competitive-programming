#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > cnt_cont(vector<int>& v){
	vector<pair<int, int> > w;
	int len = 1, c = 0;
	for(int i = 0; i < v.size(); i++){
		if(c == v[i]){
			len++;
			c++;
		}else{
			if(c) w.push_back(make_pair(c - len, c - 1));
			c = v[i] + 1;
			len = 1;
		}
	}
	if(c) w.push_back(make_pair(c - len, c - 1));
	return w;
}

int main()
{
	int n, k;
	while(scanf("%d %d\n", &n, &k), n || k){
		vector<int> v;
		bool wh = false;
		for(int i = 0, t; i < k; i++){
			scanf("%d\n", &t);
			if(!t){
				wh = true;
			}else{
				v.push_back(t);
			}
		}
		sort(v.begin(), v.end());
		vector<pair<int, int> > w = cnt_cont(v);
		int longest = 0;

		for(int i = 0; i < w.size(); i++){
			int len = w[i].second - w[i].first + 1;
			if(wh) len += 1;

			if(i < w.size() - 1 && wh){
				if(w[i].second  + 2== w[i + 1].first){
					len += w[i + 1].second - w[i + 1].first + 1;
				}
			}
			longest = max(longest, len);
		}

		printf("%d\n", longest);
	}
	return 0;
}
