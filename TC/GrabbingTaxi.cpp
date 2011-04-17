#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
using namespace std;
class GrabbingTaxi {
public:

	int minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime){
		int minimum = INT_MAX;
		for(int i = 0; i < tXs.size(); i++){
			int t = 0;
			t += (abs(tXs[i]) + abs(tYs[i])) * walkTime;
			t += (abs(gX - tXs[i]) + abs(gY - tYs[i])) * taxiTime;
			minimum = min(minimum, t);
		}
		minimum = min(minimum, (abs(gX) + abs(gY)) * walkTime);
		return minimum;
	}
};
