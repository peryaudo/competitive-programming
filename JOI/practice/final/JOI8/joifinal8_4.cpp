#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int H, W, N;
	while(scanf("%d %d %d\n", &H, &W, &N), H || W || N){
		vector<vector<int> >  v(H, vector<int>(W)),
			dp(H + 1, vector<int>(W + 1, 0));
		for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++)
				scanf("%d", &v[i][j]);

		dp[0][0] = N - 1;
		for(int i = 1; i <= H; i++){
			for(int j = 1; j <= W; j++){
				for(int _k = 0, k; _k < 2; _k++,
					k = dp[i - (_k ? 1 : 0)][j - (_k ? 0 : 1)]){
					if(k % 2){
						if(v[i - (_k ? 2 : 1)][j - (_k ? 1 : 2)] ^ k){
							dp[i][j] += (k - 1) / 2;
						}else{
							dp[i][j] += (k + 1) / 2;
						}
					}else{
						dp[i][j] += k / 2;
					}
				}
			}
		}
		for(int i = 1; i <= H; i++)
			for(int j = 1; j <= W; j++)
				if(dp[i][j] % 2) v[i - 1][j - 1] = !v[i - 1][j - 1];

		int cx = 0, cy = 0;
		while(cx != H - 1 && cy != W - 1){
			if(v[cx][cy]){
				cx++;
			}else{
				cy++;
			}
		}
		printf("%d %d\n", cx + 1, cy + 1);

	}
	return 0;
}
