#include <cstdio>
#include <vector>
using namespace std;
inline int ab(int x){
	return x < 0 ? -x : x;
}
int main()
{
	const int MOD = 100000;

	int n, m;
	scanf("%d %d\n", &n, &m);

	vector<int> s(n - 1);
	for(int i = 0; i < n - 1; i++)
		scanf("%d\n", &s[i]);

	vector<int> a(m);
	for(int i = 0; i < m; i++)
		scanf("%d\n", &a[i]);

	vector<int> ad(m);
	ad[0] = a[0];
	for(int i = 1; i < m; i++)
		ad[i] = ad[i - 1] + a[i];
	
	int res = 0;
	int p = 0;
	for(int i = 0; i < m; i++){
		int pn = p + a[i];
		if(pn > p){
			res += ad[pn] - ad[p];
		}else{
			res += ad[p] - ad[pn];
		}
		p = pn;
	}
	printf("%d\n", res);

	return 0;
}
