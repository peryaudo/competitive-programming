#include <cstdio>
#include <vector>
#include<set>
using namespace std;
typedef pair<int, int> px;
int main()
{
	int m;
	while(scanf("%d\n", &m), m){
		vector<px> needle;
		set<px> haystack;
		for(int i = 0; i < m; i++){
			int x, y;
			scanf("%d %d\n", &x, &y);
			needle.push_back(make_pair(x, y));
		}
		int n;
		scanf("%d\n", &n);
		for(int i = 0; i < n; i++){
			int x, y;
			scanf("%d %d\n", &x, &y);
			haystack.insert(make_pair(x, y));
		}
		for(set<px>::iterator it = haystack.begin(); it != haystack.end(); it++){
			int ox = (*it).first - needle[0].first, oy = (*it).second - needle[0].second, match = 1;
			for(int i = 1; i < needle.size(); i++){
				if(haystack.find(make_pair(needle[i].first + ox, needle[i].second + oy)) == haystack.end()){
					match = 0;
					break;
				}
			}
			if(match){
				printf("%d %d\n", ox, oy);
				break;
			}
		}

	}
	return 0;
}
