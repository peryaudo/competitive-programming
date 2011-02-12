#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;
vector<unsigned int> solve_amida(vector<unsigned int>& v, vector<pair<int, int> >& ab){
	map<int, vector<int> > ba;
	for(int i = 0; i < ab.size(); i++)
		ba[ab[i].second].push_back(ab[i].first);
	
	vector<unsigned int> w(v.size());
	for(int i = 0; i < v.size(); i++){
		int j = i;
		for(map<int, vector<int> >::iterator mit = ba.begin(); mit != ba.end(); mit++){
			for(vector<int>::iterator vit = (*mit).second.begin(); vit != (*mit).second.end(); vit++){
			}
		}
	}
	vector<unsigned int> x(v.size());
	for(int i = 0; i < w.size(); i++){
		x[i] = v[w[i]];
	}
	return x;
}

unsigned int least_seq(vector<unsigned int> v, int l){
	if(v.size() < l) return UINT_MAX;
	for(int i = 0; i < v.size(); i++){
		printf("%d ", v[i]);
	}
	puts("");

	unsigned int total = 0, least = UINT_MAX;
	for(int i = 0; i < l; i++) total += v[i];
	least = min(least, total);
	for(int i = 0; i < v.size() - l; i++){
		total -= v[i];
		total += v[i + l];
		least = min(least, total);
	}

	return least;
}
int main()
{
	int n, m, h, k;
	while(scanf("%d %d %d %d\n", &n, &m, &h, &k), n || m || h || k){
		vector<unsigned int> s(n);
		for(int i = 0; i < n; i++){
			scanf("%d\n", &s[i]);
		}
		vector<pair<int, int> > ab;
		for(int i = 0; i < m; i++){
			int a, b;
			scanf("%d %d\n", &a, &b);
			ab.push_back(make_pair(a - 1, b));
		}
		unsigned int least = least_seq(solve_amida(s, ab), k);
		for(int i = 0; i < m; i++){
			printf("stick num : %d :::", i);
			vector<pair<int, int> > ba = ab;
			ba.erase(ba.begin() + i);
			least = min(least, least_seq(solve_amida(s, ba), k));
		}
		printf("%d\n", least);
	}
	return 0;
}
