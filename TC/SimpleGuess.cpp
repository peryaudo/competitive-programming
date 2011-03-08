// System Test Passed
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SimpleGuess {
public:
	int getMaximum(vector <int> hints) {
		sort(hints.begin(), hints.end());
		int maximum = 0;
		for(int i = 0; i < hints.size(); i++){
			for(int j = i + 1; j < hints.size(); j++){
				if(!((hints[i] + hints[j]) % 2) && !((hints[j] - hints[j]) % 2)){
					int X = (hints[i] + hints[j]) / 2, Y = (hints[j] - hints[i]) / 2;
					maximum = max(maximum, X * Y);
				}
			}
		}
		return maximum;
	}
};
