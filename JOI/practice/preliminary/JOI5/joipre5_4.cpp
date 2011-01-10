#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
int moveatoc(vector<int> A, vector<int> B, vector<int> C){
	int cnt = 0;
	while(!(A.empty() && B.empty())){
		printf("A: "); for(int i = 0; i < A.size(); i++) printf("%d ", A[i]); puts("");
		printf("B: "); for(int i = 0; i < B.size(); i++) printf("%d ", B[i]); puts("");
		printf("C: "); for(int i = 0; i < C.size(); i++) printf("%d ", C[i]); puts("\n");
		bool move = 0;
		if(B.size())
			if(B.back() > (C.size() ? C.back() : 0)){
				C.push_back(B.back());
				B.pop_back();
				cnt++;
				move = 1;
			}
		if(A.size())
			if(A.back() > (B.size() ? B.back() : 0)){
				B.push_back(A.back());
				A.pop_back();
				cnt++;
				move = 1;
			}
		if(!move){
			return INT_MAX; 
		}
	}
	return cnt;
}

int main()
{
	int n, m;
	while(scanf("%d %d\n", &n, &m), n || m){
		int l;
		scanf("%d\n", &l);vector<int> A(l);
		for(int i = 0; i < l; i++) scanf("%d", &A[i]);
		scanf("%d\n", &l);vector<int> B(l);
		for(int i = 0; i < l; i++) scanf("%d", &B[i]);
		scanf("%d\n", &l);vector<int> C(l);
		for(int i = 0; i < l; i++) scanf("%d", &C[i]);
		int minimum = INT_MAX;
		if(A.size()) minimum = min(minimum, moveatoc(A, B, C));
		if(C.size()) minimum = min(minimum, moveatoc(C, B, A));
		if(minimum == INT_MAX) minimum = -1;
		printf("%d\n", minimum);

	}
	return 0;
}
