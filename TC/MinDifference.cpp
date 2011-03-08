#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class MinDifference {
public:
	int closestElements(int A0, int X, int Y, int M, int n) {
		vector<int> A(n);
		A[0] = A0;
		for(int i = 1; i < n; i++){
			A[i] = (A[i - 1] * X + Y) % M;
		}
		sort(A.begin(), A.end());
		int minimum = INT_MAX;
		for(int i = 0; i < n - 1; i++){
			minimum = min(minimum, A[i + 1] - A[i]);
		}
		return minimum;
	}

	

};
