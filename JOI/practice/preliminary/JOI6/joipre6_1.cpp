#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int A = 0, B = 0;
	for(int i = 0, t; i < 4; i++)
		scanf("%d\n", &t), A += t;
	for(int i = 0, t; i < 4; i++)
		scanf("%d\n", &t), B += t;
	printf("%d\n", max(A, B));

}
