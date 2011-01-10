#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int R, C;
	while(scanf("%d %d\n", &R, &C), R || C){
		vector<vector<int> > v(R, vector<int>(C));
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				scanf("%d", &v[i][j]);
		int dst = 0;
		for(int i = 0; i < (1 << R); i++){
			vector<vector<int> > w = v;
			for(int j = 0; j < R; j++)
				if(i & (1 << j))
					for(int k = 0; k < C; k++)
						w[j][k] = !w[j][k];

			for(int k = 0; k < C; k++){
				int rtotal = 0;
				for(int j = 0; j < R; j++) rtotal += w[j][k];
				if(rtotal < (R / 2))
					for(int j = 0; j < R; j++) w[j][k] = !w[j][k];
			}
			int total = 0;
			for(int j = 0; j < R; j++)
				for(int k = 0; k < C; k++)
					total += w[j][k];
			dst = max(dst, total);
		}
		printf("%d\n", dst);

	}
	return 0;
}
