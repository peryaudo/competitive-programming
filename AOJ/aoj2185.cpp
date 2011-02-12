#include <cstdio>

int main()
{
	int n;
	scanf("%d\n", &n);
	for(int _i = 0; _i < n; _i++){
		int X, Y, W, H;
		scanf("%d %d %d %d\n", &X, &Y, &W, &H);
		int N;
		scanf("%d\n", &N);
		int cnt = 0;
		for(int i = 0; i < N; i++){
			int x, y;
			scanf("%d %d\n", &x, &y);
			if(X <= x && x <= (X + W) && Y <= y && y <= (Y + H))
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
