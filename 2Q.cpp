#include<bits/stdc++.h>
#define MX 3005
using namespace std;

char nsp2[MX], other[MX], tmpstr[MX];
int dp[MX][MX], ln;

inline int max(int a, int b) { return a > b ? a : b; }

void getStr(int m, int n) {
	if (m == 0 || n == 0)  return;
	if (nsp2[m - 1] == other[n - 1]) {
		tmpstr[--ln] = nsp2[m - 1];
		getStr(m - 1, n - 1);
	}
	else {
		dp[m][n - 1] >= dp[m - 1][n] ? getStr(m, n - 1) : getStr(m - 1, n);
	}
	return;
}
int lcs(int m, int n)
{
	if (m == 0 || n == 0)  return 0;
	if (dp[m][n] != -1) return dp[m][n];
	int& res = dp[m][n];

	if (nsp2[m - 1] == other[n - 1]) {
		res = 1 + lcs(m - 1, n - 1);
	}
	else
		res = max(lcs(m, n - 1), lcs(m - 1, n));
	return res;
}



int main()
{
	int i, j, m, n, tmp;
	char name[MX];
	freopen("nsp2.txt", "r", stdin);
	//input nsp2
	scanf("%s\n", name);
	if (strcmp(name, ">nsp2") != 0) return 0;
	scanf("%s\n", tmpstr);
	tmp = strlen(tmpstr);
	for (i = 0, m = 0; i < tmp; i++) {
		if (tmpstr[i] >= 'a' && tmpstr[i] <= 'z') continue;
		nsp2[m++] = tmpstr[i];
	}
	nsp2[m] = 0;

	//A0A1B3Q5V8
	//input A0A1B3Q5V8
	scanf("%s\n", name);
	scanf("%s\n", tmpstr);
	tmp = strlen(tmpstr);
	for (i = 0, n = 0; i < tmp; i++) {
		if (tmpstr[i] >= 'a' && tmpstr[i] <= 'z') continue;
		other[n++] = tmpstr[i];
	}
	other[n] = 0;

	//init
	printf("nsp2: %s\n%s: %s\n", nsp2, &name[1], other);
	for (i = 0; i <= m; i++) for (j = 0; j <= n; j++) dp[i][j] = -1;

	//run
	ln = lcs(m, n);
	cout << "length: " << ln << endl;
	tmpstr[ln] = 0;
	getStr(m, n);
	//result
	printf("lcs: %s\n--------end-------\n", tmpstr);

	//Q9YMB7
	//input Q9YMB7
	scanf("%s\n", name);
	scanf("%s\n", tmpstr);
	tmp = strlen(tmpstr);
	for (i = 0, n = 0; i < tmp; i++) {
		if (tmpstr[i] >= 'a' && tmpstr[i] <= 'z') continue;
		other[n++] = tmpstr[i];
	}
	other[n] = 0;

	//init
	printf("nsp2: %s\n%s: %s\n", nsp2, &name[1], other);
	for (i = 0; i <= m; i++) for (j = 0; j <= n; j++) dp[i][j] = -1;

	//run
	ln = lcs(m, n);
	cout << "length: " << ln << endl;
	tmpstr[ln] = 0;
	getStr(m, n);
	//result
	printf("lcs: %s\n", tmpstr);
	return 0;
}

// This code is contributed by rathbhupendra 
