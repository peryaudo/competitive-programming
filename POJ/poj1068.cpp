#include <cstdio>
#include <string>
using namespace std;
int main()
{
	int t;
	scanf("%d\n", &t);
	for(int i = 0; i < t; i++){
		int n;
		scanf("%d\n", &n);
		string s;
		for(int j = 0,lm = 0, m; j < n; j++){
			scanf("%d", &m);
			s += string(m - lm, '(') + ')';
			lm = m;
		}
		for(int j = 0, fst = 1; j < s.size(); j++){
			if(s[j] == ')'){
				int cnt = 0;
				for(int k = j, nest = 0; 0 <= k; k--){
					if(s[k] == ')'){
						cnt++;
						nest++;
					}else if(s[k] == '('){
						nest--;
						if(nest == 0){
							break;
						}
					}
				}
				printf("%s%d", fst ? "" : " ", cnt);
				fst = 0;
			}
		}
		printf("\n");
	}
	return 0;
}