#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

inline int abs(int x){
	return x < 0 ? -x : x;
}
int main()
{
	int n, m;
	while(scanf("%d %d\n", &n, &m), n || m){
		vector<vector<int> > da(n);
		int width = 0;
		for(int i = 0; i < n; i++){
			int k;
			scanf("%d", &k);
			for(int j = 0; j < k; j++){
				int x, d;
				scanf("%d %d", &x, &d);

				if(x > da[i].size()){
					da[i].resize(x, 0);
				}
				width = max(width, x);
				x--;
				da[i][x] = d;
			}
		}
		for(int i = 0; i < n; i++)
			if(da[i].size() < width)
				da[i].resize(width, 0);

		int dp[n][width][m + 1];
		for(int i = 0; i < width; i++)
			for(int j = 0; j <= m; j++)
				dp[0][i][j] = 0;

		for(int i = 1; i < n; i++){
			for(int j = 0; j < da[i].size(); j++){
				if(!da[i][j]) continue;
				
				for(int k = 0; k <= m; k++){
					int dst = INT_MAX;
					for(int kd = 0; kd <= k; k++){
						if(i - kd - 1< 0) break;
						for(int l = 0; l < width; l++){
							printf("da[%d][%d]...", i - kd - 1, l);
							if(!da[i - kd - 1][l]){
								puts("");
								continue;
							}
							printf("ja...");
							
							dst = min(dst, (da[i][j] + da[i - kd - 1][l])
								* abs(l - j) + dp[i - kd - 1][l][k - kd]);
							printf("ja.\n");
						}
					}
					printf("dp[%d][%d][%d] = %d...", i, j, k, dst);
					dp[i][j][k] = dst;
					puts("ok.");
				}
			}
		}
	}

	return 0;
}
