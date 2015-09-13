#include <bits/stdc++.h>
using namespace std;

int n, c;
int p[200002];
int dp[200002][2];
bool v[200002][2];

int f(int i, int taken) {
	if (v[i][taken]) {
		return dp[i][taken];
	}
	v[i][taken] = true;
	if (taken) {
		dp[i][1] = max(f(i - 1, 1), f(i - 1, 0) - p[i - 1] - c);
	} else {
		dp[i][0] = max(f(i - 1, 0), f(i - 1, 1) + p[i - 1]);
	}
	return dp[i][taken];
}

int main() {
	int i, j;
	while (scanf("%d%d", &n, &c) != EOF) {
		for (i = 0; i < 2; i++) {
			for (j = 0; j <= n + 1; j++) {
				v[j][i] = false;
			}
		}
		v[1][0] = v[1][1] = true;
		dp[1][0] = 0;
		dp[1][1] = -(1 << 30);
		for (i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
		}
		printf("%d\n", max(f(n + 1, 0), f(n + 1, 1)));
	}
	return 0;
}
