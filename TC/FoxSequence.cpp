#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define NO string("NO")
#define YES string("YES")

class FoxSequence {
public:
	string isValid(vector <int> seq) {
		if(seq.size() < 5) return NO;
		int p = 0;
		//1 2 1 2 1
		// increase
		int m = seq[p + 1] - seq[p];
		if (m <= 0) return NO;
		for(p++; p < seq.size() - 1; ){
			int md = seq[p + 1] - seq[p];
			if(md != m){
				if(md > 0) return NO;
				break;
			}
			p++;
		}
		if(seq.size() - p < 4) return NO;

		// decrease
		m = seq[p + 1] - seq[p];
		if(m >= 0) return NO;
		for(p++; p < seq.size() - 1; ){
			int md = seq[p + 1] - seq[p];
			if(md != m) break;
			p++;
		}
		if(seq.size() - p < 3) return NO;

		// equal
		if((m = seq[p + 1] - seq[p]) == 0){
			for(p++; p < seq.size() - 1; ){
				int md = seq[p + 1] - seq[p];
				if(md != m){
					break;
				}
				p++;
			}
		}

		if(seq.size() - p < 2) return NO;

		// increase
		m = seq[p + 1] - seq[p];
		if (m <= 0) return NO;
		for(p++; p < seq.size() - 1; ){
			int md = seq[p + 1] - seq[p];
			if(md != m){
				if(md > 0) return NO;
				break;
			}
			p++;
		}

		if(seq.size() - p - 1 < 1) return NO;

		// decrease
		m = seq[p + 1] - seq[p];
		if (m >= 0) return NO;
		for(p++; p < seq.size() - 1; ){
			int md = seq[p + 1] - seq[p];
			if(md != m) return NO;
			p++;
		}

		return YES;
	}

	

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
