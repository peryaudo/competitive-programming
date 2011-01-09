#include <cstdio>
#include <cstring>

int main(){
	const char *haabmonths[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac",
		"ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
	char haabmon[7];
	int haabday, haabyear;
	const char *tzolkinnames[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
		"chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"}, *tzolkinname;
	int tzolkinday, tzolkinyear;

	int n, i, j, unique;
	scanf("%d\n", &n);
	printf("%d\n", n);

	for(i = 0; i < n; i++, unique = 0){
		scanf("%d. %6s %d\n", &haabday, haabmon, &haabyear);
		unique += haabyear * 365;
		unique += haabday;
		for(j = 0; j < 20; j++)
			if(!strcmp(haabmonths[j], haabmon)) break;
		unique += 20 * j;
		tzolkinyear = unique / 260;
		unique = unique % 260;
		tzolkinday = unique % 13 + 1;
		tzolkinname = tzolkinnames[unique % 20];
		printf("%d %s %d\n", tzolkinday, tzolkinname, tzolkinyear);
	}
	return 0;
}
