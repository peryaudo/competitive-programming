#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class AdditionGame {
public:
	int getMaximumPoints(int A, int B, int C, int N) {
		priority_queue<int> pq;
		pq.push(A);
		pq.push(B);
		pq.push(C);
		int point = 0;
		for(int i = 0; i < N; i++){
			int cur = pq.top(); pq.pop();
			point += cur;
			pq.push(cur + (cur >= 1 ? -1 : 0));
		}
		return point;
	}

	

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
