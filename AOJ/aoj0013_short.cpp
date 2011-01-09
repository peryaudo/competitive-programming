#include <cstdio>
#include <vector>
int main(){std::vector<int> v;for(int n;scanf("%d\n", &n)+1;)if(n)v.push_back(n);else printf("%d\n", v.back()),v.pop_back();return 0;}
