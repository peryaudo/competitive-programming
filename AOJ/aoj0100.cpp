#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	long long n;
	while(scanf("%Ld\n", &n), n){
		vector<pair<long long, long long> > v;
		for(long long i = 0; i < n; i++){
			long long p, q, r, f = 1;
			scanf("%Ld %Ld %Ld\n", &p, &q, &r);
			for(long long j = 0; j < v.size(); j++){
				if(v[j].first == p){
					f = 0;
					v[j].second += q * r;
				}
			}
			if(f){
				pair<long long, long long> pa(p, q * r);
				v.push_back(pa);
			}
			
		}
		long long g = 1;
		for(long long i = 0; i < v.size(); i++){
			if(1000000 <= v[i].second){
				g = 0;
				printf("%Ld\n", v[i].first);
			}
		}
		if(g) puts("NA");
	}
	return 0;
}
