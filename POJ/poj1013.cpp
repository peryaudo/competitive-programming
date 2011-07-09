// Wrong Answer
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

struct Balance {
	set<char> left, right;
	char status;
};

inline bool check(vector<Balance>& v, char c, char s)
{
	for (int i = 0; i < v.size(); ++i) {
		Balance& b = v[i];
		char sup;
		bool left = b.left.find(c) != b.left.end(),
		     right = b.right.find(c) != b.right.end();
		if (!left && !right) {
			sup = 'e';
		} else if (!left && right) {
			if(s == 'l')
				sup = 'u';
			else
				sup = 'd';
		} else if (left && !right) {
			if(s == 'h')
				sup = 'u';
			else
				sup = 'd';
		}
		if (sup != b.status)
			return false;
	}
	return true;
}

int main()
{
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		vector<Balance> v(3);
		for (int j = 0; j < 3; ++j) {
			/* s is status of the right side */
			char l[5], r[5], s[5];
			scanf("%4s %4s %4s\n", l, r, s);
			Balance& b = v[j];
			for (int k = 0; k < 4; ++k)
				b.left.insert(l[k]);
			for (int k = 0; k < 4; ++k)
				b.right.insert(r[k]);
			b.status = s[0];
		}
		for (char j = 'A'; j <= 'L'; ++j) {
			if (check(v, j, 'l')) {
				printf("%c is the counterfeit coin and it is light.\n", j);
				break;
			} else if (check(v, j , 'h')) {
				printf("%c is the counterfeit coin and it is heavy.\n", j);
				break;
			}
		}
	}
	return 0;
}
