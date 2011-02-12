// Wrong Answer
#include <cstdio>
#include <vector>
using namespace std;
inline bool valid(int x, int y, int w, int h){
	return 0 <= x && x < w && 0 <= y && y < h;
}

int main()
{
	int w, h;
	while(scanf("%d %d\n", &w, &h), w || h){
		const int tbl[2][2] = {{1, 0}, {0, 1}};
		/* width, height, vector */
		int dp[w][h][3];
		for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++)
		for(int k = 0; k < 3; k++)
			dp[i][j][k] = 0;

		for(int i = 0; i < w; i++)
		for(int j = 0; j < 3; j++)
				dp[i][h - 1][j] = 1;

		for(int i = 0; i < h; i++)
		for(int j = 0; j < 3; j++)
				dp[w - 1][i][j] = 1;

		for(int i = h - 2; 0 <= i; i--){
			for(int j = w - 2; 0 <= j; j--){
				for(int k = 0; k < 3; k++){
					dp[j][i][k] = 0;
					if(k){
						const int nx = j + tbl[k - 1][0], ny = i + tbl[k - 1][1];
						if(!valid(nx, ny, w, h)) continue;
						dp[j][i][k] += dp[nx][ny][0];
					}else{
						for(int l = 0; l < 2; l++){
							const int nx = j + tbl[l][0], ny = i + tbl[l][1];
							if(!valid(nx, ny, w, h)) continue;
							dp[j][i][k] += dp[nx][ny][l + 1];
						}
					}
					//dp[j][i][k] %= 100000;
				}
			}
		}
		const int res = dp[1][0][0] + dp[0][1][0];

		printf("%d\n", res);

	}
	return 0;
}
