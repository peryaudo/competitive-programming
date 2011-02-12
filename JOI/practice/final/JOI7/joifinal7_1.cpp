#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n;
	while(scanf("%d\n", &n), n){
		vector<pair<int, int> > v(1);
		scanf("%d\n", &(v[0].first)); v[0].second = 1;
		for(int i = 1; i < n; i++){
			int t;
			scanf("%d\n", &t);
			if((i + 1) % 2){
				printf("ki ->");
				if(v.back().first == t){
					v.back().second++;
				}else{
					v.push_back(make_pair(t, 1));
					//printf("koko!\n");
				}
			}else{
				printf("goo->");
				if(v.back().first != t){
					v.back().first = t;
				}
				v.back().second++;
			}
			for(int j = 0; j < v.size(); j++){
				for(int k = 0; k < v[j].second; k++){
					printf("%c", v[j].first ? '*' : 'o');
				}
			}
			puts("");
		}
		int white = 0;
		for(int i = 0; i < v.size(); i++){
			printf("%d color's %d\n", v[i].first, v[i].second);
			if(v[i].first == 0){
				white += v[i].second;
			}
		}
		printf("%d\n", white);
	}
	return 0;
}
