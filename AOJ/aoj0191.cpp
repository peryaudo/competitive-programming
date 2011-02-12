#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	while(scanf("%d %d\n", &n, &m), n || m){
		long double g[n][n];
		/* dp[a][b]は、a回目にbの肥料を与えた時のaまでの成長率の最大値 */
		long double dp[m][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%Lf", &g[i][j]);
			}
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				dp[i][j] = 0;
			}
		}
		for(int i = 0; i < n; i++) dp[0][i] = 1;
		
		for(int i = 1; i < m; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					dp[i][j] = max(dp[i][j], dp[i - 1][k] * g[k][j]);
				}
			}
		}
		long double res = 0;
		for(int i = 0; i < n; i++){
			res = max(res, dp[m - 1][i]);
		}
		printf("%.2Lf\n", res);
	}
	
	return 0;
}
